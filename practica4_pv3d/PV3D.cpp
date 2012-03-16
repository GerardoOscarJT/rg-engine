#include <vcl.h>
#pragma hdrstop
#include "PV3D.h"
#pragma package(smart_init)



PV3D::PV3D(double Cx, double Cy, double Cz) {
        x = Cx;
        y = Cy;
        z = Cz;
        t = 1; // punto
}

PV3D::PV3D(double Cx, double Cy, double Cz, int type) {
        x = Cx;
        y = Cy;
        z = Cz;
        t = type;
}

double PV3D::len() {
        return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}

void PV3D::normalize() {
        double l = len();
        x/=l;
        y/=l;
        z/=l;
}

PV3D PV3D::operator+(const PV3D &v) {
        return PV3D(x+v.x, y+v.y, z+v.z, t+v.t);
}


/*


PuntoVector3D* PuntoVector3D::add(PuntoVector3D* &v) {
        PuntoVector3D *res;

        //suma de puntos no tiene sentido
        double nx, ny, nz;
        nx = (cx + v->cx);
        ny = (cy + v->cy);
        nz = (cz + v->cz);

        res = new PuntoVector3D(nx, ny, nz, 0);
        return res;
}

PuntoVector3D* PuntoVector3D::sub(PuntoVector3D* &v) {
        PuntoVector3D *res;

        //suma de puntos no tiene sentido
        double nx, ny, nz;
        int nt;
        nx = (cx - v->cx);
        ny = (cy - v->cy);
        nz = (cz - v->cz);
        nt = tipo - v->tipo;

        res = new PuntoVector3D(nx, ny, nz, nt);
        return res;
}

PuntoVector3D* PuntoVector3D::scalarMult(double d) {
        PuntoVector3D *res;

        res = new PuntoVector3D(d*cx, d*cy, d*cz, 0);
}

double PuntoVector3D::dotProduct(PuntoVector3D* &v) {
        double res;

        res = cx*(v->cx) + cy*(v->cy) + cz*(v->cz);
        return res;
}

PuntoVector3D* PuntoVector3D::crossProduct(PuntoVector3D* &v) {
        PuntoVector3D *res;
        double ccx, ccy, ccz;

        ccx = cy*(v->cz) - (cz*(v->cy));
        ccy = cz*(v->cx) - (cx*(v->cz));
        ccz = cx*(v->cy) - (cy*(v->cx));

        res = new PuntoVector3D(ccx, ccy, ccz, 0);
        return res;
}
*/