#ifndef INITS_H
#define INITS_H

#include "Braco.h" //Inclui o arquivo onde a classe do Braco é definida (IMPORTANTE!) ver definicições em Braco.h

//tamanho da tela
const int W = 800;
const int H = 800;

Braco braco; //Objeto para desenhar o braco
Light luz; //Objeto para desenhar a luz
Floor chao; //Objeto para desenhar o chão
Vector3D cameraVector;
Vector3D moveVector;
vector<DesenhaFormas*> formas; //vetor de formas
double nowrad = 1;
double radius = 4;
int pega_objeto; //Verifica qual obejto a pinça pegou;
bool pegou_objeto; //Verifica se a pinça pegou algum objeto, setado em void handleKeyPress(unsigned char c, int x, int y) linha 96

void  Inits(){

    glClearColor(0, 0, 0, 0); //Fundo Preto
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING); //Possibilita usar iluminação
    glEnable(GL_NORMALIZE);
}

void reshape(int W, int H){
    glViewport (0, 0, (GLsizei) W, (GLsizei) H);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,W/H,1,500);

    gluLookAt(cameraVector.x(), cameraVector.y() , cameraVector.z(), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void redraw() {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    luz.updateLight();

    chao.draw();
    braco.draw();
    forinc(i, 0, formas.size()-1)
    formas[i]->draw();

    glPopMatrix();
    glutSwapBuffers();
}

/*a translacao dos cilindros é feita somada com a da transformacao para ajustar a movimentacao,
as funções reshape e redraw auxiliam nessa translação, atualizam tela, desenho, luz, etc;*/
void updateDisplay(){
    reshape(W,H);
    redraw();
}

/*O chão, a luz, a camera e as formas que ficam no chão são desenhadas aqui, cada forma é tem uma classe associada,
e para fazer o desenho são criados seus objetos, as cores para cada forma estao definidas no arquivo "Utils.h" assim como outras funções
de desenhar formas, vetores, matrizes, calculos e todas as bibliotecas necessárias (cmath, algorithm, vector, etc)*/
void Formas3D(){
    chao = Floor(10, 10, 1, WhiteColor);

    cameraVector = Vector3D(cos(nowrad) * radius, 3, sin(nowrad) * radius);

    //Desenho das formas: cubo e esfera, recebem dimenções e cores para serem desenhadas
    Cube * cube1 = new Cube(0.3, 0.3, 0.3, GreenColor);
    cube1->translate(0, 0.15, 1.6);
    Cube * cube2 = new Cube(0.3, 0.3, 0.3, YellowColor);
    cube2->translate(0, 0.15, -1.6);
    Sphere * sphere1 = new Sphere(0.3, 10, 10, BlueColor);
    sphere1->translate(1.5, 0.4, 0);
    Sphere * sphere2 = new Sphere(0.3, 10, 10, RedColor);
    sphere2->translate(-1.5, 0.4, 0);
    formas.push_back(cube1);
    formas.push_back(cube2);
    formas.push_back(sphere1);
    formas.push_back(sphere2);

    Vector4D ambient = Vector4D(0.2, 0.2, 0.2, 1.0);
    Vector4D diffuse = Vector4D(0.6, 0.6, 0.6, 1.0 );
    Vector4D specular = Vector4D(0.9, 0.9, 0.9, 1.0 );

    //Define a luz do ambiente
    luz = Light(Material(ambient,diffuse,specular,0.0), Vector3D(0,0,1));
    luz.enabled = true; //Seta a iluminação em true
}

//Define as teclas pra movimentação do braco e detecta as colisões com as formas do chão;
void handleKeyPress(unsigned char c, int x, int y){
    if (c == 'a')
        braco.rotate(0, 0, AngleToRadian(5));
    else if (c == 's')
        braco.rotate(0, 0, AngleToRadian(-5));
    else if (c == 'd')
        braco.part1.rotate(0,AngleToRadian(5), 0);
    else if (c == 'f')
        braco.part1.rotate(0,AngleToRadian(-5), 0);
    else if (c == 'q')
        braco.part1.part2.rotate(0,AngleToRadian(5), 0);
    else if (c == 'w')
        braco.part1.part2.rotate(0,AngleToRadian(-5), 0);
    else if (c == 'z'){
        nowrad -= AngleToRadian(5);
        cameraVector.x() = cos(nowrad) * radius;
        cameraVector.z() = sin(nowrad) * radius;
        updateDisplay();
    }
    else if (c == 'x'){
        nowrad += AngleToRadian(5);
        cameraVector.x() = cos(nowrad) * radius;
        cameraVector.z() = sin(nowrad) * radius;
        updateDisplay();
    }
    else if (c == 'c'){
        cameraVector.y() += 0.2;
        updateDisplay();
    }
    else if (c == 'v'){
        cameraVector.y() -= 0.2;
        updateDisplay();
    }
    else if (c == 'b'){
        radius += 0.2;
        cameraVector.x() = cos(nowrad) * radius;
        cameraVector.z() = sin(nowrad) * radius;
        updateDisplay();
    }
    else if (c == 'n'){
        radius -= 0.2;
        cameraVector.x() = cos(nowrad) * radius;
        cameraVector.z() = sin(nowrad) * radius;
        updateDisplay();
    }
    else if (c == 'e'){
        braco.part1.part2.finger1.rotate(0, AngleToRadian(5), 0);
        braco.part1.part2.finger2.rotate(0, AngleToRadian(5), 0);
    }
    else if (c == 'r'){
        braco.part1.part2.finger1.rotate(0, AngleToRadian(-5), 0);
        braco.part1.part2.finger2.rotate(0, AngleToRadian(-5), 0);
    }
    else if (c == 't'){
        if (pegou_objeto){
            pegou_objeto = false;
        }
        else {
            forinc(i,0 , formas.size()-1){
                DesenhaFormas * object = formas[i];
                Vector3D center = convertVectorToObjectSpace(object->center, object->transform);
                Matrix4 objectSpace = braco.getObjectSpace();
                Vector3D p = convertVectorToObjectSpace(object->center,objectSpace);
                p = center - p;
                moveVector = Vector3D(0,0.4,0);
                if (p.length() <= 0.6) {
                    pegou_objeto = true; //pega um objeto;
                    pega_objeto = i; //define qual objeto pegou
                    break;
                }
            }
        }
    }
    if (pegou_objeto) {
        Matrix4 objectSpace = braco.getObjectSpace();
        DesenhaFormas * forma = formas[pega_objeto];
       forma->transform = Matrix4().translationMatrix(moveVector.x(), moveVector.y(), moveVector.z()) * objectSpace;
    }
    if (c == 27)
        exit(0);
}

#endif //INITS_H
