#include <vcl.h>
#pragma hdrstop
#include "Revolution3D.h"
#pragma package(smart_init)


Revolution3D::Revolution3D() : Mesh3D() {
        points = new list<PV3D*>();
        npoints = new list<PV3D*>();

        n = 32;
}

Revolution3D::~Revolution3D() {
        list<PV3D*>::iterator it;
        for (it = points->begin(); it != points->end(); it++)
                delete *it;

        delete points;

        list<PV3D*>::iterator it_2;
        for (it_2 = npoints->begin(); it_2 != npoints->end(); it_2++)
                delete *it_2;

        delete npoints;
}

void Revolution3D::RecalculateMesh() {
        clearLists();

        int np = points->size();
        double pi = 4*atan(1);

        //Le pido que calcule los puntos nuevos
        //Es decir: yo tengo una serie de puntos definidos en Window.cpp
        //Esta funcion, "RepaintBSpline3", lo que hace es meter en npoints los puntos
        //que resultan de obtener la bspline anterior
        //RepaintBSpline3(points);
        //int np = npoints->size();

        // Genero todos los vértices en la estructura auxiliar V
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

AnsiString Revolution3D::getName() {
        return "Revolution";
}


void Revolution3D::RepaintBSpline3(list<PV3D*>* points) {
        list<PV3D*>::iterator it;
        PV3D *pv;

        PV3D * p1;
        PV3D * p2;
        PV3D * p3;

        PV3D * pp1;
        PV3D * pp2;
        PV3D * pp3;


	PV3D *p4;

        it = points->begin();

	p1 = *it;
        if (it != points->end()) it++;

	p2 = *it;
        if (it != points->end()) it++;

	p3 = *it;
        if (it != points->end()) it++;

	double t;
        bool first = true;

        for (  ; it != points->end(); it++ ) {
                p4 = *it;
                // Desplazo los siguientes:
                BSpline3Segment(p1,p2,p3,p4, points, first);
                p1 = p2;
                p2 = p3;
                p3 = p4;
                first = false;
	}
}


void Revolution3D::BSpline3Segment(PV3D* p1, PV3D* p2, PV3D* p3, PV3D* p4, list<PV3D*>* line, bool first) {
        //double n = line->segments;
//        double n = line->size() - 1;
        double n = 3;

	double t;

        for (int i = 0; i<=n; i++) {
                t = i;t /= n;
                //Creo el punto
                PV3D *p = new PV3D((double) (t*t*t*(p4->x-p1->x+3*p2->x-3*p3->x)+t*t*(3*p1->x-6*p2->x+3*p3->x)+t*(3*p3->x-3*p1->x)+p1->x+4*p2->x+p3->x)/6,(double) (t*t*t*(p4->y-p1->y+3*p2->y-3*p3->y)+t*t*(3*p1->y-6*p2->y+3*p3->y)+t*(3*p3->y-3*p1->y)+p1->y+4*p2->y+p3->y)/6, (double) (t*t*t*(p4->z-p1->z+3*p2->z-3*p3->z)+t*t*(3*p1->z-6*p2->z+3*p3->z)+t*(3*p3->z-3*p1->z)+p1->z+4*p2->z+p3->z)/6);
                //Lo meto en la nueva lista , pero me he fijado en que cuando vuelvo
                //y hago p1 = p2, p2 = p3... obtengo el mismo punto
                //para no meterlo 2 veces, no lo meto la segunda vez
                if((i == 0) && (first)) {
                        npoints->push_back(p);
                }
                else {
                        npoints->push_back(p);
                }
        }
}



