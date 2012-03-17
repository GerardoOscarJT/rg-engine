#include <vcl.h>
#pragma hdrstop
#include "Scene3D.h"
#pragma package(smart_init)



Scene3D::Scene3D() {
        cameras = new list<Camera3D*>();
        viewports = new list<ViewPort3D*>();


        // TODO: Quitar stubs:
        _epi = new Epitrochoid3D();
        _cylinder = new Cylinder3D(150,30,30, false, false);
        _cylinder->RecalculateMesh();

}

Scene3D::~Scene3D() {
        // TODO: Eliminar tambi�n el contenido de las listas
        // (primero viewports y despu�s c�maras):

        list<ViewPort3D*>::iterator it_vp;
        for (it_vp = viewports->begin(); it_vp != viewports->end(); it_vp++)
                delete *it_vp;

        delete viewports;


        list<Camera3D*>::iterator it_c;
        for (it_c = cameras->begin(); it_c != cameras->end(); it_c++)
                delete *it_c;

        delete cameras;

        delete _epi; // TODO: Es un STUB
        delete _cylinder;
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


        /*_epi->Repaint();


        GLUquadric *c = gluNewQuadric();
        gluQuadricDrawStyle(c, GLU_LINE);

        glPushMatrix();
        glTranslatef(0,100,100);

        glColor3f(0.5,0.8,1);
        gluSphere(c, 20, 16, 8);

        glColor3f(0,0.5,0.5);
        gluSphere(c, 60, 16, 8);

        glColor3f(0,0,0.25);
        gluSphere(c, 90, 32, 32);

        glPopMatrix();

        glColor3f(1,1,0);

        glBegin(GL_LINE_STRIP);
                glVertex3f(100,0,0);
                glVertex3f(150,0,0);
                glVertex3f(150,0,50);
                glVertex3f(100,0,50);
                glVertex3f(100,0,0);

        glEnd();

        glBegin(GL_LINE_STRIP);
                glVertex3f(100,50,0);
                glVertex3f(150,50,0);
                glVertex3f(150,50,50);
                glVertex3f(100,50,50);
                glVertex3f(100,50,0);
        glEnd();

        glBegin(GL_LINES);
                glVertex3f(100,0,0);
                glVertex3f(100,50,0);
                glVertex3f(150,0,0);
                glVertex3f(150,50,0);
                glVertex3f(150,0,50);
                glVertex3f(150,50,50);
                glVertex3f(100,0,50);
                glVertex3f(100,50,50);
        glEnd();  */




        _cylinder->Repaint();

        _epi->Repaint();



       /*
        glColor3f(0,0,1);
        _box->x = 100;
        _box->y = 10;
        _box->z = 100;
        _box->RecalculateMesh();
        _box->Repaint();


        glColor3f(1,0,0);
        _box->x = 10;
        _box->y = 100;
        _box->z = 100;
        _box->RecalculateMesh();
        _box->Repaint();


        glColor3f(0,1,0);
        _box->x = 10;
        _box->y = -100;
        _box->z = 100;
        _box->RecalculateMesh();
        _box->Repaint();


        glColor3f(.5,.5,.5);
        _box->x = -100;
        _box->y = 10;
        _box->z = 100;
        _box->RecalculateMesh();
        _box->Repaint();
        */


/*
//        glBegin(GL_LINE_STRIP);
        glBegin(GL_POINTS);

                FrenetFrameEpitrochoid epi;
                PV3D p;

                epi.a = 30;
                epi.b = 10;
                epi.h = 20;
                epi.center.y  = 100;

                int n = 360;
                double pi = 4*atan(1);
                int w = 6; // N�mero de v�rtices del pol�gono
                double r = 5; // Radio del pol�gono

                for (int i=0; i<=n; i++) {
                        double angle = i*2*pi/n;

                        epi.setT(angle);


                        for (int j=0; j<w; j++) {
                                p = epi.transformPoint(PV3D(
                                        r*cos(j*2*pi/w),
                                        r*sin(j*2*pi/w),
                                        0
                                ));
                                glVertex3f(
                                        p.x,
                                        p.y,
                                        p.z
                                );
                        }
                }

        glEnd();
*/        



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
