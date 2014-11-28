#ifndef UTILS_H
#define UTILS_H

//Todos os arquivos.h e alguns defines para cor e texturas(não consegui usar textura, mas ta implementado);

#include "Constants.h" //Definição de constantes
#include "Matrix.h" //Do c++
#include "Vector.h" //Do c++
#include "Ray.h" //Calcula direção da luz
#include "DesenhaFormas.h" //DesenhaFormas (oi!?)
#include "Polygon.h" //Desenha poligonos
#include "Triangle.h" //Desenha triangulos
#include "Rectangle.h" //Desenha retangulos
#include "Floor.h" //Desenha chão
#include "Cube.h" //Desenha cubos3D
#include "NGone.h" //Desenha poligonos3D
#include "Conus.h" //Desenha cone3D
#include "Sphere.h" //Desenha esfera 3D
#include "Light.h" //Desenha Luz
#include "Spacefunc.h" //Funções matemáticas, manipulação de vetores, matrizes, etc
#include "Camera.h" //Rotaciona câmera

#define BlackColor Vector4D(0,0,0,1.0)
#define WhiteColor Vector4D(1.0,1.0,1.0,1.0)
#define RedColor Vector4D(1.0,0,0,1.0)
#define GreenColor Vector4D(0,1.0,0,1.0)
#define BlueColor Vector4D(0,0,1.0,1.0)
#define YellowColor Vector4D(1.0,1.0,0,1.0)

#define NoneMaterial Material()
#define SilverMaterial Material(MaterialTypeSilver)
#define GoldMaterial Material(MaterialTypeGold)
#define PewterMaterial Material(MaterialTypePewter)
#define CopperMaterial Material(MaterialTypeCopper)

#endif // UTILS_H
