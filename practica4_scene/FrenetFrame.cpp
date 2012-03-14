#include <vcl.h>
#pragma hdrstop

#include "FrenetFrame.h"

#pragma package(smart_init)

FrenetFrame::FrenetFrame() {

}

PV3D FrenetFrame::transformPoint(PV3D p) {
        PV3D r;
        PV3D c = C(_t);

        r.x = _N.x*p.x + _B.x*p.y + _T.x*p.z + p.t * c.x;
        r.y = _N.y*p.x + _B.y*p.y + _T.y*p.z + p.t * c.y;
        r.z = _N.z*p.x + _B.z*p.y + _T.z*p.z + p.t * c.z;

        r = r + center;

        return r;
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

