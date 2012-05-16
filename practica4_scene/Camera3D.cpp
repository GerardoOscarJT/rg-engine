#include <vcl.h>
#pragma hdrstop
#include "Camera3D.h"
#pragma package(smart_init)


Camera3D::Camera3D() {

        look = new PV3D();
        eye = new PV3D();
        up = new PV3D();

}

void Camera3D::inicializa(int width, int height) {

        module_xy = sqrt(pow(eye->x,2)
                                +
                                pow(eye->y,2));

        setView1();

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


        setView();

        perspective = 1;
        setProjection(width, height);
}

Camera3D::~Camera3D() {
        delete look;
        delete eye;
        delete up;

        delete n;
        delete u;
        delete v;
}

void Camera3D::oblique(PV3D& p) {
        glMatrixMode(GL_PROJECTION); 
        glLoadIdentity();
        glOrtho(L, R, B, T, 0, 200000);
        if(p.z != 0 && p != PV3D(0,0,1)) {
                float m[16] =  {1, 0, 0, 0,
                                0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1};
                m[8] = -(p.x/p.z);
                m[9] = -(p.y/p.z);
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

        setModelViewMatrix();
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

        setModelViewMatrix();
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

        setModelViewMatrix();
}

void Camera3D::setModelViewMatrix() {

        PV3D* eyeM = new PV3D();
        *eyeM = *eye - PV3D(0,0,0,1);

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
        
        delete eyeM;

        /*GLfloat c[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, c);
        glLoadMatrixf(m);
        glMultMatrixf(c);
        glGetFloatv(GL_MODELVIEW_MATRIX, c);
        glLoadMatrixf(mm);
        glMultMatrixf(c);
        glGetFloatv(GL_MODELVIEW_MATRIX, c);*/
        setM();

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

void Camera3D::recalculateCameraAxis() {

        //Recalcula los ejes de la cámara
        *n = *eye - *look; n->normalize();
        *u = up->crossProduct(*n); u->normalize();
        *v = n->crossProduct(*u);

}

void Camera3D::setView1() {

/*
        look->x = 0;
        look->y = 0;
        look->z = -1;
*/        

        up->x = 0;
        up->y = 0;
        up->z = 1;
        up->t = 0;

        n = new PV3D();
        u = new PV3D();
        v = new PV3D();
        
        recalculateCameraAxis();

        setM();



}

void Camera3D::setView() {

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    gluLookAt(
        eye->x, eye->y, eye->z,        look->x, look->y, look->z,        up->x, up->y, up->z        );
    GLfloat c[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, c);
    
}

void Camera3D::setProjection(int width, int height) {

    glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
    L = -width/2;
    R = width/2;
    B = -height/2;
    T = height/2;


    if (perspective == 0) {
        glFrustum(L/64,R/64,B/64,T/64,10,20000);
    } else if(perspective == 1){
        glOrtho(L, R, B, T, 0, 200000);
    } else if(perspective == 2) {
        oblique(PV3D(3,1.2,34));
        //oblique(PV3D(0, -0.00294, 2));
    }
}

void Camera3D::recalculateCamera(int width, int height) {
        setProjection(width, height);
        setView();

        glLoadMatrixf(mm);
}

void Camera3D::move(PV3D& del) {
        eye->x += del.x*u->x + del.y*v->x + del.z*n->x;
        eye->y += del.x*u->y + del.y*v->y + del.z*n->y;
        eye->z += del.x*u->z + del.y*v->z + del.z*n->z;


        setModelViewMatrix(); 
}

//void Camera3D::changeAtrib(int atrib, int pos, int value) { //Unusued
        /*
        Explicación de los parámetros:
                * atrib es el atributo. Es 0 para eye, 1 para look y 2 para up
                * pos es la posición dentro del atributo. Es 0 para x, 1 para y y
                2 para z
                * value es el valor a sumar a la posición del atributo
        */
  /*      switch(atrib) {
                case 0: //se trata de eye
                        if(pos == 0) {
                                eye->x += value;
                        }
                        else if(pos == 1) {
                                eye->y += value;
                        }
                        else {
                                eye->z += value;
                        }
                        break;
                case 1: //se trata de look
                        if(pos == 0) {
                                look->x += value;
                        }
                        else if(pos == 1) {
                                look->y += value;
                        }
                        else {
                                look->z += value;
                        }
                        break;
                case 2: //se trata de up
                        if(pos == 0) {
                                up->x += value;
                        }
                        else if(pos == 1) {
                                up->y += value;
                        }
                        else {
                                up->z += value;
                        }
                        break;
        }
        *n = *eye - *look; n->normalize();
        *u = up->crossProduct(*n); u->normalize();
        *v = n->crossProduct(*u); //v->normalize();

        setM();
        setModelViewMatrix();
}   */

void Camera3D::zoomIn(bool select) {

        //Si es true, se corresponde a teclado;
        //si no, es desde ratón

        double zoomFactor;

        select ? zoomFactor = 1.02 : zoomFactor = 1.08;

        eye->x /= zoomFactor;
        eye->y /= zoomFactor;
        eye->z /= zoomFactor;

        setModelViewMatrix();
}

void Camera3D::zoomOut(bool select) {

        //Si select es true, se corresponde a teclado;
        //si no, es desde ratón

        double zoomFactor;

        select ? zoomFactor = 1.02 : zoomFactor = 1.08;

        eye->x *= zoomFactor;
        eye->y *= zoomFactor;
        eye->z *= zoomFactor;

        setModelViewMatrix();
}


void Camera3D::xyRotate(bool select) {

        //Si select es true, suma 0.1
        //Si es false, resta 0.1

        double module_xy = sqrt(pow(eye->x,2)
                                +
                                pow(eye->y,2));
        //double module = look_eye.len();
        double angle = atan2l(
                n->x,
                n->y
                );

        select ? angle += 0.1 : angle -= 0.1;

        eye->x = module_xy*sin(angle);
        eye->y = module_xy*cos(angle);

        recalculateCameraAxis();

        setModelViewMatrix();

}

void Camera3D::zRotate(bool select) {

        //Si select es true, suma 10
        //Si es false, resta 10

        select ? eye->z += 10 : eye->z -= 10;

        recalculateCameraAxis();

        setModelViewMatrix();
}

void Camera3D::alongAxis(int axis, double value) {

        switch(axis) {
                case 0:
                        eye->x += value;
                        break;
                case 1:
                        eye->y += value;
                        break;
                case 2:
                        eye->z += value;
                        break;
        }

        recalculateCameraAxis();

        setModelViewMatrix();

}

void Camera3D::turnX(bool select) {

         //Si select es true, suma 0.1
        //Si es false, resta 0.1

        /*double module_xy = sqrt(pow(eye->x,2)
                                +
                                pow(eye->y,2));*/
        //double module = look_eye.len();
        double angle = atan2l(
                n->z,
                n->y
                );

        select ? angle += 0.1 : angle -= 0.1;

        eye->z = module_xy*sin(angle);
        eye->y = module_xy*cos(angle);

        recalculateCameraAxis();

        setModelViewMatrix();
        
}

void Camera3D::turnY(bool select) {

         //Si select es true, suma 0.1
        //Si es false, resta 0.1

        /*double module_xy = sqrt(pow(eye->x,2)
                                +
                                pow(eye->y,2));*/
        //double module = look_eye.len();
        double angle = atan2l(
                n->z,
                n->x
                );

        select ? angle += 0.1 : angle -= 0.1;

        eye->z = module_xy*sin(angle);
        eye->x = module_xy*cos(angle);

        recalculateCameraAxis();

        setModelViewMatrix();

}

void Camera3D::corner() {
        eye->x = 100;
        eye->y = 100;
        eye->z = 100;

        recalculateCameraAxis();

        setModelViewMatrix();
}

