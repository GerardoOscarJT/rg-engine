#include <vcl.h>
#pragma hdrstop
#include "Box3D.h"
#pragma package(smart_init)



Box3D::Box3D() : Mesh3D() {
        x = 1;
        y = 1;
        z = 1;
        x_div = 2;
        y_div = 2;
        z_div = 2;


        RecalculateMesh();

}

Box3D::~Box3D(){

}

void Box3D::RecalculateMesh() {

        clearLists();

        double divX = x/x_div;
        double divY = y/y_div;
        double divZ = z/z_div;
        double separacion;

        Vertex3D * v1 = new Vertex3D(x,0,z); vertices->push_back(v1);

        Vertex3D **v12 = new Vertex3D*[y_div-1];
        separacion = divY;
        for(int i = 0; i < y_div-1; i++) {
                v12[i] = new Vertex3D(x,(i+1)*separacion,z);
                vertices->push_back(v12[i]);
        }

        Vertex3D * v2 = new Vertex3D(x,y,z); vertices->push_back(v2);

        Vertex3D **v23 = new Vertex3D*[x_div-1];
        separacion = divX;
        for(int i = 0; i < x_div-1; i++) {
                v23[i] = new Vertex3D((i+1)*separacion,y,z);
                vertices->push_back(v23[i]);
        }

        Vertex3D * v3 = new Vertex3D(0,y,z);vertices->push_back(v3);

        Vertex3D **v34 = new Vertex3D*[y_div-1];
        separacion = divY;
        for(int i = 0; i < y_div-1; i++) {
                v34[i] = new Vertex3D(0,(i+1)*separacion,z);
                vertices->push_back(v34[i]);
        }

        Vertex3D * v4 = new Vertex3D(0,0,z); vertices->push_back(v4);

        Vertex3D **v41 = new Vertex3D*[x_div-1];
        separacion = divX;
        for(int i = 0; i < x_div-1; i++) {
                v41[i] = new Vertex3D((i+1)*separacion,0,z);
                vertices->push_back(v41[i]);
        }

        Vertex3D * v5 = new Vertex3D(x,0,0); vertices->push_back(v5);

        Vertex3D **v56 = new Vertex3D*[y_div-1];
        separacion = divY;
        for(int i = 0; i < y_div-1; i++) {
                v56[i] = new Vertex3D(x,(i+1)*separacion,0);
                vertices->push_back(v56[i]);
        }

        Vertex3D * v6 = new Vertex3D(x,y,0); vertices->push_back(v6);

        Vertex3D **v67 = new Vertex3D*[x_div-1];
        separacion = divX; //v[7]->x = 0, v6->x - 0 = v6->x
        for(int i = 0; i < x_div-1; i++) {
                v67[i] = new Vertex3D((i+1)*separacion,y,0);
                vertices->push_back(v67[i]);
        }

        Vertex3D * v7 = new Vertex3D(0,y,0);vertices->push_back(v7);

        Vertex3D **v78 = new Vertex3D*[y_div-1];
        separacion = divY;
        //separacion = divX;
        for(int i = 0; i < y_div-1; i++) {
                v78[i] = new Vertex3D(0,(i+1)*separacion,0);
                //v78[i] = new Vertex3D((i+1)*separacion,0,0);
                vertices->push_back(v78[i]);
        }

        Vertex3D * v8 = new Vertex3D(0,0,0); vertices->push_back(v8);

        Vertex3D **v85 = new Vertex3D*[x_div-1];
        separacion = divX;
        //separacion = divY;
        for(int i = 0; i < x_div-1; i++) {
                v85[i] = new Vertex3D((i+1)*separacion,0,0);
                //v85[i-1] = new Vertex3D(0,i*separacion,0);
                vertices->push_back(v85[i]);
        }

        //Divisi�n de la dimensi�n z
        Vertex3D **v51 = new Vertex3D*[z_div-1];
        separacion = divZ;
        for(int i = 0; i < z_div-1; i++) {
                v51[i] = new Vertex3D(x,0,(i+1)*separacion);
                vertices->push_back(v51[i]);
        }

        Vertex3D **v62 = new Vertex3D*[z_div-1];
        separacion = divZ;
        for(int i = 0; i < z_div-1; i++) {
                v62[i] = new Vertex3D(x,y,(i+1)*separacion);
                vertices->push_back(v62[i]);
        }

        Vertex3D **v73 = new Vertex3D*[z_div-1];
        separacion = divZ;
        for(int i = 0; i < z_div-1; i++) {
                v73[i] = new Vertex3D(0,y,(i+1)*separacion);
                vertices->push_back(v73[i]);
        }

        Vertex3D **v84 = new Vertex3D*[z_div-1];
        separacion = divZ;
        for(int i = 0; i < z_div-1; i++) {
                v84[i] = new Vertex3D(0,0,(i+1)*separacion);
                vertices->push_back(v84[i]);
        }



        //------------Caras Laterales Derechas-------------------------------
        //Genero los v�rtices intermedios de la cara por filas
        double espacioDerX = divX;
        double espacioDerZ = divZ;
        double posDerZ = 0;
        Vertex3D ***mDerAux;
        mDerAux = new Vertex3D**[z_div-1];
        for(int i = 0; i < z_div-1; i++) {
                mDerAux[i] = new Vertex3D*[x_div-1];
                posDerZ = (i+1)*espacioDerZ;
                double posDerX = 0;
                for(int j = 0; j < x_div-1; j++) {
                        posDerX = (j+1)*espacioDerX;
                        mDerAux[i][j] = new Vertex3D(posDerX, y, posDerZ);
                        vertices->push_back(mDerAux[i][j]);
                }
        }

         //Fila Superior
         Face3D *fDerSupIzq = new Face3D(); faces->push_back(fDerSupIzq);
         fDerSupIzq->normal->y = 1;
         fDerSupIzq->normal->t = 0;
         fDerSupIzq->vertices->push_back(v2);
         fDerSupIzq->vertices->push_back(v62[z_div-2]);
         fDerSupIzq->vertices->push_back(mDerAux[z_div-2][x_div-2]);
         fDerSupIzq->vertices->push_back(v23[x_div-2]);

         for(int i = 0; i < x_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = 1;
                f->normal->t = 0;
                f->vertices->push_back(v23[i]);
                f->vertices->push_back(v23[i+1]);
                f->vertices->push_back(mDerAux[z_div-2][i+1]);
                f->vertices->push_back(mDerAux[z_div-2][i]);
         }

         //Columna Derecha
         Face3D *fDerSupDer = new Face3D(); faces->push_back(fDerSupDer);
         fDerSupDer->normal->y = 1;
         fDerSupDer->normal->t = 0;
         fDerSupDer->vertices->push_back(v3);
         fDerSupDer->vertices->push_back(v23[0]);
         fDerSupDer->vertices->push_back(mDerAux[z_div-2][0]);
         fDerSupDer->vertices->push_back(v73[z_div-2]);

         for(int i = 0; i < z_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = 1;
                f->normal->t = 0;
                f->vertices->push_back(v73[i+1]);
                f->vertices->push_back(mDerAux[i+1][0]);
                f->vertices->push_back(mDerAux[i][0]);
                f->vertices->push_back(v73[i]);
         }

         //Entramado
         for(int i = 0; i < z_div-2; i++) {
                for(int j = 0; j < x_div-2; j++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->y = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(mDerAux[i][j]);
                        f->vertices->push_back(mDerAux[i+1][j]);
                        f->vertices->push_back(mDerAux[i+1][j+1]);
                        f->vertices->push_back(mDerAux[i][j+1]);
                }
         }

         //Fila Inferior
         for(int i = 0; i < x_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = 1;
                f->normal->t = 0;
                f->vertices->push_back(v67[i]);
                f->vertices->push_back(mDerAux[0][i]);
                f->vertices->push_back(mDerAux[0][i+1]);
                f->vertices->push_back(v67[i+1]);
         }

         Face3D *fDerInfIzq = new Face3D(); faces->push_back(fDerInfIzq);
         fDerInfIzq->normal->y = 1;
         fDerInfIzq->normal->t = 0;
         fDerInfIzq->vertices->push_back(v6);
         fDerInfIzq->vertices->push_back(v67[x_div-2]);
         fDerInfIzq->vertices->push_back(mDerAux[0][x_div-2]);
         fDerInfIzq->vertices->push_back(v62[0]);

         //Columna Izquierda
         for(int i = 0; i < z_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = 1;
                f->normal->t = 0;
                f->vertices->push_back(v62[i+1]);
                f->vertices->push_back(v62[i]);
                f->vertices->push_back(mDerAux[i][x_div-2]);
                f->vertices->push_back(mDerAux[i+1][x_div-2]);
         }

         Face3D *fDerInfDer = new Face3D(); faces->push_back(fDerInfDer);
         fDerInfDer->normal->y = 1;
         fDerInfDer->normal->t = 0;
         fDerInfDer->vertices->push_back(v7);
         fDerInfDer->vertices->push_back(v73[0]);
         fDerInfDer->vertices->push_back(mDerAux[0][0]);
         fDerInfDer->vertices->push_back(v67[0]);


         for(int i = 0; i < z_div-1; i++) {
                delete[] mDerAux[i];
         }
         delete[] mDerAux;

        //------------Fin Caras Laterales Derechas-------------------------------

        //------------Caras frontales-------------------------------

        //Genero los v�rtices intermedios de la cara por filas
        double espacioFronY = divY;
        double espacioFronZ = divZ;
        double posFronZ = 0;
        Vertex3D ***mFronAux;
        mFronAux = new Vertex3D**[z_div-1];
        for(int i = 0; i < z_div-1; i++) {
                mFronAux[i] = new Vertex3D*[y_div-1];
                posFronZ = (i+1)*espacioFronZ;
                double posFronY = 0;
                for(int j = 0; j < y_div-1; j++) {
                        posFronY = (j+1)*espacioFronY;
                        mFronAux[i][j] = new Vertex3D(x, posFronY, posFronZ);
                        vertices->push_back(mFronAux[i][j]);
                }
        }

         //Fila Superior
         Face3D *fFronSupIzq = new Face3D(); faces->push_back(fFronSupIzq);
         fFronSupIzq->normal->x = 1;
         fFronSupIzq->normal->t = 0;
         fFronSupIzq->vertices->push_back(v1);
         fFronSupIzq->vertices->push_back(v51[z_div-2]);
         fFronSupIzq->vertices->push_back(mFronAux[z_div-2][0]);
         fFronSupIzq->vertices->push_back(v12[0]);

         for(int i = 0; i < y_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v12[i]);
                f->vertices->push_back(mFronAux[z_div-2][i]);
                f->vertices->push_back(mFronAux[z_div-2][i+1]);
                f->vertices->push_back(v12[i+1]);
         }

         //Columna Derecha
         Face3D *fFronSupDer = new Face3D(); faces->push_back(fFronSupDer);
         fFronSupDer->normal->x = 1;
         fFronSupDer->normal->t = 0;
         fFronSupDer->vertices->push_back(v2);
         fFronSupDer->vertices->push_back(v12[y_div-2]);
         fFronSupDer->vertices->push_back(mFronAux[z_div-2][y_div-2]);
         fFronSupDer->vertices->push_back(v62[z_div-2]);

         for(int i = 0; i < z_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v62[i]);
                f->vertices->push_back(v62[i+1]);
                f->vertices->push_back(mFronAux[i+1][y_div-2]);
                f->vertices->push_back(mFronAux[i][y_div-2]);
         }

         //Entramado
         for(int i = 0; i < z_div-2; i++) {
                for(int j = 0; j < y_div-2; j++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->x = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(mFronAux[i][j]);
                        f->vertices->push_back(mFronAux[i][j+1]);
                        f->vertices->push_back(mFronAux[i+1][j+1]);
                        f->vertices->push_back(mFronAux[i+1][j]);
                }
         }

         //Fila Inferior
         for(int i = 0; i < y_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v56[i]);
                f->vertices->push_back(v56[i+1]);
                f->vertices->push_back(mFronAux[0][i+1]);
                f->vertices->push_back(mFronAux[0][i]);
         }

         Face3D *fFronInfIzq = new Face3D(); faces->push_back(fFronInfIzq);
         fFronInfIzq->normal->x = 1;
         fFronInfIzq->normal->t = 0;
         fFronInfIzq->vertices->push_back(v5);
         fFronInfIzq->vertices->push_back(v56[0]);
         fFronInfIzq->vertices->push_back(mFronAux[0][0]);
         fFronInfIzq->vertices->push_back(v51[0]);

         //Columna Izquierda
         for(int i = 0; i < z_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v51[i]);
                f->vertices->push_back(mFronAux[i][0]);
                f->vertices->push_back(mFronAux[i+1][0]);
                f->vertices->push_back(v51[i+1]);
         }

         Face3D *fFronInfDer = new Face3D(); faces->push_back(fFronInfDer);
         fFronInfDer->normal->x = 1;
         fFronInfDer->normal->t = 0;
         fFronInfDer->vertices->push_back(v6);
         fFronInfDer->vertices->push_back(v62[0]);
         fFronInfDer->vertices->push_back(mFronAux[0][y_div-2]);
         fFronInfDer->vertices->push_back(v56[y_div-2]);


         for(int i = 0; i < z_div-1; i++) {
                delete[] mFronAux[i];
         }
         delete[] mFronAux;

        //------------Fin Caras frontales-------------------------------

        //------------Caras Laterales Izquierdas-------------------------------

         //Genero los v�rtices intermedios de la cara por filas
        double espacioIzqX = divX;
        double espacioIzqZ = divZ;
        double posIzqZ = 0;
        Vertex3D ***mIzqAux;
        mIzqAux = new Vertex3D**[z_div-1];
        for(int i = 0; i < z_div-1; i++) {
                mIzqAux[i] = new Vertex3D*[x_div-1];
                posIzqZ = (i+1)*espacioIzqZ;
                double posIzqX = 0;
                for(int j = 0; j < x_div-1; j++) {
                        posIzqX = (j+1)*espacioIzqX;
                        mIzqAux[i][j] = new Vertex3D(posIzqX, 0, posIzqZ);
                        vertices->push_back(mIzqAux[i][j]);
                }
        }

         //Fila Superior
         Face3D *fIzqSupIzq = new Face3D(); faces->push_back(fIzqSupIzq);
         fIzqSupIzq->normal->y = -1;
         fIzqSupIzq->normal->t = 0;
         fIzqSupIzq->vertices->push_back(v1);
         fIzqSupIzq->vertices->push_back(v51[z_div-2]);
         fIzqSupIzq->vertices->push_back(mIzqAux[z_div-2][x_div-2]);
         fIzqSupIzq->vertices->push_back(v41[x_div-2]);

         for(int i = 0; i < x_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = -1;
                f->normal->t = 0;
                f->vertices->push_back(v41[i]);
                f->vertices->push_back(v41[i+1]);
                f->vertices->push_back(mIzqAux[z_div-2][i+1]);
                f->vertices->push_back(mIzqAux[z_div-2][i]);
         }

         //Columna Derecha
         Face3D *fIzqSupDer = new Face3D(); faces->push_back(fIzqSupDer);
         fIzqSupDer->normal->y = -1;
         fIzqSupDer->normal->t = 0;
         fIzqSupDer->vertices->push_back(v4);
         fIzqSupDer->vertices->push_back(v41[0]);
         fIzqSupDer->vertices->push_back(mIzqAux[z_div-2][0]);
         fIzqSupDer->vertices->push_back(v84[z_div-2]);

         for(int i = 0; i < z_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = -1;
                f->normal->t = 0;
                f->vertices->push_back(v84[i]);
                f->vertices->push_back(v84[i+1]);
                f->vertices->push_back(mIzqAux[i+1][0]);
                f->vertices->push_back(mIzqAux[i][0]);
         }

         //Entramado
         for(int i = 0; i < z_div-2; i++) {
                for(int j = 0; j < x_div-2; j++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->y = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(mIzqAux[i][j]);
                        f->vertices->push_back(mIzqAux[i+1][j]);
                        f->vertices->push_back(mIzqAux[i+1][j+1]);
                        f->vertices->push_back(mIzqAux[i][j+1]);
                }
         }

         //Fila Inferior
         for(int i = 0; i < x_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = -1;
                f->normal->t = 0;
                f->vertices->push_back(v85[i]);
                f->vertices->push_back(mIzqAux[0][i]);
                f->vertices->push_back(mIzqAux[0][i+1]);
                f->vertices->push_back(v85[i+1]);
         }

         Face3D *fIzqInfIzq = new Face3D(); faces->push_back(fIzqInfIzq);
         fIzqInfIzq->normal->y = -1;
         fIzqInfIzq->normal->t = 0;
         fIzqInfIzq->vertices->push_back(v5);
         fIzqInfIzq->vertices->push_back(v85[x_div-2]);
         fIzqInfIzq->vertices->push_back(mIzqAux[0][x_div-2]);
         fIzqInfIzq->vertices->push_back(v51[0]);

         //Columna Izquierda
         for(int i = 0; i < z_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = -1;
                f->normal->t = 0;
                f->vertices->push_back(v51[i]);
                f->vertices->push_back(mIzqAux[i][x_div-2]);
                f->vertices->push_back(mIzqAux[i+1][x_div-2]);
                f->vertices->push_back(v51[i+1]);
         }

         Face3D *fIzqInfDer = new Face3D(); faces->push_back(fIzqInfDer);
         fIzqInfDer->normal->y = -1;
         fIzqInfDer->normal->t = 0;
         fIzqInfDer->vertices->push_back(v8);
         fIzqInfDer->vertices->push_back(v84[0]);
         fIzqInfDer->vertices->push_back(mIzqAux[0][0]);
         fIzqInfDer->vertices->push_back(v85[0]);


         for(int i = 0; i < z_div-1; i++) {
                delete[] mIzqAux[i];
         }
         delete[] mIzqAux;

        //------------Fin Caras Laterales Izquierdas-------------------------------

        //------------Cara Posterior-------------------------------

         //Genero los v�rtices intermedios de la cara por filas
        double espacioPostY = divY;
        double espacioPostZ = divZ;
        double posPostZ = 0;
        Vertex3D ***mPostAux;
        mPostAux = new Vertex3D**[z_div-1];
        for(int i = 0; i < z_div-1; i++) {
                mPostAux[i] = new Vertex3D*[y_div-1];
                posPostZ = (i+1)*espacioPostZ;
                double posPostY = 0;
                for(int j = 0; j < y_div-1; j++) {
                        posPostY = (j+1)*espacioPostY;
                        mPostAux[i][j] = new Vertex3D(0, posPostY, posPostZ);
                        vertices->push_back(mPostAux[i][j]);
                }
        }

         //Fila Superior
         Face3D *fPostSupIzq = new Face3D(); faces->push_back(fPostSupIzq);
         fPostSupIzq->normal->x = -1;
         fPostSupIzq->normal->t = 0;
         fPostSupIzq->vertices->push_back(v4);
         fPostSupIzq->vertices->push_back(v84[z_div-2]);
         fPostSupIzq->vertices->push_back(mPostAux[z_div-2][0]);
         fPostSupIzq->vertices->push_back(v34[0]);

         for(int i = 0; i < y_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v34[i]);
                f->vertices->push_back(mPostAux[z_div-2][i]);
                f->vertices->push_back(mPostAux[z_div-2][i+1]);
                f->vertices->push_back(v34[i+1]);
         }

         //Columna Derecha
         Face3D *fPostSupDer = new Face3D(); faces->push_back(fPostSupDer);
         fPostSupDer->normal->x = -1;
         fPostSupDer->normal->t = 0;
         fPostSupDer->vertices->push_back(v3);
         fPostSupDer->vertices->push_back(v34[y_div-2]);
         fPostSupDer->vertices->push_back(mPostAux[z_div-2][y_div-2]);
         fPostSupDer->vertices->push_back(v73[z_div-2]);

         for(int i = 0; i < z_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v73[i]);
                f->vertices->push_back(v73[i+1]);
                f->vertices->push_back(mPostAux[i+1][y_div-2]);
                f->vertices->push_back(mPostAux[i][y_div-2]);
         }

         //Entramado
         for(int i = 0; i < z_div-2; i++) {
                for(int j = 0; j < y_div-2; j++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->x = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(mPostAux[i][j]);
                        f->vertices->push_back(mPostAux[i][j+1]);
                        f->vertices->push_back(mPostAux[i+1][j+1]);
                        f->vertices->push_back(mPostAux[i+1][j]);
                }
         }

         //Fila Inferior
         for(int i = 0; i < y_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v78[i]);
                f->vertices->push_back(v78[i+1]);
                f->vertices->push_back(mPostAux[0][i+1]);
                f->vertices->push_back(mPostAux[0][i]);
         }

         Face3D *fPostInfIzq = new Face3D(); faces->push_back(fPostInfIzq);
         fPostInfIzq->normal->x = -1;
         fPostInfIzq->normal->t = 0;
         fPostInfIzq->vertices->push_back(v8);
         fPostInfIzq->vertices->push_back(v78[0]);
         fPostInfIzq->vertices->push_back(mPostAux[0][0]);
         fPostInfIzq->vertices->push_back(v84[0]);

         //Columna Izquierda
         for(int i = 0; i < z_div-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v84[i]);
                f->vertices->push_back(mPostAux[i][0]);
                f->vertices->push_back(mPostAux[i+1][0]);
                f->vertices->push_back(v84[i+1]);
         }

         Face3D *fPostInfDer = new Face3D(); faces->push_back(fPostInfDer);
         fPostInfDer->normal->x = -1;
         fPostInfDer->normal->t = 0;
         fPostInfDer->vertices->push_back(v7);
         fPostInfDer->vertices->push_back(v73[0]);
         fPostInfDer->vertices->push_back(mPostAux[0][y_div-2]);
         fPostInfDer->vertices->push_back(v78[y_div-2]);


         for(int i = 0; i < z_div-1; i++) {
                delete[] mPostAux[i];
         }
         delete[] mPostAux;

        //------------Fin Cara Posterior-------------------------------

        //------------Cara Superior-------------------------------

                //Genero los v�rtices intermedios de la cara por filas
                double espacioY = divY;
                double espacioX = divX;
                double posX = 0;
                Vertex3D ***m1Aux;
                m1Aux = new Vertex3D**[x_div-1];
                for(int i = 0; i < x_div-1; i++) {
                        m1Aux[i] = new Vertex3D*[y_div-1];
                        posX = (i+1)*espacioX;
                        double posY = 0;
                        for(int j = 0; j < y_div-1; j++) {
                                posY = (j+1)*espacioY;
                                m1Aux[i][j] = new Vertex3D(posX, posY, z);
                                vertices->push_back(m1Aux[i][j]);
                        }
                }

                //Fila Superior
                Face3D *fSupIzq = new Face3D(); faces->push_back(fSupIzq);
                fSupIzq->normal->z = 1;
                fSupIzq->normal->t = 0;
                fSupIzq->vertices->push_back(v4);
                fSupIzq->vertices->push_back(v41[0]);
                fSupIzq->vertices->push_back(m1Aux[0][0]);
                fSupIzq->vertices->push_back(v34[0]);

                for(int i = 0; i < y_div-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(v34[i]);
                        f->vertices->push_back(m1Aux[0][i]);
                        f->vertices->push_back(m1Aux[0][i+1]);
                        f->vertices->push_back(v34[i+1]);
                }

                //Columna Derecha
                Face3D *fSupDer = new Face3D(); faces->push_back(fSupDer);
                fSupDer->normal->z = 1;
                fSupDer->normal->t = 0;
                fSupDer->vertices->push_back(v3);
                fSupDer->vertices->push_back(v34[y_div-2]);
                fSupDer->vertices->push_back(m1Aux[0][y_div-2]);
                fSupDer->vertices->push_back(v23[0]);

                for(int i = 0; i < x_div-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(v23[i]);
                        f->vertices->push_back(m1Aux[i][y_div-2]);
                        f->vertices->push_back(m1Aux[i+1][y_div-2]);
                        f->vertices->push_back(v23[i+1]);
                }

                //Entramado
                for(int i = 0; i < x_div-2; i++) {
                        for(int j = 0; j < y_div-2; j++) {
                                Face3D *f = new Face3D(); faces->push_back(f);
                                f->normal->z = 1;
                                f->normal->t = 0;
                                f->vertices->push_back(m1Aux[i][j]);
                                f->vertices->push_back(m1Aux[i+1][j]);
                                f->vertices->push_back(m1Aux[i+1][j+1]);
                                f->vertices->push_back(m1Aux[i][j+1]);
                        }
                }

                //Fila Inferior
                for(int i = 0; i < y_div-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(v12[i]);
                        f->vertices->push_back(v12[i+1]);
                        f->vertices->push_back(m1Aux[x_div-2][i+1]);
                        f->vertices->push_back(m1Aux[x_div-2][i]);
                }

                Face3D *fInfIzq = new Face3D(); faces->push_back(fInfIzq);
                fInfIzq->normal->z = 1;
                fInfIzq->normal->t = 0;
                fInfIzq->vertices->push_back(v1);
                fInfIzq->vertices->push_back(v12[0]);
                fInfIzq->vertices->push_back(m1Aux[x_div-2][0]);
                fInfIzq->vertices->push_back(v41[x_div-2]);

                //Columna Izquierda
                for(int i = 0; i < x_div-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(v41[i]);
                        f->vertices->push_back(v41[i+1]);
                        f->vertices->push_back(m1Aux[i+1][0]);
                        f->vertices->push_back(m1Aux[i][0]);
                }

                Face3D *fInfDer = new Face3D(); faces->push_back(fInfDer);
                fInfDer->normal->z = 1;
                fInfDer->normal->t = 0;
                fInfDer->vertices->push_back(v2);
                fInfDer->vertices->push_back(v23[x_div-2]);
                fInfDer->vertices->push_back(m1Aux[x_div-2][y_div-2]);
                fInfDer->vertices->push_back(v12[y_div-2]);


                for(int i = 0; i < x_div-1; i++) {
                        delete[] m1Aux[i];
                }
                delete[] m1Aux;

        //------------Fin Cara Superior-------------------------------

        //------------Cara Inferior-------------------------------

                //Genero los v�rtices intermedios de la cara por filas
                double espacioInfY = divY;
                double espacioInfX = divX;
                double posInfX = 0;
                Vertex3D ***mInfAux;
                mInfAux = new Vertex3D**[x_div-1];
                for(int i = 0; i < x_div-1; i++) {
                        mInfAux[i] = new Vertex3D*[y_div-1];
                        posInfX = (i+1)*espacioInfX;
                        double posInfY = 0;
                        for(int j = 0; j < y_div-1; j++) {
                                posInfY = (j+1)*espacioInfY;
                                mInfAux[i][j] = new Vertex3D(posInfX, posInfY, 0);
                                vertices->push_back(mInfAux[i][j]);
                        }
                }

                //Fila Superior
                Face3D *fInfSupIzq = new Face3D(); faces->push_back(fInfSupIzq);
                fInfSupIzq->normal->z = -1;
                fInfSupIzq->normal->t = 0;
                fInfSupIzq->vertices->push_back(v5);
                fInfSupIzq->vertices->push_back(v85[x_div-2]);
                fInfSupIzq->vertices->push_back(mInfAux[x_div-2][0]);
                fInfSupIzq->vertices->push_back(v56[0]);

                for(int i = 0; i < y_div-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(v56[i]);
                        f->vertices->push_back(mInfAux[x_div-2][i]);
                        f->vertices->push_back(mInfAux[x_div-2][i+1]);
                        f->vertices->push_back(v56[i+1]);
                }

                //Columna Derecha
                Face3D *fInfSupDer = new Face3D(); faces->push_back(fInfSupDer);
                fInfSupDer->normal->z = -1;
                fInfSupDer->normal->t = 0;
                fInfSupDer->vertices->push_back(v6);
                fInfSupDer->vertices->push_back(v56[y_div-2]);
                fInfSupDer->vertices->push_back(mInfAux[x_div-2][y_div-2]);
                fInfSupDer->vertices->push_back(v67[x_div-2]);

                for(int i = 0; i < x_div-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(v67[i]);
                        f->vertices->push_back(v67[i+1]);
                        f->vertices->push_back(mInfAux[i+1][y_div-2]);
                        f->vertices->push_back(mInfAux[i][y_div-2]);
                }

                //Entramado
                for(int i = 0; i < x_div-2; i++) {
                        for(int j = 0; j < y_div-2; j++) {
                                Face3D *f = new Face3D(); faces->push_back(f);
                                f->normal->z = -1;
                                f->normal->t = 0;
                                f->vertices->push_back(mInfAux[i][j]);
                                f->vertices->push_back(mInfAux[i][j+1]);
                                f->vertices->push_back(mInfAux[i+1][j+1]);
                                f->vertices->push_back(mInfAux[i+1][j]);
                        }
                }

                //Fila Inferior
                for(int i = 0; i < y_div-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(v78[i]);
                        f->vertices->push_back(v78[i+1]);
                        f->vertices->push_back(mInfAux[0][i+1]);
                        f->vertices->push_back(mInfAux[0][i]);
                }

                Face3D *fInfInfDer = new Face3D(); faces->push_back(fInfInfDer);
                fInfInfDer->normal->z = -1;
                fInfInfDer->normal->t = 0;
                fInfInfDer->vertices->push_back(v7);
                fInfInfDer->vertices->push_back(v67[0]);
                fInfInfDer->vertices->push_back(mInfAux[0][y_div-2]);
                fInfInfDer->vertices->push_back(v78[y_div-2]);

                //Columna Izquierda
                for(int i = 0; i < x_div-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(v85[i+1]);
                        f->vertices->push_back(v85[i]);
                        f->vertices->push_back(mInfAux[i][0]);
                        f->vertices->push_back(mInfAux[i+1][0]);
                }

                Face3D *fInfInfIzq = new Face3D(); faces->push_back(fInfInfIzq);
                fInfInfIzq->normal->z = -1;
                fInfInfIzq->normal->t = 0;
                fInfInfIzq->vertices->push_back(v8);
                fInfInfIzq->vertices->push_back(v78[0]);
                fInfInfIzq->vertices->push_back(mInfAux[0][0]);
                fInfInfIzq->vertices->push_back(v85[0]);

                for(int i = 0; i < x_div-1; i++) {
                        delete[] mInfAux[i];
                }
                delete[] mInfAux; 

        //------------Fin Cara Inferior-------------------------------

        delete[] v84;
        delete[] v73;
        delete[] v62;
        delete[] v51;

        delete[] v85;
        delete[] v78;
        delete[] v67;
        delete[] v56;

        delete[] v41;
        delete[] v34;
        delete[] v23;
        delete[] v12;  


}

AnsiString Box3D::getName() {
        return "Box";
}
