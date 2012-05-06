#ifndef EventFactoryH
#define EventFactoryH

#include <list.h>
#include "EventRoll.h"
#include "EventPitch.h"
#include "EventYaw.h"
#include "EventGlass.h"
#include "EventHouse.h"
#include "EventZoom.h"


class EventFactory {
public:
        static Event* createEvent(String);
        static list<String> * getEvents();
};


#endif
