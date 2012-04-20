#ifndef Camera3DH
#define Camera3DH

#include <gl\gl.h>
#include <gl\glu.h>
#include "PV3D.h"

const double pi = 4*atan(1);

class Camera3D {
public:
        Camera3D(int, int, PV3D&, PV3D&, PV3D&);
        ~Camera3D();

        PV3D* look;
        PV3D* eye;
        PV3D* up;

        PV3D* n;
        PV3D* u;
        PV3D* v;

        float L,R,B,T,N,F; //Volumen de vista
        float fovy;
        float proportion;

        GLfloat m[16]; //Para guardar la matriz de vista inversa

        GLfloat miVM[16]; //mi matriz de MODELVIEW
        GLfloat ordVM[16]; //matriz MODELVIEW de OpenGL

        //int perspective;
        bool perspective;
        AnsiString name;

        void roll(double ang);
        void yaw(double ang);
        void pitch(double ang);

        void oblique(PV3D* p, double, double, double, double);
        void recalculateCamera(int, int);

private:

        void setView1(PV3D& , PV3D& , PV3D& );
        void setView();
        void setProjection(int, int);
        void setModelViewMatrix();
        void setM();


};


#endif
