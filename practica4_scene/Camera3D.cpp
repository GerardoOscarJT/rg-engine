#include <vcl.h>
#pragma hdrstop
#include "Camera3D.h"
#pragma package(smart_init)


Camera3D::Camera3D(int width, int height, PV3D& eye1, PV3D& look1, PV3D& up1) {

        setView1(eye1, look1, up1);
        setView();

        perspective = false;
        //perspective = 1;
        setProjection(width, height);

        //setModelViewMatrix();
}

Camera3D::~Camera3D() {
        delete look;
        delete eye;
        delete up;

        delete n;
        delete u;
        delete v;
}

void Camera3D::oblique(PV3D* p, double L, double R, double B, double T) {
        glMatrixMode(GL_PROJECTION); 
        glLoadIdentity();
        glOrtho(L, R, B, T, 0, 200000);
        if(p->z != 0 && *p != PV3D(0,0,1)) {
                float m[16] =  {1, 0, 0, 0,
                                0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1};
                m[8] = -p->x/p->z;
                m[9] = -p->y/p->z;
                glMultMatrixf(m);
        }

}

void Camera3D::roll(double ang) {
        //ang en grados
        double c = cos((pi/180)*ang);
        double s = sin((pi/180)*ang);
        PV3D t;
        t.x = u->x; t.y = u->y; t.z = u->z;

        u->x = c*t.x + s*v->x;
        u->y = c*t.y + s*v->y;
        u->z = c*t.z + s*v->z;

        v->x = -s*t.x + c*v->x;
        v->y = -s*t.y + c*v->y;
        v->z = -s*t.z + c*v->z;
}

void Camera3D::yaw(double ang) {
        //ang en grados
        double c = cos((pi/180)*ang);
        double s = sin((pi/180)*ang);
        PV3D t;
        t.x = n->x; t.y = n->y; t.z = n->z;

        n->x = c*t.x + s*u->x;
        n->y = c*t.y + s*u->y;
        n->z = c*t.z + s*u->z;

        u->x = c*u->x - s*t.x;
        u->y = c*u->y - s*t.y;
        u->z = c*u->z - s*t.z;

}

void Camera3D::pitch(double ang) {
        //ang en grados
        double c = cos((pi/180)*ang);
        double s = sin((pi/180)*ang);
        PV3D t;
        t.x = v->x; t.y = v->y; t.z = v->z;

        v->x = c*t.x - s*n->x;
        v->y = c*t.y - s*n->y;
        v->z = c*t.z - s*n->z;

        n->x = s*t.x + c*n->x;
        n->y = s*t.y + c*n->y;
        n->z = s*t.z + c*n->z;
}

void Camera3D::setModelViewMatrix() {

        /*glMatrixMode(GL_MODELVIEW);
        GLfloat m[16];

        m[0] = u->x;
        m[1] = v->x;
        m[2] = n->x;
        m[3] = 0;

        m[4] = u->y;
        m[5] = v->y;
        m[6] = n->y;
        m[7] = 0;

        m[8] = u->z;
        m[9] = v->z;
        m[10] = n->z;
        m[11] = 0;

        m[12] = -(eye->dotProduct(*u));
        m[13] = -(eye->dotProduct(*v));
        m[14] = -(eye->dotProduct(*n));
        m[15] = 1;

        glLoadMatrixf(m);*/


        glMatrixMode(GL_MODELVIEW);

        GLfloat mm[16]; //mm es la matriz de vista nueva
        mm[0] = u->x;
        mm[1] = v->x;
        mm[2] = n->x;
        mm[3] = 0;

        mm[4] = u->y;
        mm[5] = v->y;
        mm[6] = n->y;
        mm[7] = 0;

        mm[8] = u->z;
        mm[9] = v->z;
        mm[10] = n->z;
        mm[11] = 0;

        mm[12] = -(eye->dotProduct(*u));
        mm[13] = -(eye->dotProduct(*v));
        mm[14] = -(eye->dotProduct(*n));
        mm[15] = 1;

        GLfloat c[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, c);
        glLoadMatrixf(m);
        glMultMatrixf(c);
        glGetFloatv(GL_MODELVIEW_MATRIX, c);
        glLoadMatrixf(mm);
        glMultMatrixf(c);

}

void Camera3D::setM() {
        m[0] = u->x;
        m[1] = u->y;
        m[2] = u->z;
        m[3] = 0;

        m[4] = v->x;
        m[5] = v->y;
        m[6] = v->z;
        m[7] = 0;

        m[8] = n->x;
        m[9] = n->y;
        m[10] = n->z;
        m[11] = 0;

        m[12] = eye->x;
        m[13] = eye->y;
        m[14] = eye->z;
        m[15] = 1;
}

void Camera3D::setView1(PV3D& eye2, PV3D& look2, PV3D& up2) {

        /*look = new PV3D(0,0,-1);
        eye = new PV3D(0,0,0);
        up = new PV3D(0,0,1,0); // vector*/

        look = new PV3D(look2.x, look2.y, look2.z);
        eye = new PV3D(eye2.x, eye2.y, eye2.z);
        up = new PV3D(up2.x, up2.y, up2.z, 0);

        n = new PV3D();
        u = new PV3D();
        v = new PV3D();
        *n = *eye - *look; n->normalize();
        *u = up->crossProduct(*n); u->normalize();
        *v = n->crossProduct(*u); //v->normalize();

        setM();



}

void Camera3D::setView() {

        glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

        gluLookAt(
                eye->x, eye->y, eye->z,                look->x, look->y, look->z,                up->x, up->y, up->z                );
}

void Camera3D::setProjection(int width, int height) {

        glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
        L = -width/2;
        R = width/2;
        B = -height/2;
        T = height/2;


        if (perspective) {
                glFrustum(L/64,R/64,B/64,T/64,10,20000);
        } else {
                glOrtho(L, R, B, T, 0, 200000);
        }
}

void Camera3D::recalculateCamera(int width, int height) {
        setProjection(width, height);
        setView();
        setModelViewMatrix();
}


