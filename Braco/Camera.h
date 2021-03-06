#ifndef CAMERA_H
#define CAMERA_H

#include "Vector.h"
#include "Ray.h"

class Camera{
public:
    int front, width, height;
    Vector3D eyePos;
    Camera() {}
    Camera(GLfloat f, GLfloat w, GLfloat h) {
        front = f;
        width = w;
        height = h;
        eyePos = Vector3D(0,0,-front);
    }

    Camera(const Camera & c) {
        front = c.front;
        width = c.width;
        height = c.height;
        eyePos = c.eyePos;
    }

    Camera & operator = (const Camera & c) {
        front = c.front;
        width = c.width;
        height = c.height;
        eyePos = c.eyePos;
        return *this;
    }

    Ray getRay(GLfloat i, GLfloat j) {
        Vector3D pos = Vector3D(j - width * 0.5, height * 0.5 - i, 0) - eyePos;
        return Ray(eyePos,  pos.normalize());
    }
};

#endif // CAMERA_H
