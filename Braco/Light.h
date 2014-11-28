#ifndef LIGHT_H
#define LIGHT_H

#include "Vector.h"

class Light{
private:
    static int objectCount;
    int lightID;
public:
    bool enabled;
    Material material;
    Vector3D position;
    GLfloat constantAttenuation, linearAttenuation, quadraticAttenuation;
    Light() {}
    Light(Material mt, Vector3D p, GLfloat ca = 1.0, GLfloat la = 0.2, GLfloat qa = 0.05) {
        material = mt;
        position = p;
        constantAttenuation = ca;
        linearAttenuation = la;
        quadraticAttenuation = qa;
        lightID = objectCount + GL_LIGHT0;
        objectCount ++;
        enabled = false;
    }
    Light(const Light & lt) {
        material = Material(lt.material);
        position = Vector3D(lt.position);
        constantAttenuation = lt.constantAttenuation;
        linearAttenuation = lt.linearAttenuation;
        quadraticAttenuation = lt.quadraticAttenuation;
        enabled = lt.enabled;
        lightID = lt.getLightID();
    }
    Light & operator = (const Light & lt) {
        material = Material(lt.material);
        position = Vector3D(lt.position);
        constantAttenuation = lt.constantAttenuation;
        linearAttenuation = lt.linearAttenuation;
        quadraticAttenuation = lt.quadraticAttenuation;
        enabled = lt.enabled;
        lightID = lt.getLightID();
        return *this;
    }
    int getLightID() const { return lightID; }
    void updateLight() {
        if (enabled) {
            glEnable(lightID);
            glLightfv(lightID, GL_AMBIENT, material.ambient.V());
            glLightfv(lightID, GL_DIFFUSE, material.diffuse.V());
            glLightfv(lightID, GL_SPECULAR, material.specular.V());
            glLightf(lightID, GL_CONSTANT_ATTENUATION, constantAttenuation);
            glLightf(lightID, GL_LINEAR_ATTENUATION, linearAttenuation);
            glLightf(lightID, GL_QUADRATIC_ATTENUATION, quadraticAttenuation);
            GLfloat p[] = { (GLfloat)position[0],(GLfloat)position[1],(GLfloat)position[2],0};
            glLightfv(lightID, GL_POSITION, p);
        }
        else {
            glDisable(lightID);
        }
    }
};

int Light::objectCount = 0;

#endif // LIGHT_H
