#ifndef EventGlassH
#define EventGlassH

#include "Event.h"
#include "Revolution3D.h"

class EventGlass:public Event {

public:
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();



};




#endif
 