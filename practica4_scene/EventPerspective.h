#ifndef EventPerspectiveH
#define EventPerspectiveH

#include "Event.h"

class EventPerspective : public Event {

public:
        String getName();
        void top(ViewPort3D *_viewport, Scene3D *_scene);

};

#endif
