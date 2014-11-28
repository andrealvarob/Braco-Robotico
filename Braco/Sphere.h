#ifndef SPHERE_H
#define SPHERE_H

#include "Constants.h"
#include "Rectangle.h"
#include "Triangle.h"

Vector3D rotatedVectorWithRadius(double radius,double alpha, double beta) {
    return Vector3D(radius * sin(AngleToRadian(beta)) * cos(AngleToRadian(alpha)),
                   radius * sin(AngleToRadian(beta)) * sin(AngleToRadian(alpha)),
                   radius * cos(AngleToRadian(beta)));
}

class Sphere : public DesenhaFormas {
private:
    GLfloat radius;
public:
    vector<Polygon> polygons;
    Sphere() {}

    Sphere(double r, double angleX, double angleY, Vector4D cl) {
        radius = r;
        color = cl;
        int numberOfVectorsInCircleXY = (Angle2PI / angleX);
        int numberOfVectorsInCircleZY = (AnglePI / angleY);
        angleX = Angle2PI / numberOfVectorsInCircleXY;
        angleY = AnglePI / numberOfVectorsInCircleZY;

        for (int i = 1; i < numberOfVectorsInCircleZY; i++) {
            for (int j = 0; j < numberOfVectorsInCircleXY; j++) {
                double alpha = angleX * j,
                       beta = angleY * i;
                Vector3D curVector = rotatedVectorWithRadius(radius, alpha, beta),
                        nextVector = rotatedVectorWithRadius(radius, alpha + angleX, beta);

                if (i == 1) {
                    Vector3D a = rotatedVectorWithRadius(radius, 0, 0);
                    Triangle t = Triangle(curVector, nextVector, a);
                    t.color = color;
                    polygons.push_back(t);
                }
                else {
                    if (i == numberOfVectorsInCircleZY - 1) {
                        Vector3D a = rotatedVectorWithRadius(radius, alpha, beta + angleY);
                        Triangle t = Triangle(curVector, a, nextVector);
                        t.color = color;
                        polygons.push_back(t);
                    }
                    Vector3D a = rotatedVectorWithRadius(radius, alpha, beta - angleY),
                    b = rotatedVectorWithRadius(radius, alpha + angleX, beta - angleY);
                    Rectangle rect = Rectangle(curVector, nextVector, b, a);
                    rect.color = color;
                    polygons.push_back(rect);
                }
            }
        }
    }
    Sphere(const Sphere & c) : DesenhaFormas(c) {
        polygons = c.polygons;
    }
    Sphere & operator = (const Sphere & c) {
        DesenhaFormas::operator=(c);

        polygons = c.polygons;

        return *this;
    }
    bool intersects(Ray & ray, Vector3D * p = NULL, Vector3D * normal = NULL) {
        GLfloat b = (ray.dest - center).dotProduct(ray.dir) * 2, c = (ray.dest - center).dotProduct(ray.dest - center) - radius * radius;
        GLfloat d = b * b - 4 * c;
        if (d < 0)
            return false;
        d = sqrt(d);

        GLfloat t1 = (-b - d) / 2, t2 = (-b + d) / 2;
        if (t1 > t2)
            swap(t1, t2);

        if (t2 < EPS)
            return false;

        if (t1 < EPS)
            t1 = t2;

        if (p)
            *p = ray.dest + ray.dir * t1;
        if (normal)
            *normal = (*p - center).normalize();

        return true;
    }

    void draw() {
        glPushMatrix();

        glMultMatrixf(transform.A());

        forinc(i, 0, polygons.size()-1) {
            polygons[i].draw();
        }

        glPopMatrix();
    }
};

#endif // SPHERE_H
