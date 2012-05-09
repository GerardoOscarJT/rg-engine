//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sphere3D.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Sphere3D::Sphere3D() {
        radius = 20;
        nParallels = 20;
        nMeridians = 20;

        points = new list<PV3D*>();
        n = nMeridians;
}

Sphere3D::Sphere3D(double _radius, int _nParallels, int _nMeridians) {

        radius = _radius;
        nParallels = _nParallels;
        nMeridians = _nMeridians;

        points = new list<PV3D*>();
        n = nMeridians;
}

void Sphere3D::RecalculateMesh() {

        double pi = 4*atan(1);

        double inc_ang = pi/nParallels;
        for(int i = 0; i <= nParallels; i++) {
                double ang = i*inc_ang;
                Vertex3D* v;
                v = new Vertex3D(0, -radius*sin(ang), radius*cos(ang));
                points->push_back(v);
                vertices->push_back(v);
        }

        int np = points->size();
        Vertex3D*** V = new Vertex3D**[np];
        list<PV3D*>::iterator it;
        PV3D *point;

        int i = 0;
        for (it = points->begin(); it != points->end(); it++) {
        //for (it = npoints->begin(); it != npoints->end(); it++) {
                point = *it;
                V[i] = new Vertex3D*[n];
                double mod = sqrt(pow(point->x,2)+pow(point->y,2));
                for (int j=0; j<n; j++) {
                        V[i][j] = new Vertex3D(mod*cos(j*2*pi/n), mod*sin(j*2*pi/n), point->z);
                        vertices->push_back(V[i][j]);
                }
                i++;
        }

        // Genero todas las caras utilizando V
        for (int i=0; i<np - 1; i++) {
                for (int j=0; j<n; j++) {
                        Face3D* F = new Face3D(); faces->push_back(F);
                        F->vertices->push_back(V[i][j]);
                        F->vertices->push_back(V[i][(j+1)%n]);
                        F->vertices->push_back(V[i+1][(j+1)%n]);
                        F->vertices->push_back(V[i+1][j]);
                }
        }
        RecalculateNormals();

        // Destruyo la estructura auxiliar V
        for (int i=0; i<np; i++) {
                delete[] V[i];
        }
        delete[] V;

}

Sphere3D::~Sphere3D() {
}

AnsiString Sphere3D::getName() {
        return "Sphere";
}
