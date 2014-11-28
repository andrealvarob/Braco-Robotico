#ifndef POLYGON_H
#define POLYGON_H

#include "DesenhaFormas.h"

const int MaxPointCount = 4;

class Polygon : public DesenhaFormas {
protected:
    int n; // number of points
    Vector3D points[MaxPointCount];
    void initialise() {
        transform = Matrix4().identity();
    }
public:
    Polygon(int nVectors = 2) : n(nVectors) { initialise(); }
    Polygon(const Polygon & p) : DesenhaFormas(p) {
        n = p.n;
        forinc(i, 0, n-1)
            points[i] = Vector3D(p.points[i]);
    }
    Polygon & operator = (const Polygon & p) {
        DesenhaFormas::operator=(p);

        n = p.n;
        forinc(i, 0, n-1)
            points[i] = Vector3D(p.points[i]);

        return *this;
    }
    int size() const { return n; }
    void draw() {
        glPushMatrix();

        glMultMatrixf(transform.A());

        glLineWidth(2);
            glEnable(GL_COLOR_MATERIAL);
            glColor3fv(color.V());
            glDisable(GL_COLOR_MATERIAL);

        glBegin(GL_POLYGON);
        forinc(i,0,n-1) {
            glNormal3fv(points[i].V());
            glVertex3fv(points[i].V());
        }
        glEnd();

        glPopMatrix();
    }
};

#endif // POLYGON_H
