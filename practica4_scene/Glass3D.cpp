//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Glass3D.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


Glass3D::Glass3D() {

        copa = new Revolution3D();
        copa->n = 64;

        copa->points->push_back(new PV3D(0,0,8));
        copa->points->push_back(new PV3D(0,0,8));
        copa->points->push_back(new PV3D(0,0,8));
        copa->points->push_back(new PV3D(50,0,0));
        copa->points->push_back(new PV3D(50,0,2));
        copa->points->push_back(new PV3D(4,0,10));
        copa->points->push_back(new PV3D(4,0,100));
        copa->points->push_back(new PV3D(4,0,100));
        copa->points->push_back(new PV3D(100,0,200));
        copa->points->push_back(new PV3D(99,0,201));
        copa->points->push_back(new PV3D(98,0,200));
        copa->points->push_back(new PV3D(0,0,102));
        copa->points->push_back(new PV3D(0,0,102));

}

Glass3D::~Glass3D() {

        /*for(int i = 0; i < 6; i++) {
                delete points[i];
        }

        delete points;*/
        delete copa;
}

void Glass3D::RecalculateMesh() {

        /*double pi = 4*atan(1);
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
                                }
                        }

                }

        delete[] aux;   */

        copa->RecalculateMesh();


}

String Glass3D::getName() {
        return "copa";
}