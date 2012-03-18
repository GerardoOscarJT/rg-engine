#ifndef FrenetFrameEpitrochoidH
#define FrenetFrameEpitrochoidH

#include "FrenetFrame.h"

class FrenetFrameEpitrochoid : public FrenetFrame {
public:
        double a;
        double b;
        double h;

        FrenetFrameEpitrochoid();


        PV3D C(double theta);
        PV3D C1(double theta);
        PV3D C2(double theta);

private:




};




#endif
