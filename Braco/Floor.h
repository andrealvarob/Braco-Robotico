#ifndef FLOOR_H
#define FLOOR_h

#include "Rectangle.h"

class Floor : public DesenhaFormas {
private:
    vector<Rectangle> rects;

public:
    Floor() {};
    Floor(int numberOfUnitsInWidth, int numberOfUnitsInHeight, double unitHeight, Vector4D cl) {
        color = cl;
        forinc(i,0,numberOfUnitsInWidth - 1)
        forinc(j,0,numberOfUnitsInHeight - 1) {
            Vector3D a = Vector3D(j * unitHeight - numberOfUnitsInHeight * unitHeight / 2,
                                0,i * unitHeight - numberOfUnitsInWidth * unitHeight / 2),
                    b = a + Vector3D(0, 0, unitHeight),
                    c = b + Vector3D(unitHeight,0,0),
                    d = c - Vector3D(0, 0, unitHeight);
            Rectangle rect = Rectangle(a, b, c, d);
            rect.color = color;
            rects.push_back(rect);
        }
    }
    Floor(const Floor & f) : DesenhaFormas(f) {
        rects = f.rects;
    }
    Floor & operator = (const Floor & f) {
        DesenhaFormas::operator=(f);

        rects = f.rects;

        return *this;
    }
    void draw() {
        glPushMatrix();

        glMultMatrixf(transform.A());

        forinc(i, 0, rects.size()-1)
            rects[i].draw();

        glPopMatrix();
    }
};


#endif // FLOOR_H
