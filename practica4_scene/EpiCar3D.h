#ifndef EpiCar3DH
#define EpiCar3DH
#include "Group3D.h"
#include "Cylinder3D.h"
#include "Epitrochoid3D.h"
#include "Box3D.h"



class EpiCar3D : public Group3D {
public:

        EpiCar3D();
        ~EpiCar3D();


        Group3D * car;
        Epitrochoid3D * epi;

        void setTime(double time);
        double getTime();


        Group3D *_wheel1;
        Group3D *_wheel2;
        Group3D *_wheel3;
        Group3D *_wheel4;
        
private:

        double _time;

        Group3D *_wheel;
        Group3D *_chassis;




};






#endif
