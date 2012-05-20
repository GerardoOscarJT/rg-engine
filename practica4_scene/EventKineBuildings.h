#ifndef EventKineBuildingsH
#define EventKineBuildingsH

#include "Event.h"

class EventKineBuildings:public Event {
public:

        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();

};






#endif
