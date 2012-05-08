#ifndef Camera3DH
#define Camera3DH

#include <gl\gl.h>
#include <gl\glu.h>
#include "PV3D.h"

const double pi = 4*atan(1);

class Camera3D {
public:
        Camera3D();
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

        GLfloat mm[16]; //mm es la matriz de vista nueva
        GLfloat m[16]; //Para guardar la matriz de vista inversa
        double module_xy;

        //int perspective;
        int perspective;
        AnsiString name;

        void roll(double ang);
        void yaw(double ang);
        void pitch(double ang);

        void inicializa(int, int);
        void oblique(PV3D& p);
        void recalculateCamera(int, int);
        void move(PV3D&);
        void alongAxis(int, double);
        void corner();

        //void changeAtrib(int, int, int);


        void zoomIn(bool);
        void zoomOut(bool);

        void xyRotate(bool);
        void zRotate(bool);
        void turnX(bool);
        void turnY(bool);
        //Lo que debería ser turnZ es xyRotate

private:

        void setModelViewMatrix();
        void recalculateCameraAxis();
        void setView1();
        void setView();
        void setProjection(int, int);
        void setM();


};


#endif
