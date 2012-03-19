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




};


#endif
