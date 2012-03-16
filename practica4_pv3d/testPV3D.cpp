#include <vcl.h>
#pragma hdrstop
#include "testPV3D.h"
#pragma package(smart_init)


/**
        Crear un punto. Hay dos tipos de constructoras:
        1) x,y,z y por defecto es un punto
*/
bool testPV3D::test1() {
        double x = rand()/100;
        double y = rand()/100;
        double z = rand()/100;

        PV3D punto(x,y,z);

        return punto.x == x && punto.y == y && punto.z == z && punto.t == 1;
}


/**
        Crear un punto. Hay dos tipos de constructoras:
        2) x,y,z,t  si t=0 es un vector y si t=1 es un punto
*/
bool testPV3D::test2() {
        double x = rand()/100;
        double y = rand()/100;
        double z = rand()/100;
        int t = rand() % 2;

        PV3D punto(x,y,z,t);

        return punto.x == x && punto.y == y && punto.z == z && punto.t == t;
}

/**
        Obtenemos el módulo del vector
*/
bool testPV3D::test3() {
        double x = rand()/100;
        double y = rand()/100;
        double z = rand()/100;

        PV3D punto(x,y,z,0);

        double m = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        double n = punto.len();

        return m == n;
}

/**
        Normaliza el propio vector
*/
bool testPV3D::test4() {
        double x = rand()/100;
        double y = rand()/100;
        double z = rand()/100;

        PV3D punto(x,y,z,0);

        double l = punto.len();
        x/=l;
        y/=l;
        z/=l;

        punto.normalize();

        return punto.x == x && punto.y == y && punto.z == z;
}

/**
        Suma:
                * vector + vector
                * punto + vector
                * vector + punto
*/
bool testPV3D::test5() {
        double x1 = rand()/100;
        double y1 = rand()/100;
        double z1 = rand()/100;

        double x2 = rand()/100;
        double y2 = rand()/100;
        double z2 = rand()/100;

        PV3D punto1(x1,y1,z1,0);
        PV3D punto2(x2,y2,z2,0);
        PV3D punto3(x1,y1,z1,1);
        PV3D punto4(x2,y2,z2,1);

        // dos vectores
        PV3D p5 = punto1 + punto2;
        if (!(p5.x==punto1.x+punto2.x && p5.y==punto1.y+punto2.y &&
                p5.z==punto1.z+punto2.z && p5.t==0 ))
                return false;

        // dos puntos
        PV3D p6 = punto3 + punto4;
        if (!(p6.x==punto3.x+punto4.x && p6.y==punto3.y+punto4.y &&
                p6.z==punto3.z+punto4.z && p6.t!=0 && p6.t!=1 ))
                return false;

        // vector + punto
        PV3D p7 = punto1 + punto3;
        if (!(p7.x==punto1.x+punto3.x && p7.y==punto1.y+punto3.y &&
                p7.z==punto1.z+punto3.z && p7.t==1 ))
                return false;

        // punto + vector
        PV3D p8 = punto3 + punto1;
        if (!(p8.x==punto3.x+punto1.x && p8.y==punto3.y+punto1.y &&
                p8.z==punto3.z+punto1.z && p8.t==1 ))
                return false;

        return true;
}


/**
*/
bool testPV3D::test6() {

        PV3D *p = new PV3D(1,2,3);

        PV3D q(30,20,10);

        PV3D r = q+*p;




        delete p;

        return false;
}


