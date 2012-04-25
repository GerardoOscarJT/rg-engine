#ifndef EventFactoryH
#define EventFactoryH

#include "EventRoll.h"

class EventFactory {
public:
        static Event* createEvent(String);
        static list<String> getEvents();        
};


#endif
