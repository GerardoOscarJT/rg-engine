#ifndef Group3DelementH
#define Group3DelementH

#include "PV3D.h"
#include "Figure3D.h"


class Group3Delement {
public:
        Group3Delement(Figure3D* f);
        ~Group3Delement();

        PV3D *translation;
        PV3D *rotation;
        Figure3D *figure;



private:



};




#endif
 