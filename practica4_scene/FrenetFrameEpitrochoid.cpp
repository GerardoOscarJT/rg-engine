#include <vcl.h>
#pragma hdrstop
#include "FrenetFrameEpitrochoid.h"
#pragma package(smart_init)

FrenetFrameEpitrochoid::FrenetFrameEpitrochoid() {
        
}

PV3D FrenetFrameEpitrochoid::C(double theta) {
        PV3D r(
                (a+b)*cos(theta)-h*cos(theta*(a+b)/b),
                (a+b)*sin(theta)-h*sin(theta*(a+b)/b),
                0
        );
        return r;
}

PV3D FrenetFrameEpitrochoid::C1(double theta) {
        PV3D r(
                -(a+b)*sin(theta)+h*(a+b)*sin(theta*(a+b)/b)/b,
                (a+b)*cos(theta)-h*(a+b)*cos(theta*(a+b)/b)/b,
                0
        );
        return r;
}

PV3D FrenetFrameEpitrochoid::C2(double theta) {
        PV3D r(
                -(a+b)*cos(theta) + h*pow((a+b)/b,2)*cos(theta*(a+b)/b),
                -(a+b)*sin(theta) + h*pow((a+b)/b,2)*sin(theta*(a+b)/b),
                0
        );
        return r;
}

