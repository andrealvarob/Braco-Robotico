#include <cstdio>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Inits.h" //inclui as inicializações da Open_GL e aqrquivos.h usados no projeto

//Abra o README
//Os outros arquivos.h tb estão comentados
int main(int argc, char * argv[]){

    Formas3D(); //Explica em Inits.h

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(W, H);
    glutInitWindowPosition(W/2, H/2);
    glutCreateWindow("Braco");

    Inits();
    glutDisplayFunc(redraw);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handleKeyPress);
    glutIdleFunc(redraw);
    glutMainLoop();

    return 0;
}
