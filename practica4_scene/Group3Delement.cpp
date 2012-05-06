#include <vcl.h>
#pragma hdrstop
#include "Group3Delement.h"
#pragma package(smart_init)




Group3Delement::Group3Delement(Figure3D* f) {
        rotation = new PV3D(0,0,0);
        translation = new PV3D(0,0,0);
        figure = f;
}


Group3Delement::~Group3Delement() {
        delete translation;
        delete rotation;
}



