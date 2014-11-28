#ifndef RAY_H
#define RAY_H

#include "Constants.h"
#include "Vector.h"

class Ray {
public:
    Vector3D dest, dir;// destination, dirrection
    Ray() { dest = Vector3D(), dir = Vector3D(); }
    Ray(Vector3D de, Vector3D di) { dest = de, dir = di; }

    Ray(const Ray & r) {
        dest = r.dest;
        dir = r.dir;
    }

    Ray & operator = (const Ray & r) {
        dest = r.dest;
        dir = r.dir;
        return *this;
    }
    void printDescription() const {
        dest.printDescription();
        dir.printDescription();
    }
};

#endif // RAY_H
