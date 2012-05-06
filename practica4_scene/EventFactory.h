#ifndef EventFactoryH
#define EventFactoryH

#include <list.h>
#include "EventRoll.h"

class EventFactory {
public:
        static Event* createEvent(String);
        static list<String> * getEvents();
};


#endif
