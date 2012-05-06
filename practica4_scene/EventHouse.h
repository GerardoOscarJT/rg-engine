#ifndef EventHouseH
#define EventHouseH

#include "Event.h"

class EventHouse:public Event {
public:
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();
private:
        Group3D *_house;
};



#endif
 