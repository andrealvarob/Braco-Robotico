# Braco Robótico

Este projeto é uma simulação 3D de um braço robótico, 
desenvolvido para obtenção de nota referente a disciplina Computação Gráfica(DCA0114) 2014.2,
Este modelo foi construido baseando-se nos parâmetros de Denavit-Hartenberg(http://en.wikipedia.org/wiki/Denavit%E2%80%93Hartenberg_parameters), os arquivos Matriz.h, Vector.h e Spacefunc.h(Original:Mathlib.h) foram incluidos para calculos referente
ao ângulos de rotação das formas;

## Dependencias
* Open_GL
* GLUT
* GNU g++
* STL

## Como compilar

##Linux

- Terminal(crtl+alt+t)
user@vehicle:~/diretorio$ g++ main.cpp -o EXE -lGL -lGLU -lglut

## Como executar

- Terminal(crtl+alt+t)
user@vehicle:~/diretorio$ ./EXE

##Controles do braço e da câmera

Nesse projeto você pode utilizar os seguintes comandos para controlar o Braço:

* `q / w` -> `q` gira o ANTEBRAÇO no sentindo HORARIO e `w` no sentido ANTI-HORARIO;
* `e / r` -> `e` ABRE PINÇA e `r` FECHA PINÇA;
* `a / s` -> `a` gira a BASE no sentindo HORARIO e `s` no sentindo ANTI-HORARIO;
* `d / f` -> `d` gira o BRAÇO no sentido HORARIO e `f` no sentindo ANTI-HORARIO;
* `z / x` -> `z` gira a CÂMERA na HORIZONTAL no sentido HORARIO e `x` HORIZONTAL no sentindo ANTI-HORARIO;
* `c / v` -> `c` gira a CÂMERA na VERTICAL no sentido HORARIO e `v` VERTICAL no sentindo ANTI-HORARIO;
* `b / n` -> `b` AFASTA a CÂMERA e `n` APROXIMA a CÂMERA;
* `t` -> Pega objeto;
