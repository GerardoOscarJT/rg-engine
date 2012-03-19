#include <vcl.h>
#pragma hdrstop
#include "Revolution3D.h"
#pragma package(smart_init)





Revolution3D::Revolution3D() : Mesh3D() {
        points = new list<PV3D*>();

        n = 32;
}

Revolution3D::~Revolution3D() {
        list<PV3D*>::iterator it;
        for (it = points->begin(); it != points->end(); it++)
                delete *it;

        delete points;
}

void Revolution3D::RecalculateMesh() {
        clearLists();

        int np = points->size();
        double pi = 4*atan(1);

        // Genero todos los vértices en la estructura auxiliar V
        Vertex3D*** V = new Vertex3D**[np];
        list<PV3D*>::iterator it;
        PV3D *point;

        int i = 0;
        for (it = points->begin(); it != points->end(); it++) {
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

        // Destruyo la estructura auxiliar V
        for (int i=0; i<np; i++) {
                delete[] V[i];
        }
        delete[] V;






}

AnsiString Revolution3D::getName() {
        return "Revolution";
}
