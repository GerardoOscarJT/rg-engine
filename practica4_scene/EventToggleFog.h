#ifndef EventToggleFogH
#define EventToggleFogH

#include "Event.h"

class EventToggleFog : public Event {
public:
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();


};



#endif
 