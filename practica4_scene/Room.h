#ifndef RoomH
#define RoomH

#include "Group3D.h"

class Room : public Group3D {

public:
        Group3D *leftRoom;
        Group3D *rightRoom;

        Room();
        ~Room();

}

#endif
