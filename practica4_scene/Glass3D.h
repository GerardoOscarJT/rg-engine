//---------------------------------------------------------------------------

#ifndef Glass3DH
#define Glass3DH
//---------------------------------------------------------------------------

#include "Revolution3D.h"

class Glass3D {//: public Mesh3D {

public:

        Vertex3D** points;

        Glass3D();
        ~Glass3D();
        void RecalculateMesh();

        String getName();


private:

         Revolution3D *copa;


};


#endif
