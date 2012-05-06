//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Disk3D.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Disk3D::Disk3D(double _innerRadius, double _outerRadius, int _nSlices, int _nRings) {
        innerRadius = _innerRadius;
        outerRadius = _outerRadius;
        nSlices = _nSlices;
        nRings = _nRings;
}

Disk3D::~Disk3D() {
}

void Disk3D::RecalculateMesh() {

        //TODO: radio interior y número de anillos concéntricos

        double pi = 4*atan(1);

        double inc_ang = (2*pi)/nSlices;
        Vertex3D *zero = new Vertex3D(0,0,0);

        for(int i=0; i<nSlices; i++) {
                double ang = i*inc_ang;
                Vertex3D* v = new Vertex3D(outerRadius*cos(ang), outerRadius*sin(ang), 0);
                vertices->push_back(v);
        }

        list<Vertex3D*>::iterator it;
        for(it = vertices->begin(); it != vertices->end(); it++ ){
                Vertex3D *aux = *it;
                Face3D *f = new Face3D(); faces->push_back(f);
                it++;
                if(it != vertices->end()) {
                        Vertex3D *v = *it;
                        f->vertices->push_back(aux);
                        f->vertices->push_back(v);
                        f->vertices->push_back(zero);
                }
                else {
                        f->vertices->push_back(aux);
                        f->vertices->push_back(vertices->front());
                        f->vertices->push_back(zero);
                }
                it--;
        }

        RecalculateNormals();

}

AnsiString Disk3D::getName() {
        return "Disk";
}


