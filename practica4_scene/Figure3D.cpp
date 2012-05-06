#include <vcl.h>
#pragma hdrstop
#include "Figure3D.h"
#pragma package(smart_init)


Figure3D::Figure3D() {
        translation = new PV3D();
        rotation = new PV3D();
        scale = new PV3D(1,1,1,1);

        static int counter = 1;

        counter++;
        human_name = getName() + " " + AnsiString(counter);
}

Figure3D::~Figure3D() {
        delete translation;
        delete rotation;
        delete scale;
}

AnsiString Figure3D::getName() {
        return "Figure";
}

