#include <vcl.h>
#pragma hdrstop
#include "Epitrochoid3D.h"
#pragma package(smart_init)


Epitrochoid3D::Epitrochoid3D() : Mesh3D() {
        // Valores iniciales de la epitrocoide
        a = 150;
        b = 50;
        h = 150;
        r = 20;

        // Discretización
        nP = 8;
        nQ = 60;

        RecalculateMesh();
}


void Epitrochoid3D::RecalculateMesh() {
        clearLists();

        double pi = 4*atan(1);

        _frenet_frame.a = a;
        _frenet_frame.b = b;
        _frenet_frame.h = h;

        // Genero todos los vértices en la estructura auxiliar V

        Vertex3D*** V = new Vertex3D**[nQ];
        for (int i=0; i<nQ; i++) {
                V[i] = new Vertex3D*[nP];
                _frenet_frame.setT(i*2*pi/nQ); // angle
                for (int j=0; j<nP; j++) {
                        V[i][j] = new Vertex3D(r*cos(j*2*pi/nP),r*sin(j*2*pi/nP),0);
                        _frenet_frame.transformPoint(V[i][j]);
                        vertices->push_back(V[i][j]);
                }
        }

        // Genero todas las caras utilizando V
        for (int i=0; i<nQ; i++) {
                for (int j=0; j<nP; j++) {
                        Face3D* F = new Face3D(); faces->push_back(F);
                        F->vertices->push_back(V[i][(j+1)%nP]);
                        F->vertices->push_back(V[i][j]);
                        F->vertices->push_back(V[(i+1)%nQ][j]);
                        F->vertices->push_back(V[(i+1)%nQ][(j+1)%nP]);
                }
        }

        // Destruyo la estructura auxiliar V
        for (int i=0; i<nQ; i++) {
                delete[] V[i];
        }
        delete[] V;


        // TODO: Llamar a recalculate normals

        RecalculateNormals();
        /*list<Face3D*>::iterator it_f;
        Face3D* f;
        for(it_f = faces->begin(); it_f != faces->end(); it_f++) {
                f = *it_f;

        } */

}


String Epitrochoid3D::getName() {
        return "Epitrochoid";
}

