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
                        /*Face3D* F = new Face3D(); faces->push_back(F);
                        F->vertices->push_back(V[i][(j+1)%nP]);
                        F->vertices->push_back(V[i][j]);
                        F->vertices->push_back(V[(i+1)%nQ][j]);
                        F->vertices->push_back(V[(i+1)%nQ][(j+1)%nP]);*/



                        Face3D* F1, *F2;
                        F1 = new Face3D();
                        F2 = new Face3D();
                        faces->push_back(F1);
                        faces->push_back(F2);

                        F1->vertices->push_back(V[i][j]);
                        F1->vertices->push_back(V[(i+1)%nQ][j]);
                        F1->vertices->push_back(V[(i+1)%nQ][(j+1)%nP]);

                        F2->vertices->push_back(V[i][(j+1)%nP]);
                        F2->vertices->push_back(V[i][j]);
                        F2->vertices->push_back(V[(i+1)%nQ][(j+1)%nP]);

                        /*Vertex3D *nv = newVertex(*(V[i][(j+1)%nP]), *(V[i][j]), *(V[(i + 1)%nQ][j]), *(V[(i + 1)%nQ][(j+1)%nP]));
                        vertices->push_back(nv);
                        Face3D *F1, *F2, *F3, *F4;
                        F1 = new Face3D();
                        F2 = new Face3D();
                        F3 = new Face3D();
                        F4 = new Face3D();

                        faces->push_back(F1);
                        faces->push_back(F2);
                        faces->push_back(F3);
                        faces->push_back(F4);

                        F1->vertices->push_back(V[i][j]);
                        F1->vertices->push_back(V[(i+1)%nQ][j]);
                        F1->vertices->push_back(nv);

                        F2->vertices->push_back(V[(i+1)%nQ][j]);
                        F2->vertices->push_back(V[(i+1)%nQ][(j+1)%nP]);
                        F2->vertices->push_back(nv);

                        F3->vertices->push_back(V[(i+1)%nQ][(j+1)%nP]);
                        F3->vertices->push_back(V[i][(j+1)%nP]);
                        F3->vertices->push_back(nv);

                        F4->vertices->push_back(V[i][(j+1)%nP]);
                        F4->vertices->push_back(V[i][j]);
                        F4->vertices->push_back(nv);       */
                        









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




Vertex3D* Epitrochoid3D::newVertex(Vertex3D &p1, Vertex3D &p2, Vertex3D &p3, Vertex3D &p4) {

        double res_x = 0, res_y = 0, res_z = 0;
        Vertex3D *res;

        res_x = p1.x + p2.x + p3.x + p4.x;
        res_y = p1.y + p2.y + p3.y + p4.y;
        res_z = p1.z + p2.z + p3.z + p4.z;

        res_x /= 4;
        res_y /= 4;
        res_z /= 4;

        res = new Vertex3D(res_x, res_y, res_z);

        return res;

}




String Epitrochoid3D::getName() {
        return "Epitrochoid";
}

