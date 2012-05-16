#include <vcl.h>
#pragma hdrstop
#include "ViewPort3D.h"
#pragma package(smart_init)

ViewPort3D::ViewPort3D(void * hWnd, int& width, int& height) {
        _width = &width;
        _height = &height;

        _hdc = GetDC(hWnd);

        PIXELFORMATDESCRIPTOR pfd = {
                sizeof(PIXELFORMATDESCRIPTOR),
                1,
                PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
                PFD_TYPE_RGBA,
                32,
                0,0,0,0,0,0,
                0,0,
                0,0,0,0,0,
                32,
                0,
                0,
                PFD_MAIN_PLANE,
                0,
                0,0,0
        };

        pfd.iLayerType = PFD_MAIN_PLANE;

        SetPixelFormat(_hdc, ChoosePixelFormat(_hdc, &pfd), &pfd);        
        _hrc = wglCreateContext(_hdc);

        cameras = new Camera3D*[2];

}

void ViewPort3D::makeCurrent() {
        glEnable(GL_DEPTH_TEST);

        glEnable(GL_FRONT_AND_BACK);


        if(wglMakeCurrent(_hdc, _hrc) == false)
                ShowMessage("Could not make ViewPort3D current :·(");        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);                        }

ViewPort3D::~ViewPort3D() {
        delete cameras;
        wglDeleteContext(_hdc);
}

void ViewPort3D::swapBuffers(){
        SwapBuffers(_hdc);
}

void ViewPort3D::RecalculateViewport() {
        //camera->recalculateCamera();        //projection();        //view();        camera->recalculateCamera(*_width, *_height);        // Puerto de vista        glViewport(0, 0, *_width, *_height);
}

void ViewPort3D::findCoordinates(int scX, int scY, GLint *colores) {

        /*glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();*/

        GLint coords[4];
        glGetIntegerv(GL_VIEWPORT, coords);

        GLdouble mv[16];
        glGetDoublev(GL_MODELVIEW_MATRIX, mv);

        GLdouble pro[16];
        glGetDoublev(GL_PROJECTION_MATRIX, pro);

        int glY = coords[3] - scY;

        //int glZ;
        /*GLdouble glZ = 1;

        glReadPixels(scX, glY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &glZ);*/

        //glFinish();

        /*unsigned char color[3];
        glReadBuffer(GL_FRONT);
        glReadPixels(scX, glY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, colores);*/

        GLfloat pick_col[3];
        glReadBuffer(GL_FRONT);
        glReadPixels(scX , glY , 1 , 1 , GL_RGB , GL_FLOAT , pick_col);

        //GLdouble x,y,z;
        //GLdouble z;

        //GLdouble r1,r2,r3;

        //gluUnProject(scX,glY,0.0,mv,pro,coords,&x,&y,&z);
        //gluUnProject(scX,glY,1.0,mv,pro,coords,&r1,&r2,&r3);

        /*GLdouble nx, ny, nz;
        gluProject(0,0,0,mv,pro,coords,&nx,&ny,&nz);
        ShowMessage("Pantalla: " + AnsiString(nx) + AnsiString(ny) + AnsiString(nz));*/

}

/*
void ViewPort3D::view() {
        glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

        gluLookAt(
                camera->eye->x, camera->eye->y, camera->eye->z,                camera->look->x, camera->look->y, camera->look->z,                camera->up->x, camera->up->y, camera->up->z                );
}

void ViewPort3D::projection() {
        glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
        double L = -*_width/2;
        double R = *_width/2;
        double B = -*_height/2;
        double T = *_height/2;


        if (camera->perspective) {
                glFrustum(L/64,R/64,B/64,T/64,10,20000);
        } else {
                glOrtho(L, R, B, T, 0, 200000);
        }
}
*/
