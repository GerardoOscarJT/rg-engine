#include <vcl.h>
#pragma hdrstop
#include "Box3D.h"
#pragma package(smart_init)


/*
Box3D::Box3D() : Mesh3D() {

}
*/


void Box3D::RecalculateMesh() {
        clearLists();

        double divX = x/divisiones;
        double divY = y/divisiones;
        double divZ = z/divisiones;
        double separacion;

        Vertex3D * v1 = new Vertex3D(x,0,z); vertices->push_back(v1);

        Vertex3D **v12 = new Vertex3D*[divisiones-1];
        separacion = divY;
        for(int i = 1; i < divisiones; i++) {
                v12[i-1] = new Vertex3D(x,i*separacion,z);
                vertices->push_back(v12[i-1]);
        }

        Vertex3D * v2 = new Vertex3D(x,y,z); vertices->push_back(v2);

        Vertex3D **v23 = new Vertex3D*[divisiones-1];
        separacion = divX;
        for(int i = divisiones-2; i >= 0; i--) {
                v23[i] = new Vertex3D((i+1)*separacion,y,z);
                vertices->push_back(v23[i]);
        }

        Vertex3D * v3 = new Vertex3D(0,y,z);vertices->push_back(v3);

        Vertex3D **v34 = new Vertex3D*[divisiones-1];
        separacion = divY;
        for(int i = divisiones-2; i >= 0; i--) {
                v34[i] = new Vertex3D(0,(i+1)*separacion,z);
                vertices->push_back(v34[i]);
        }

        Vertex3D * v4 = new Vertex3D(0,0,z); vertices->push_back(v4);

        Vertex3D **v41 = new Vertex3D*[divisiones-1];
        separacion = divX;
        for(int i = 1; i < divisiones; i++) {
                v41[i-1] = new Vertex3D(i*separacion,0,z);
                vertices->push_back(v41[i-1]);
        }

        Vertex3D * v5 = new Vertex3D(x,0,0); vertices->push_back(v5);

        Vertex3D **v56 = new Vertex3D*[divisiones-1];
        separacion = divY;
        for(int i = 1; i < divisiones; i++) {
                v56[i-1] = new Vertex3D(x,i*separacion,0);
                vertices->push_back(v56[i-1]);
        }

        Vertex3D * v6 = new Vertex3D(x,y,0); vertices->push_back(v6);

        Vertex3D **v67 = new Vertex3D*[divisiones-1];
        separacion = divX; //v[7]->x = 0, v6->x - 0 = v6->x
        for(int i = divisiones-2; i >= 0; i--) {
                v67[i] = new Vertex3D((i+1)*separacion,y,0);
                vertices->push_back(v67[i]);
        }

        Vertex3D * v7 = new Vertex3D(0,y,0);vertices->push_back(v7);

        Vertex3D **v78 = new Vertex3D*[divisiones-1];
        separacion = divY;
        for(int i = divisiones-2; i >= 0; i--) {
                v78[i] = new Vertex3D(0,(i+1)*separacion,0);
                vertices->push_back(v78[i]);
        }

        Vertex3D * v8 = new Vertex3D(0,0,0); vertices->push_back(v8);

        Vertex3D **v85 = new Vertex3D*[divisiones-1];
        separacion = divX;
        for(int i = 1; i < divisiones; i++) {
                v85[i-1] = new Vertex3D(i*separacion,0,0);
                vertices->push_back(v85[i-1]);
        }

        //División de la dimensión z
        Vertex3D **v51 = new Vertex3D*[divisiones-1];
        separacion = divZ;
        for(int i = divisiones-2; i >= 0; i--) {
                v51[i] = new Vertex3D(x,0,(i+1)*separacion);
                vertices->push_back(v51[i]);
        }

        Vertex3D **v62 = new Vertex3D*[divisiones-1];
        separacion = divZ;
        for(int i = divisiones-2; i >= 0; i--) {
                v62[i] = new Vertex3D(x,y,(i+1)*separacion);
                vertices->push_back(v62[i]);
        }

        Vertex3D **v73 = new Vertex3D*[divisiones-1];
        separacion = divZ;
        for(int i = divisiones-2; i >= 0; i--) {
                v73[i] = new Vertex3D(0,y,(i+1)*separacion);
                vertices->push_back(v73[i]);
        }

        Vertex3D **v84 = new Vertex3D*[divisiones-1];
        separacion = divZ;
        for(int i = divisiones-2; i >= 0; i--) {
                v84[i] = new Vertex3D(0,0,(i+1)*separacion);
                vertices->push_back(v84[i]);
        }



        //------------Caras Laterales Derechas-------------------------------
        //Genero los vértices intermedios de la cara por filas
        double espacioDerY = divY;
        double espacioDerZ = divZ;
        double posDerZ = 0;
        Vertex3D ***mDerAux;
        mDerAux = new Vertex3D**[divisiones-1];
        for(int i = 0; i < divisiones-1; i++) {
                mDerAux[i] = new Vertex3D*[divisiones-1];
                posDerZ += espacioDerZ;
                double posDerY = 0;
                for(int j = 0; j < divisiones-1; j++) {
                        posDerY += espacioDerY;
                        mDerAux[i][j] = new Vertex3D(x, posDerY, posDerZ);
                        vertices->push_back(mDerAux[i][j]);
                }
        }

         //Fila Superior
         Face3D *fDerSupIzq = new Face3D(); faces->push_back(fDerSupIzq);
         fDerSupIzq->normal->x = 1;
         fDerSupIzq->normal->t = 0;
         fDerSupIzq->vertices->push_back(v2);
         fDerSupIzq->vertices->push_back(v12[divisiones-2]);
         fDerSupIzq->vertices->push_back(mDerAux[divisiones-2][divisiones-2]);
         fDerSupIzq->vertices->push_back(v62[divisiones-2]);

         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v12[i+1]);
                f->vertices->push_back(v12[i]);
                f->vertices->push_back(mDerAux[divisiones-2][i]);
                f->vertices->push_back(mDerAux[divisiones-2][i+1]);
         }

         //Columna Derecha
         Face3D *fDerSupDer = new Face3D(); faces->push_back(fDerSupDer);
         fDerSupDer->normal->x = 1;
         fDerSupDer->normal->t = 0;
         fDerSupDer->vertices->push_back(v1);
         fDerSupDer->vertices->push_back(v51[divisiones-2]);
         fDerSupDer->vertices->push_back(mDerAux[divisiones-2][0]);
         fDerSupDer->vertices->push_back(v12[0]);

         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v51[i+1]);
                f->vertices->push_back(v51[i]);
                f->vertices->push_back(mDerAux[i][0]);
                f->vertices->push_back(mDerAux[i+1][0]);
         }

         //Entramado
         for(int i = 0; i < divisiones-2; i++) {
                for(int j = 0; j < divisiones-2; j++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->x = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(mDerAux[i][j]);
                        f->vertices->push_back(mDerAux[i][j+1]);
                        f->vertices->push_back(mDerAux[i+1][j+1]);
                        f->vertices->push_back(mDerAux[i+1][j]);
                }
         }

         //Fila Inferior
         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v56[i]);
                f->vertices->push_back(v56[i+1]);
                f->vertices->push_back(mDerAux[0][i+1]);
                f->vertices->push_back(mDerAux[0][i]);
         }

         Face3D *fDerInfIzq = new Face3D(); faces->push_back(fDerInfIzq);
         fDerInfIzq->normal->x = 1;
         fDerInfIzq->normal->t = 0;
         fDerInfIzq->vertices->push_back(v6);
         fDerInfIzq->vertices->push_back(v62[0]);
         fDerInfIzq->vertices->push_back(mDerAux[0][divisiones-2]);
         fDerInfIzq->vertices->push_back(v56[divisiones-2]);

         //Columna Izquierda
         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v62[i]);
                f->vertices->push_back(v62[i+1]);
                f->vertices->push_back(mDerAux[i+1][divisiones-2]);
                f->vertices->push_back(mDerAux[i][divisiones-2]);
         }

         Face3D *fDerInfDer = new Face3D(); faces->push_back(fDerInfDer);
         fDerInfDer->normal->x = 1;
         fDerInfDer->normal->t = 0;
         fDerInfDer->vertices->push_back(v5);
         fDerInfDer->vertices->push_back(v56[0]);
         fDerInfDer->vertices->push_back(mDerAux[0][0]);
         fDerInfDer->vertices->push_back(v51[0]);


         for(int i = 0; i < divisiones-1; i++) {
                delete[] mDerAux[i];
         }
         delete[] mDerAux;

        //------------Fin Caras Laterales Derechas-------------------------------

        //------------Caras frontales-------------------------------

        //Genero los vértices intermedios de la cara por filas
        double espacioFronX = divX;
        double espacioFronZ = divZ;
        double posFronZ = 0;
        Vertex3D ***mFronAux;
        mFronAux = new Vertex3D**[divisiones-1];
        for(int i = 0; i < divisiones-1; i++) {
                mFronAux[i] = new Vertex3D*[divisiones-1];
                posFronZ += espacioFronZ;
                double posFronX = 0;
                for(int j = 0; j < divisiones-1; j++) {
                        posFronX += espacioFronX;
                        mFronAux[i][j] = new Vertex3D(posFronX, y, posFronZ);
                        vertices->push_back(mFronAux[i][j]);
                }
        }

         //Fila Superior
         Face3D *fFronSupIzq = new Face3D(); faces->push_back(fFronSupIzq);
         fFronSupIzq->normal->y = 1;
         fFronSupIzq->normal->t = 0;
         fFronSupIzq->vertices->push_back(v3);
         fFronSupIzq->vertices->push_back(v23[0]);
         fFronSupIzq->vertices->push_back(mFronAux[divisiones-2][0]);
         fFronSupIzq->vertices->push_back(v73[divisiones-2]);

         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = 1;
                f->normal->t = 0;
                f->vertices->push_back(v23[i]);
                f->vertices->push_back(v23[i+1]);
                f->vertices->push_back(mFronAux[divisiones-2][i+1]);
                f->vertices->push_back(mFronAux[divisiones-2][i]);
         }

         //Columna Derecha
         Face3D *fFronSupDer = new Face3D(); faces->push_back(fFronSupDer);
         fFronSupDer->normal->y = 1;
         fFronSupDer->normal->t = 0;
         fFronSupDer->vertices->push_back(v2);
         fFronSupDer->vertices->push_back(v62[divisiones-2]);
         fFronSupDer->vertices->push_back(mFronAux[divisiones-2][divisiones-2]);
         fFronSupDer->vertices->push_back(v23[divisiones-2]);

         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = 1;
                f->normal->t = 0;
                f->vertices->push_back(v62[i+1]);
                f->vertices->push_back(v62[i]);
                f->vertices->push_back(mFronAux[i][divisiones-2]);
                f->vertices->push_back(mFronAux[i+1][divisiones-2]);
         }

         //Entramado
         for(int i = 0; i < divisiones-2; i++) {
                for(int j = 0; j < divisiones-2; j++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->y = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(mFronAux[i][j]);
                        f->vertices->push_back(mFronAux[i+1][j]);
                        f->vertices->push_back(mFronAux[i+1][j+1]);
                        f->vertices->push_back(mFronAux[i][j+1]);
                }
         }

         //Fila Inferior
         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = 1;
                f->normal->t = 0;
                f->vertices->push_back(v67[i+1]);
                f->vertices->push_back(v67[i]);
                f->vertices->push_back(mFronAux[0][i]);
                f->vertices->push_back(mFronAux[0][i+1]);
         }

         Face3D *fFronInfIzq = new Face3D(); faces->push_back(fFronInfIzq);
         fFronInfIzq->normal->y = 1;
         fFronInfIzq->normal->t = 0;
         fFronInfIzq->vertices->push_back(v7);
         fFronInfIzq->vertices->push_back(v73[0]);
         fFronInfIzq->vertices->push_back(mFronAux[0][0]);
         fFronInfIzq->vertices->push_back(v67[0]);

         //Columna Izquierda
         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = 1;
                f->normal->t = 0;
                f->vertices->push_back(v73[i]);
                f->vertices->push_back(v73[i+1]);
                f->vertices->push_back(mFronAux[i+1][0]);
                f->vertices->push_back(mFronAux[i][0]);
         }

         Face3D *fFronInfDer = new Face3D(); faces->push_back(fFronInfDer);
         fFronInfDer->normal->y = 1;
         fFronInfDer->normal->t = 0;
         fFronInfDer->vertices->push_back(v6);
         fFronInfDer->vertices->push_back(v67[divisiones-2]);
         fFronInfDer->vertices->push_back(mFronAux[0][divisiones-2]);
         fFronInfDer->vertices->push_back(v62[0]);


         for(int i = 0; i < divisiones-1; i++) {
                delete[] mFronAux[i];
         }
         delete[] mFronAux;

        //------------Fin Caras frontales-------------------------------

        //------------Caras Laterales Izquierdas-------------------------------

         //Genero los vértices intermedios de la cara por filas
        double espacioIzqY = divY;
        double espacioIzqZ = divZ;
        double posIzqZ = 0;
        Vertex3D ***mIzqAux;
        mIzqAux = new Vertex3D**[divisiones-1];
        for(int i = 0; i < divisiones-1; i++) {
                mIzqAux[i] = new Vertex3D*[divisiones-1];
                posIzqZ += espacioIzqZ;
                double posIzqY = 0;
                for(int j = 0; j < divisiones-1; j++) {
                        posIzqY += espacioIzqY;
                        mIzqAux[i][j] = new Vertex3D(0, posIzqY, posIzqZ);
                        vertices->push_back(mIzqAux[i][j]);
                }
        }

         //Fila Superior
         Face3D *fIzqSupIzq = new Face3D(); faces->push_back(fIzqSupIzq);
         fIzqSupIzq->normal->x = -1;
         fIzqSupIzq->normal->t = 0;
         fIzqSupIzq->vertices->push_back(v3);
         fIzqSupIzq->vertices->push_back(v34[divisiones-2]);
         fIzqSupIzq->vertices->push_back(mIzqAux[divisiones-2][divisiones-2]);
         fIzqSupIzq->vertices->push_back(v73[divisiones-2]);

         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v34[i+1]);
                f->vertices->push_back(v34[i]);
                f->vertices->push_back(mIzqAux[divisiones-2][i]);
                f->vertices->push_back(mIzqAux[divisiones-2][i+1]);
         }

         //Columna Derecha
         Face3D *fIzqSupDer = new Face3D(); faces->push_back(fIzqSupDer);
         fIzqSupDer->normal->x = -1;
         fIzqSupDer->normal->t = 0;
         fIzqSupDer->vertices->push_back(v4);
         fIzqSupDer->vertices->push_back(v84[divisiones-2]);
         fIzqSupDer->vertices->push_back(mIzqAux[divisiones-2][0]);
         fIzqSupDer->vertices->push_back(v34[0]);

         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v84[i+1]);
                f->vertices->push_back(v84[i]);
                f->vertices->push_back(mIzqAux[i][0]);
                f->vertices->push_back(mIzqAux[i+1][0]);
         }

         //Entramado
         for(int i = 0; i < divisiones-2; i++) {
                for(int j = 0; j < divisiones-2; j++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->x = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(mIzqAux[i][j]);
                        f->vertices->push_back(mIzqAux[i][j+1]);
                        f->vertices->push_back(mIzqAux[i+1][j+1]);
                        f->vertices->push_back(mIzqAux[i+1][j]);
                }
         }

         //Fila Inferior
         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v78[i]);
                f->vertices->push_back(v78[i+1]);
                f->vertices->push_back(mIzqAux[0][i+1]);
                f->vertices->push_back(mIzqAux[0][i]);
         }

         Face3D *fIzqInfIzq = new Face3D(); faces->push_back(fIzqInfIzq);
         fIzqInfIzq->normal->x = -1;
         fIzqInfIzq->normal->t = 0;
         fIzqInfIzq->vertices->push_back(v7);
         fIzqInfIzq->vertices->push_back(v73[0]);
         fIzqInfIzq->vertices->push_back(mIzqAux[0][divisiones-2]);
         fIzqInfIzq->vertices->push_back(v78[divisiones-2]);

         //Columna Izquierda
         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v73[i]);
                f->vertices->push_back(v73[i+1]);
                f->vertices->push_back(mIzqAux[i+1][divisiones-2]);
                f->vertices->push_back(mIzqAux[i][divisiones-2]);
         }

         Face3D *fIzqInfDer = new Face3D(); faces->push_back(fIzqInfDer);
         fIzqInfDer->normal->x = -1;
         fIzqInfDer->normal->t = 0;
         fIzqInfDer->vertices->push_back(v8);
         fIzqInfDer->vertices->push_back(v78[0]);
         fIzqInfDer->vertices->push_back(mIzqAux[0][0]);
         fIzqInfDer->vertices->push_back(v84[0]);


         for(int i = 0; i < divisiones-1; i++) {
                delete[] mIzqAux[i];
         }
         delete[] mIzqAux;

        //------------Fin Caras Laterales Izquierdas-------------------------------

        //------------Cara Posterior-------------------------------

         //Genero los vértices intermedios de la cara por filas
        double espacioPostX = divX;
        double espacioPostZ = divZ;
        double posPostZ = 0;
        Vertex3D ***mPostAux;
        mPostAux = new Vertex3D**[divisiones-1];
        for(int i = 0; i < divisiones-1; i++) {
                mPostAux[i] = new Vertex3D*[divisiones-1];
                posPostZ += espacioPostZ;
                double posPostX = 0;
                for(int j = 0; j < divisiones-1; j++) {
                        posPostX += espacioPostX;
                        mPostAux[i][j] = new Vertex3D(posPostX, 0, posPostZ);
                        vertices->push_back(mPostAux[i][j]);
                }
        }

         //Fila Superior
         Face3D *fPostSupIzq = new Face3D(); faces->push_back(fPostSupIzq);
         fPostSupIzq->normal->y = -1;
         fPostSupIzq->normal->t = 0;
         fPostSupIzq->vertices->push_back(v4);
         fPostSupIzq->vertices->push_back(v41[0]);
         fPostSupIzq->vertices->push_back(mPostAux[divisiones-2][0]);
         fPostSupIzq->vertices->push_back(v84[divisiones-2]);

         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = -1;
                f->normal->t = 0;
                f->vertices->push_back(v41[i]);
                f->vertices->push_back(v41[i+1]);
                f->vertices->push_back(mPostAux[divisiones-2][i+1]);
                f->vertices->push_back(mPostAux[divisiones-2][i]);
         }

         //Columna Derecha
         Face3D *fPostSupDer = new Face3D(); faces->push_back(fPostSupDer);
         fPostSupDer->normal->y = -1;
         fPostSupDer->normal->t = 0;
         fPostSupDer->vertices->push_back(v1);
         fPostSupDer->vertices->push_back(v51[divisiones-2]);
         fPostSupDer->vertices->push_back(mPostAux[divisiones-2][divisiones-2]);
         fPostSupDer->vertices->push_back(v41[divisiones-2]);

         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = -1;
                f->normal->t = 0;
                f->vertices->push_back(v51[i+1]);
                f->vertices->push_back(v51[i]);
                f->vertices->push_back(mPostAux[i][divisiones-2]);
                f->vertices->push_back(mPostAux[i+1][divisiones-2]);
         }

         //Entramado
         for(int i = 0; i < divisiones-2; i++) {
                for(int j = 0; j < divisiones-2; j++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->y = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(mPostAux[i][j]);
                        f->vertices->push_back(mPostAux[i+1][j]);
                        f->vertices->push_back(mPostAux[i+1][j+1]);
                        f->vertices->push_back(mPostAux[i][j+1]);
                }
         }

         //Fila Inferior
         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = -1;
                f->normal->t = 0;
                f->vertices->push_back(v85[i+1]);
                f->vertices->push_back(v85[i]);
                f->vertices->push_back(mPostAux[0][i]);
                f->vertices->push_back(mPostAux[0][i+1]);
         }

         Face3D *fPostInfIzq = new Face3D(); faces->push_back(fPostInfIzq);
         fPostInfIzq->normal->y = -1;
         fPostInfIzq->normal->t = 0;
         fPostInfIzq->vertices->push_back(v8);
         fPostInfIzq->vertices->push_back(v84[0]);
         fPostInfIzq->vertices->push_back(mPostAux[0][0]);
         fPostInfIzq->vertices->push_back(v85[0]);

         //Columna Izquierda
         for(int i = 0; i < divisiones-2; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = -1;
                f->normal->t = 0;
                f->vertices->push_back(v84[i]);
                f->vertices->push_back(v84[i+1]);
                f->vertices->push_back(mPostAux[i+1][0]);
                f->vertices->push_back(mPostAux[i][0]);
         }

         Face3D *fPostInfDer = new Face3D(); faces->push_back(fPostInfDer);
         fPostInfDer->normal->y = -1;
         fPostInfDer->normal->t = 0;
         fPostInfDer->vertices->push_back(v5);
         fPostInfDer->vertices->push_back(v85[divisiones-2]);
         fPostInfDer->vertices->push_back(mPostAux[0][divisiones-2]);
         fPostInfDer->vertices->push_back(v51[0]);


         for(int i = 0; i < divisiones-1; i++) {
                delete[] mPostAux[i];
         }
         delete[] mPostAux;

        //------------Fin Cara Posterior-------------------------------

        //------------Cara Superior-------------------------------

                //Genero los vértices intermedios de la cara por filas
                double espacioY = divY;
                double espacioX = divX;
                double posY = 0;
                Vertex3D ***m1Aux;
                m1Aux = new Vertex3D**[divisiones-1];
                for(int i = 0; i < divisiones-1; i++) {
                        m1Aux[i] = new Vertex3D*[divisiones-1];
                        posY += espacioY;
                        double posX = 0;
                        for(int j = 0; j < divisiones-1; j++) {
                                posX += espacioX;
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

                for(int i = 0; i < divisiones-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(v41[i]);
                        f->vertices->push_back(v41[i+1]);
                        f->vertices->push_back(m1Aux[0][i+1]);
                        f->vertices->push_back(m1Aux[0][i]);
                }

                //Columna Derecha
                Face3D *fSupDer = new Face3D(); faces->push_back(fSupDer);
                fSupDer->normal->z = 1;
                fSupDer->normal->t = 0;
                fSupDer->vertices->push_back(v1);
                fSupDer->vertices->push_back(v12[0]);
                fSupDer->vertices->push_back(m1Aux[0][divisiones-2]);
                fSupDer->vertices->push_back(v41[divisiones-2]);

                for(int i = 0; i < divisiones-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(v12[i]);
                        f->vertices->push_back(v12[i+1]);
                        f->vertices->push_back(m1Aux[i+1][divisiones-2]);
                        f->vertices->push_back(m1Aux[i][divisiones-2]);
                }

                //Entramado
                for(int i = 0; i < divisiones-2; i++) {
                        for(int j = 0; j < divisiones-2; j++) {
                                Face3D *f = new Face3D(); faces->push_back(f);
                                f->normal->z = 1;
                                f->normal->t = 0;
                                f->vertices->push_back(m1Aux[i][j]);
                                f->vertices->push_back(m1Aux[i][j+1]);
                                f->vertices->push_back(m1Aux[i+1][j+1]);
                                f->vertices->push_back(m1Aux[i+1][j]);
                        }
                }

                //Fila Inferior
                for(int i = 0; i < divisiones-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(v23[i+1]);
                        f->vertices->push_back(v23[i]);
                        f->vertices->push_back(m1Aux[divisiones-2][i]);
                        f->vertices->push_back(m1Aux[divisiones-2][i+1]);
                }

                Face3D *fInfIzq = new Face3D(); faces->push_back(fInfIzq);
                fInfIzq->normal->z = 1;
                fInfIzq->normal->t = 0;
                fInfIzq->vertices->push_back(v3);
                fInfIzq->vertices->push_back(v34[divisiones-2]);
                fInfIzq->vertices->push_back(m1Aux[divisiones-2][0]);
                fInfIzq->vertices->push_back(v23[0]);

                //Columna Izquierda
                for(int i = 0; i < divisiones-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(v34[i+1]);
                        f->vertices->push_back(v34[i]);
                        f->vertices->push_back(m1Aux[i][0]);
                        f->vertices->push_back(m1Aux[i+1][0]);
                }

                Face3D *fInfDer = new Face3D(); faces->push_back(fInfDer);
                fInfDer->normal->z = 1;
                fInfDer->normal->t = 0;
                fInfDer->vertices->push_back(v2);
                fInfDer->vertices->push_back(v23[divisiones-2]);
                fInfDer->vertices->push_back(m1Aux[divisiones-2][divisiones-2]);
                fInfDer->vertices->push_back(v12[divisiones-2]);


                for(int i = 0; i < divisiones-1; i++) {
                        delete[] m1Aux[i];
                }
                delete[] m1Aux;

        //------------Fin Cara Superior-------------------------------

        //------------Cara Inferior-------------------------------

                //Genero los vértices intermedios de la cara por filas
                double espacioInfY = divY;
                double espacioInfX = divX;
                double posInfY = 0;
                Vertex3D ***mInfAux;
                mInfAux = new Vertex3D**[divisiones-1];
                for(int i = 0; i < divisiones-1; i++) {
                        mInfAux[i] = new Vertex3D*[divisiones-1];
                        posInfY += espacioInfY;
                        double posInfX = 0;
                        for(int j = 0; j < divisiones-1; j++) {
                                posInfX += espacioInfX;
                                mInfAux[i][j] = new Vertex3D(posInfX, posInfY, 0);
                                vertices->push_back(mInfAux[i][j]);
                        }
                }

                //Fila Superior
                Face3D *fInfSupIzq = new Face3D(); faces->push_back(fInfSupIzq);
                fInfSupIzq->normal->z = -1;
                fInfSupIzq->normal->t = 0;
                fInfSupIzq->vertices->push_back(v8);
                fInfSupIzq->vertices->push_back(v85[0]);
                fInfSupIzq->vertices->push_back(mInfAux[0][0]);
                fInfSupIzq->vertices->push_back(v78[0]);

                for(int i = 0; i < divisiones-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(v85[i]);
                        f->vertices->push_back(v85[i+1]);
                        f->vertices->push_back(mInfAux[0][i+1]);
                        f->vertices->push_back(mInfAux[0][i]);
                }

                //Columna Derecha
                Face3D *fInfSupDer = new Face3D(); faces->push_back(fInfSupDer);
                fInfSupDer->normal->z = -1;
                fInfSupDer->normal->t = 0;
                fInfSupDer->vertices->push_back(v5);
                fInfSupDer->vertices->push_back(v56[0]);
                fInfSupDer->vertices->push_back(mInfAux[0][divisiones-2]);
                fInfSupDer->vertices->push_back(v85[divisiones-2]);

                for(int i = 0; i < divisiones-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(v56[i]);
                        f->vertices->push_back(v56[i+1]);
                        f->vertices->push_back(mInfAux[i+1][divisiones-2]);
                        f->vertices->push_back(mInfAux[i][divisiones-2]);
                }

                //Entramado
                for(int i = 0; i < divisiones-2; i++) {
                        for(int j = 0; j < divisiones-2; j++) {
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
                for(int i = 0; i < divisiones-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(v67[i+1]);
                        f->vertices->push_back(v67[i]);
                        f->vertices->push_back(mInfAux[divisiones-2][i]);
                        f->vertices->push_back(mInfAux[divisiones-2][i+1]);
                }

                Face3D *fInfInfDer = new Face3D(); faces->push_back(fInfInfDer);
                fInfInfDer->normal->z = -1;
                fInfInfDer->normal->t = 0;
                fInfInfDer->vertices->push_back(v6);
                fInfInfDer->vertices->push_back(v67[divisiones-2]);
                fInfInfDer->vertices->push_back(mInfAux[divisiones-2][divisiones-2]);
                fInfInfDer->vertices->push_back(v56[divisiones-2]);

                //Columna Izquierda
                for(int i = 0; i < divisiones-2; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(v78[i+1]);
                        f->vertices->push_back(v78[i]);
                        f->vertices->push_back(mInfAux[i][0]);
                        f->vertices->push_back(mInfAux[i+1][0]);
                }

                Face3D *fInfInfIzq = new Face3D(); faces->push_back(fInfInfIzq);
                fInfInfIzq->normal->z = -1;
                fInfInfIzq->normal->t = 0;
                fInfInfIzq->vertices->push_back(v7);
                fInfInfIzq->vertices->push_back(v78[divisiones-2]);
                fInfInfIzq->vertices->push_back(mInfAux[divisiones-2][0]);
                fInfInfIzq->vertices->push_back(v67[0]);

                for(int i = 0; i < divisiones-1; i++) {
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
