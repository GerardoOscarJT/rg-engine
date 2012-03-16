#include <vcl.h>
#pragma hdrstop
#include "Group3D.h"
#pragma package(smart_init)




Group3D::Group3D() : Figure3D() {

}


Group3D::~Group3D() {

}



void Group3D::Repaint() {

}


String Group3D::getName() {
        return "Group";
}
