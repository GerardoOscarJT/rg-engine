#ifndef LeftRoomFurnH
#define LeftRoomFurnH

#include "Group3D.h"
#include "Box3D.h"
#include "Cylinder3D.h"
#include "Disk3D.h"
#include "Epitrochoid3D.h"
#include "Revolution3D.h"

class LeftRoomFurn : public Group3D{

public:

        Group3D *table;
        Group3D *chair1;
        Group3D *chair2;
        Group3D *chair3;
        Group3D *chair4;

        Group3D *servilleta1;
        Group3D *servilleta2;
        Group3D *servilleta3;
        Group3D *servilleta4;

        LeftRoomFurn();

private:

        Group3D *_chair;
        Group3D *_napkin;

};

#endif
