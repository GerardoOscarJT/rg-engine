#ifndef EventToggleLightingH
#define EventToggleLightingH
#include "Event.h"

class EventToggleLighting: public Event {
public:
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();



};




#endif
 