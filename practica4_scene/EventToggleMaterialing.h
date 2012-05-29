#ifndef EventToggleMaterialingH
#define EventToggleMaterialingH

#include "Event.h"

class EventToggleMaterialing:public Event {
public:
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();

};





#endif
 