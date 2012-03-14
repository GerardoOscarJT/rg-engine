#ifndef FrenetFrameH
#define FrenetFrameH

#include "PV3D.h"

class FrenetFrame {
public:
        FrenetFrame();


        PV3D transformPoint(PV3D p);

        void setT(double t);
        double getT();

        PV3D center;


protected:
        virtual PV3D C(double theta) = 0;
        virtual PV3D C1(double theta) = 0;
        virtual PV3D C2(double theta) = 0;

        double _t;

        PV3D _T;
        PV3D _B;
        PV3D _N;

};




#endif
