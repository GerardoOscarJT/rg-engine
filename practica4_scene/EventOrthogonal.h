//---------------------------------------------------------------------------

#ifndef EventOrthogonalH
#define EventOrthogonalH

#include "Event.h"
//---------------------------------------------------------------------------

class EventOrthogonal : public Event {

public:
        String getName();

        void top(ViewPort3D *_viewport, Scene3D *_scene);
};

#endif
