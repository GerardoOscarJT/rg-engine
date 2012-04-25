#include <vcl.h>
#pragma hdrstop
#include "Color3D.h"
#pragma package(smart_init)



Color3D::Color3D() {
        r = 0;
        g = 0;
        b = 0;

}

Color3D::Color3D(double red, double green, double blue) {
        r = red;
        g = green;
        b = blue;
}
