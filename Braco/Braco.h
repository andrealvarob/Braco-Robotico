#ifndef BRACO_H
#define BRACO_H

#include  "Utils.h" //Inclui arquivo de todas as funções do projeto

//classes das partes do braco

//classe da garra, herda da classe DesenhaFormas
class RobotFinger : public DesenhaFormas{
public:
    NGone fingerStep;
    Sphere fingerRotationSphere;
    Conus fingerTop;
    //Nesse Metodo(O contrutor da classe) são definidas as formas das garras do robo, igual a Formas3d() do Inits.h
    RobotFinger() {
        fingerStep = NGone(12, 2, 0.01, 3, 0.1, YellowColor);
        fingerRotationSphere = Sphere(0.04, 10, 10, BlueColor);
        fingerRotationSphere.translate(0, 0.3, 0);
        fingerTop = Conus(12, 2, 0.01, 4, 0.1, YellowColor);
        fingerTop.translate(0, 0.3, 0);
        fingerTop.rotate(0, AngleToRadian(-30), 0);
    }
    //Nesse Metodo são desenhadas as formas da garra
    void draw() {
        glPushMatrix();

        glMultMatrixf(transform.A());

        fingerStep.draw();
        fingerTop.draw();
        fingerRotationSphere.draw();

        glPopMatrix();
    }
};

//Assim como classe da garra, esta classe é responsável por uma parte do braco, o ante_braço;.
class RobotArmPart2 : public DesenhaFormas {
public:
    NGone   firstRotationStick;
    Sphere   stickHead;
    RobotFinger finger1,finger2; //Nesta classe é feita a união das formas da anterios com a desta
    RobotArmPart2 () {
        //Construtor; define as formas do ante_braço;
        firstRotationStick = NGone(32, 2, 0.1, 12, 0.1, YellowColor);
        stickHead = Sphere(0.25, 10, 10, BlueColor);
        stickHead.translate(0, 1.2, 0);
        finger1 = RobotFinger();
        finger1.translate(0.2, 1.3, 0);
        finger1.rotate(0, AngleToRadian(45), 0);

        finger2 = RobotFinger();
        finger2.translate(-0.2, 1.3, 0);
        finger2.rotate(0, AngleToRadian(-45), AngleToRadian(180));
    }
    Matrix4 getObjectSpace() {
        return stickHead.transform * transform;
    }
    //Desenha
    void draw() {
        glPushMatrix();

        glMultMatrixf(transform.A());

        firstRotationStick.draw();
        stickHead.draw();
        finger1.draw();
        finger2.draw();

        glPopMatrix();
    }
};

//Braço
class RobotArmPart1 : public DesenhaFormas {
public:
    NGone   firstRotationStick;
    Sphere       firstRotationSphere1;
    RobotArmPart2 part2; //Une as formas da classe anterior

    RobotArmPart1() {
        //Contrutor, faz o mesmo das anteriores
        firstRotationStick = NGone(32, 2, 0.1, 12, 0.1, YellowColor);
        firstRotationSphere1 = Sphere(0.25, 10, 10, BlueColor);
        firstRotationSphere1.translate(0, 1.2, 0);
        firstRotationSphere1.rotate(AngleToRadian(90), 0, 0);

        part2 = RobotArmPart2();
        part2.translate(0, 1.2, 0);
        part2.rotate(0,  AngleToRadian(-90), 0);
    }
    Matrix4 getObjectSpace() {
        return part2.getObjectSpace() * transform;
    }
    //Desenha
    void draw() {
        glPushMatrix();

        glMultMatrixf(transform.A());

        firstRotationStick.draw();
        firstRotationSphere1.draw();
        part2.draw();

        glPopMatrix();
    }
};

//A classe mais importante, une todos os membros do braço
class Braco : public DesenhaFormas {
public:
    NGone   bottomRotationCone1, bottomStickCone;
    Sphere  firstRotationSphere1;
    RobotArmPart1 part1;

    Braco(){
        bottomRotationCone1 = NGone(16, 6, 0.1, 1, 0.25, RedColor);
        bottomStickCone = NGone(16, 2, 0.1, 5, 0.2, YellowColor);
        firstRotationSphere1 = Sphere(0.25, 10, 10, BlueColor);

        firstRotationSphere1.translate(0, 1.2, 0);
        firstRotationSphere1.rotate(AngleToRadian(90), 0, 0);
        part1 = RobotArmPart1();
        part1.translate(0, 1.2, 0);
        part1.rotate(0,  AngleToRadian(-30), 0);
    }
    Matrix4 getObjectSpace() {
        return part1.getObjectSpace() * transform;
    }
    void draw(){
        glPushMatrix();

        glMultMatrixf(transform.A());

        bottomRotationCone1.draw();
        bottomStickCone.draw();
        firstRotationSphere1.draw();
        part1.draw();

        glPopMatrix();
    }
};


#endif // BRACO_H
