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

        SetPixelFormat(_hdc, ChoosePixelFormat(_hdc, &pfd), &pfd);
        _hrc = wglCreateContext(_hdc);

}

void ViewPort3D::makeCurrent() {
        if(wglMakeCurrent(_hdc, _hrc) == false)
                ShowMessage("Could not make ViewPort3D current :�(");

ViewPort3D::~ViewPort3D() {
        wglDeleteContext(_hdc);
}

void ViewPort3D::swapBuffers(){
        SwapBuffers(_hdc);
}

void ViewPort3D::RecalculateViewport() {

        glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
        double L = -*_width/2;
        double R = *_width/2;
        double B = -*_height/2;
        double T = *_height/2;


        if (camera->perspective) {
                glFrustum(L/10,R/10,B/10,T/10,10,20000);
        } else {
                glOrtho(L, R, B, T, 0, 200000);
        }

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
        gluLookAt(
                camera->eye->x, camera->eye->y, camera->eye->z,
}