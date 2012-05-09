#ifndef Revolution3DH
#define Revolution3DH

#include "Mesh3D.h"
#include "PV3D.h"
#include <list.h>



class Revolution3D : public Mesh3D {
public:
        Revolution3D();
        ~Revolution3D();

        list<PV3D*> *points;

        void RecalculateMesh();

        int n; // Número de pasos de la circunferencia

        AnsiString getName();

private:

        list<PV3D*> *npoints; //nueva lista que contendrá puntos de la bspline

        void RepaintBSpline3(list<PV3D*>*);
        void BSpline3Segment(PV3D* p1, PV3D* p2, PV3D* p3, PV3D* p4, list<PV3D*> *line, bool first);
        bool exist(list<PV3D*>*, PV3D*);


};


#endif
