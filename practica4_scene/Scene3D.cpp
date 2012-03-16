#include <vcl.h>
#pragma hdrstop
#include "Scene3D.h"
#pragma package(smart_init)



Scene3D::Scene3D() {
        cameras = new list<Camera3D*>();
        viewports = new list<ViewPort3D*>();


        // TODO: Quitar stub:
        _epi = new Epitrochoid3D();
        /*
        _epi->a = 150;
        _epi->b = 50;
        _epi->h = 100;
        */
}

Scene3D::~Scene3D() {
        // TODO: Eliminar también el contenido de las listas
        // (primero viewports y después cámaras):
        delete viewports;
        delete cameras;

        delete _epi; // TODO: Es un STUB
}

void Scene3D::Repaint() {
        list<ViewPort3D*>::iterator it;
        ViewPort3D * vp;
        for (it = viewports->begin(); it != viewports->end(); it++) {
                vp = *it;
                RepaintViewPort(vp);
        }
}

void Scene3D::RepaintViewPort(ViewPort3D* vp) {
        vp->makeCurrent();
        vp->RecalculateViewport();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




        glClearColor(0.6,0.7,0.8,1.0);


        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        //Luz0
        glEnable(GL_LIGHT0);
        GLfloat LuzDifusa[]={1.0,1.0,1.0,1.0};
        glLightfv(GL_LIGHT0,GL_DIFFUSE,LuzDifusa);
        GLfloat LuzAmbiente[]={0.3,0.3,0.3,1.0};
        glLightfv(GL_LIGHT0,GL_AMBIENT,LuzAmbiente);
        PosicionLuz0[0]=25.0; PosicionLuz0[1]=25.0;
        PosicionLuz0[2]=0.0; PosicionLuz0[3]=1.0;
        glLightfv(GL_LIGHT0, GL_POSITION, PosicionLuz0);

        glEnable(GL_COLOR_MATERIAL);
        glMaterialf(GL_FRONT, GL_SHININESS, 0.1);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_NORMALIZE);
        glShadeModel(GL_SMOOTH);   //Defecto

        glLightfv(GL_LIGHT0,GL_POSITION,PosicionLuz0);


        DrawAxis();


        _epi->Repaint();



        glFlush();

        vp->swapBuffers();
}


void Scene3D::DrawAxis() {
        glBegin(GL_LINES);
                glColor3f(1,0,0);
                glVertex3f(0,0,0);
                glVertex3f(2000,0,0);

                glColor3f(0,1,0);
                glVertex3f(0,0,0);
                glVertex3f(0,2000,0);

                glColor3f(0,0,1);
                glVertex3f(0,0,0);
                glVertex3f(0,0,2000);

                glColor3f(0.4,0,0);
                glVertex3f(0,0,0);
                glVertex3f(-2000,0,0);

                glColor3f(0,0.4,0);
                glVertex3f(0,0,0);
                glVertex3f(0,-2000,0);

                glColor3f(0,0,0.4);
                glVertex3f(0,0,0);
                glVertex3f(0,0,-2000);

        glEnd();

}
