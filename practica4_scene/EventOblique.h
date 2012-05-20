#ifndef EventObliqueH
#define EventObliqueH

#include "Event.h"

class EventOblique : public Event {

public:
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();

};

#endif
