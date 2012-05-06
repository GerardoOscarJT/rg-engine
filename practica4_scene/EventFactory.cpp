#include <vcl.h>
#pragma hdrstop

#include "EventFactory.h"

Event* EventFactory::createEvent(String name) {
        if (name == "roll")
                return new EventRoll();

        return NULL;
}



list<String>* EventFactory::getEvents() {
        list<String> *registered_events = new list<String>();

        registered_events->push_back("roll");
        registered_events->push_back("zeta");
        registered_events->push_back("abeto");
        registered_events->push_back("aba");
        registered_events->push_back("abedul");
        registered_events->push_back("otro");
        registered_events->push_back("anda");

        registered_events->sort();

        return registered_events;
}

#pragma package(smart_init)
