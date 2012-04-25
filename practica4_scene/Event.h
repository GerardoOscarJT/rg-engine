#ifndef EventH
#define EventH

#include <list.h>

class Event {
public:
        virtual bool event()=0;
        virtual String getName()=0;
};

#endif
