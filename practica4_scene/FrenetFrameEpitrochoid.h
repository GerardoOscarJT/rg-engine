#ifndef FrenetFrameEpitrochoidH
#define FrenetFrameEpitrochoidH

#include "FrenetFrame.h"

class FrenetFrameEpitrochoid : public FrenetFrame {
public:
        double a;
        double b;
        double h;
        PV3D center;

        FrenetFrameEpitrochoid();


private:
        PV3D C(double theta);
        PV3D C1(double theta);
        PV3D C2(double theta);





};




#endif
