#include <vcl.h>
#pragma hdrstop

#include "FrenetFrame.h"

#pragma package(smart_init)

FrenetFrame::FrenetFrame() {

}

void FrenetFrame::transformPoint(PV3D *p) {
        double x=p->x, y=p->y, z=p->z;

        PV3D c = C(_t);

        p->x = _N.x*x + _B.x*y + _T.x*z + p->t * c.x;
        p->y = _N.y*x + _B.y*y + _T.y*z + p->t * c.y;
        p->z = _N.z*x + _B.z*y + _T.z*z + p->t * c.z;
}

void FrenetFrame::setT(double t) {  //T es el frame, me parece (NOOO t es el parámetro de la ecuación)
        _t = t;

        // Recalcular matrices chungas...
        _T = C1(t);
        _T.normalize();

        _B = C1(t).crossProduct(C2(t));
        _B.normalize();

        _N = _T.crossProduct(_B);

        //Tenemos las 3 columnas de la matriz

}


double FrenetFrame::getT() {
        return _t;
}

