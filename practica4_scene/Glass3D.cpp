//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Glass3D.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


Glass3D::Glass3D() {

        points = new Vertex3D*[6];
        for(int i = 0; i < 6; i++) {
                points[i] = new Vertex3D();
        }

        points[0]->x = 10;
        points[0]->y = 0;
        points[0]->z = 0;

        points[1]->x = 5;
        points[1]->y = 2;
        //points[1]->z = 10;
        points[1]->z = 0;

        points[2]->x = 5;
        points[2]->y = 5;
        //points[2]->z = 20;
        points[2]->z = 0;

        points[3]->x = 8;
        points[3]->y = 15;
        //points[3]->z = 30;
        points[3]->z = 0;

        points[4]->x = 12;
        points[4]->y = 25;
        //points[4]->z = 40;
        points[4]->z = 0;

        points[5]->x = 17;
        points[5]->y = 30;
        //points[5]->z = 50;
        points[5]->z = 0;

}

Glass3D::~Glass3D() {

        for(int i = 0; i < 6; i++) {
                delete points[i];
        }

        delete points;
}

void Glass3D::RecalculateMesh() {

        double pi = 4*atan(1);
        double div = 2*pi/20;

        //Calculamos los vértices de la copa
        double ang;
        //int i = 0;
        Vertex3D** aux = new Vertex3D*[120];

        for(int i = 0; i < 20; i++) {

                ang = i*div;

                for(int j = 0; j < 6; j++) {
                        Vertex3D* transf = new Vertex3D();
                        transf->x = cos(ang)*points[j]->x + sin(ang)*points[j]->z;
                        transf->y = points[j]->y;
                        transf->z = -sin(ang)*points[j]->x + cos(ang)*points[j]->z;
                        vertices->push_back(transf);
                        aux[6*i+j] = transf; 
                }
        }

                for(int k = 0; k < 19; k++) {
                        for(int l = 0; l < 5; l++) {
                                Face3D* f = new Face3D();
                                faces->push_back(f);
                                f->vertices->push_back(aux[6*k + l]);
                                f->vertices->push_back(aux[6*k + (l+6)]);
                                f->vertices->push_back(aux[6*k + (l+7)]);
                                f->vertices->push_back(aux[6*k + (l+1)]);
                                RecalculateNormals(*f);
                        }

                        if(k == 18) {
                                k++;
                                for(int l = 0; l < 5; l++) {
                                        Face3D* f = new Face3D();
                                        faces->push_back(f);
                                        f->vertices->push_back(aux[6*k + l]);
                                        f->vertices->push_back(aux[l]);
                                        f->vertices->push_back(aux[l+1]);
                                        f->vertices->push_back(aux[6*k + (l+1)]);
                                        RecalculateNormals(*f);
                                }
                        }

                }

        delete[] aux;


}

String Glass3D::getName() {
        return "copa";
}