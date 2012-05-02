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

        Vertex3D * v1 = new Vertex3D(x,0,z); vertices->push_back(v1);

        Vertex3D **v12 = new Vertex3D*[9];
        separacion = y/10;
        for(int i = 1; i < 10; i++) {
                v12[i-1] = new Vertex3D(x,i*separacion,z);
                vertices->push_back(v12[i-1]);
        }

        Vertex3D * v2 = new Vertex3D(x,y,z); vertices->push_back(v2);

        Vertex3D **v23 = new Vertex3D*[9];
        separacion = x/10;
        for(int i = 8; i >= 0; i--) {
                v23[i] = new Vertex3D((i+1)*separacion,y,z);
                vertices->push_back(v23[i]);
        }

        Vertex3D * v3 = new Vertex3D(0,y,z);vertices->push_back(v3);

        Vertex3D **v34 = new Vertex3D*[9];
        separacion = y/10;
        for(int i = 8; i >= 0; i--) {
                v34[i] = new Vertex3D(0,(i+1)*separacion,z);
                vertices->push_back(v34[i]);
        }

        Vertex3D * v4 = new Vertex3D(0,0,z); vertices->push_back(v4);

        Vertex3D **v41 = new Vertex3D*[9];
        separacion = x/10;
        for(int i = 1; i < 10; i++) {
                v41[i-1] = new Vertex3D(i*separacion,0,z);
                vertices->push_back(v41[i-1]);
        }

        Vertex3D * v5 = new Vertex3D(x,0,0); vertices->push_back(v5);

        Vertex3D **v56 = new Vertex3D*[9];
        separacion = y/10;
        for(int i = 1; i < 10; i++) {
                v56[i-1] = new Vertex3D(x,i*separacion,0);
                vertices->push_back(v56[i-1]);
        }

        Vertex3D * v6 = new Vertex3D(x,y,0); vertices->push_back(v6);

        Vertex3D **v67 = new Vertex3D*[9];
        separacion = x/10; //v[7]->x = 0, v6->x - 0 = v6->x
        for(int i = 8; i >= 0; i--) {
                v67[i] = new Vertex3D((i+1)*separacion,y,0);
                vertices->push_back(v67[i]);
        }

        Vertex3D * v7 = new Vertex3D(0,y,0);vertices->push_back(v7);

        Vertex3D **v78 = new Vertex3D*[9];
        separacion = y/10;
        for(int i = 8; i >= 0; i--) {
                v78[i] = new Vertex3D(0,(i+1)*separacion,0);
                vertices->push_back(v78[i]);
        }

        Vertex3D * v8 = new Vertex3D(0,0,0); vertices->push_back(v8);

        Vertex3D **v85 = new Vertex3D*[9];
        separacion = x/10;
        for(int i = 1; i < 10; i++) {
                v85[i-1] = new Vertex3D(i*separacion,0,0);
                vertices->push_back(v85[i-1]);
        }

        //División de la dimensión z
        Vertex3D **v51 = new Vertex3D*[9];
        separacion = z/10;
        for(int i = 8; i >= 0; i--) {
                v51[i] = new Vertex3D(x,0,(i+1)*separacion);
                vertices->push_back(v51[i]);
        }

        Vertex3D **v62 = new Vertex3D*[9];
        separacion = z/10;
        for(int i = 8; i >= 0; i--) {
                v62[i] = new Vertex3D(x,y,(i+1)*separacion);
                vertices->push_back(v62[i]);
        }

        Vertex3D **v73 = new Vertex3D*[9];
        separacion = z/10;
        for(int i = 8; i >= 0; i--) {
                v73[i] = new Vertex3D(0,y,(i+1)*separacion);
                vertices->push_back(v73[i]);
        }

        Vertex3D **v84 = new Vertex3D*[9];
        separacion = z/10;
        for(int i = 8; i >= 0; i--) {
                v84[i] = new Vertex3D(0,0,(i+1)*separacion);
                vertices->push_back(v84[i]);
        }



        //------------Caras Laterales Derechas-------------------------------
        //Genero los vértices intermedios de la cara por filas
        double espacioDerY = y/10;
        double espacioDerZ = z/10;
        double posDerZ = 0;
        Vertex3D ***mDerAux;
        mDerAux = new Vertex3D**[9];
        for(int i = 0; i < 9; i++) {
                mDerAux[i] = new Vertex3D*[9];
                posDerZ += espacioDerZ;
                double posDerY = 0;
                for(int j = 0; j < 9; j++) {
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
         fDerSupIzq->vertices->push_back(v12[8]);
         fDerSupIzq->vertices->push_back(mDerAux[8][8]);
         fDerSupIzq->vertices->push_back(v62[8]);

         for(int i = 0; i < 8; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v12[i+1]);
                f->vertices->push_back(v12[i]);
                f->vertices->push_back(mDerAux[8][i]);
                f->vertices->push_back(mDerAux[8][i+1]);
         }

         //Columna Derecha
         Face3D *fDerSupDer = new Face3D(); faces->push_back(fDerSupDer);
         fDerSupDer->normal->x = 1;
         fDerSupDer->normal->t = 0;
         fDerSupDer->vertices->push_back(v1);
         fDerSupDer->vertices->push_back(v51[8]);
         fDerSupDer->vertices->push_back(mDerAux[8][0]);
         fDerSupDer->vertices->push_back(v12[0]);

         for(int i = 0; i < 8; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v51[i+1]);
                f->vertices->push_back(v51[i]);
                f->vertices->push_back(mDerAux[i][0]);
                f->vertices->push_back(mDerAux[i+1][0]);
         }

         //Entramado
         for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
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
         for(int i = 0; i < 8; i++) {
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
         fDerInfIzq->vertices->push_back(mDerAux[0][8]);
         fDerInfIzq->vertices->push_back(v56[8]);

         //Columna Izquierda
         for(int i = 0; i < 8; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = 1;
                f->normal->t = 0;
                f->vertices->push_back(v62[i]);
                f->vertices->push_back(v62[i+1]);
                f->vertices->push_back(mDerAux[i+1][8]);
                f->vertices->push_back(mDerAux[i][8]);
         }

         Face3D *fDerInfDer = new Face3D(); faces->push_back(fDerInfDer);
         fDerInfDer->normal->x = 1;
         fDerInfDer->normal->t = 0;
         fDerInfDer->vertices->push_back(v5);
         fDerInfDer->vertices->push_back(v56[0]);
         fDerInfDer->vertices->push_back(mDerAux[0][0]);
         fDerInfDer->vertices->push_back(v51[0]);


         for(int i = 0; i < 9; i++) {
                delete[] mDerAux[i];
         }
         delete[] mDerAux;

        //------------Fin Caras Laterales Derechas-------------------------------

        //------------Caras frontales-------------------------------

        //Genero los vértices intermedios de la cara por filas
        double espacioFronX = x/10;
        double espacioFronZ = z/10;
        double posFronZ = 0;
        Vertex3D ***mFronAux;
        mFronAux = new Vertex3D**[9];
        for(int i = 0; i < 9; i++) {
                mFronAux[i] = new Vertex3D*[9];
                posFronZ += espacioFronZ;
                double posFronX = 0;
                for(int j = 0; j < 9; j++) {
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
         fFronSupIzq->vertices->push_back(mFronAux[8][0]);
         fFronSupIzq->vertices->push_back(v73[8]);

         for(int i = 0; i < 8; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = 1;
                f->normal->t = 0;
                f->vertices->push_back(v23[i]);
                f->vertices->push_back(v23[i+1]);
                f->vertices->push_back(mFronAux[8][i+1]);
                f->vertices->push_back(mFronAux[8][i]);
         }

         //Columna Derecha
         Face3D *fFronSupDer = new Face3D(); faces->push_back(fFronSupDer);
         fFronSupDer->normal->y = 1;
         fFronSupDer->normal->t = 0;
         fFronSupDer->vertices->push_back(v2);
         fFronSupDer->vertices->push_back(v62[8]);
         fFronSupDer->vertices->push_back(mFronAux[8][8]);
         fFronSupDer->vertices->push_back(v23[8]);

         for(int i = 0; i < 8; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = 1;
                f->normal->t = 0;
                f->vertices->push_back(v62[i+1]);
                f->vertices->push_back(v62[i]);
                f->vertices->push_back(mFronAux[i][8]);
                f->vertices->push_back(mFronAux[i+1][8]);
         }

         //Entramado
         for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
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
         for(int i = 0; i < 8; i++) {
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
         for(int i = 0; i < 8; i++) {
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
         fFronInfDer->vertices->push_back(v67[8]);
         fFronInfDer->vertices->push_back(mFronAux[0][8]);
         fFronInfDer->vertices->push_back(v62[0]);


         for(int i = 0; i < 9; i++) {
                delete[] mFronAux[i];
         }
         delete[] mFronAux;

        //------------Fin Caras frontales-------------------------------

        //------------Caras Laterales Izquierdas-------------------------------

         //Genero los vértices intermedios de la cara por filas
        double espacioIzqY = y/10;
        double espacioIzqZ = z/10;
        double posIzqZ = 0;
        Vertex3D ***mIzqAux;
        mIzqAux = new Vertex3D**[9];
        for(int i = 0; i < 9; i++) {
                mIzqAux[i] = new Vertex3D*[9];
                posIzqZ += espacioIzqZ;
                double posIzqY = 0;
                for(int j = 0; j < 9; j++) {
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
         fIzqSupIzq->vertices->push_back(v34[8]);
         fIzqSupIzq->vertices->push_back(mIzqAux[8][8]);
         fIzqSupIzq->vertices->push_back(v73[8]);

         for(int i = 0; i < 8; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v34[i+1]);
                f->vertices->push_back(v34[i]);
                f->vertices->push_back(mIzqAux[8][i]);
                f->vertices->push_back(mIzqAux[8][i+1]);
         }

         //Columna Derecha
         Face3D *fIzqSupDer = new Face3D(); faces->push_back(fIzqSupDer);
         fIzqSupDer->normal->x = -1;
         fIzqSupDer->normal->t = 0;
         fIzqSupDer->vertices->push_back(v4);
         fIzqSupDer->vertices->push_back(v84[8]);
         fIzqSupDer->vertices->push_back(mIzqAux[8][0]);
         fIzqSupDer->vertices->push_back(v34[0]);

         for(int i = 0; i < 8; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v84[i+1]);
                f->vertices->push_back(v84[i]);
                f->vertices->push_back(mIzqAux[i][0]);
                f->vertices->push_back(mIzqAux[i+1][0]);
         }

         //Entramado
         for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
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
         for(int i = 0; i < 8; i++) {
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
         fIzqInfIzq->vertices->push_back(mIzqAux[0][8]);
         fIzqInfIzq->vertices->push_back(v78[8]);

         //Columna Izquierda
         for(int i = 0; i < 8; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->x = -1;
                f->normal->t = 0;
                f->vertices->push_back(v73[i]);
                f->vertices->push_back(v73[i+1]);
                f->vertices->push_back(mIzqAux[i+1][8]);
                f->vertices->push_back(mIzqAux[i][8]);
         }

         Face3D *fIzqInfDer = new Face3D(); faces->push_back(fIzqInfDer);
         fIzqInfDer->normal->x = -1;
         fIzqInfDer->normal->t = 0;
         fIzqInfDer->vertices->push_back(v8);
         fIzqInfDer->vertices->push_back(v78[0]);
         fIzqInfDer->vertices->push_back(mIzqAux[0][0]);
         fIzqInfDer->vertices->push_back(v84[0]);


         for(int i = 0; i < 9; i++) {
                delete[] mIzqAux[i];
         }
         delete[] mIzqAux;

        //------------Fin Caras Laterales Izquierdas-------------------------------

        //------------Cara Posterior-------------------------------

         //Genero los vértices intermedios de la cara por filas
        double espacioPostX = x/10;
        double espacioPostZ = z/10;
        double posPostZ = 0;
        Vertex3D ***mPostAux;
        mPostAux = new Vertex3D**[9];
        for(int i = 0; i < 9; i++) {
                mPostAux[i] = new Vertex3D*[9];
                posPostZ += espacioPostZ;
                double posPostX = 0;
                for(int j = 0; j < 9; j++) {
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
         fPostSupIzq->vertices->push_back(mPostAux[8][0]);
         fPostSupIzq->vertices->push_back(v84[8]);

         for(int i = 0; i < 8; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = -1;
                f->normal->t = 0;
                f->vertices->push_back(v41[i]);
                f->vertices->push_back(v41[i+1]);
                f->vertices->push_back(mPostAux[8][i+1]);
                f->vertices->push_back(mPostAux[8][i]);
         }

         //Columna Derecha
         Face3D *fPostSupDer = new Face3D(); faces->push_back(fPostSupDer);
         fPostSupDer->normal->y = -1;
         fPostSupDer->normal->t = 0;
         fPostSupDer->vertices->push_back(v1);
         fPostSupDer->vertices->push_back(v51[8]);
         fPostSupDer->vertices->push_back(mPostAux[8][8]);
         fPostSupDer->vertices->push_back(v41[8]);

         for(int i = 0; i < 8; i++) {
                Face3D *f = new Face3D(); faces->push_back(f);
                f->normal->y = -1;
                f->normal->t = 0;
                f->vertices->push_back(v51[i+1]);
                f->vertices->push_back(v51[i]);
                f->vertices->push_back(mPostAux[i][8]);
                f->vertices->push_back(mPostAux[i+1][8]);
         }

         //Entramado
         for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
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
         for(int i = 0; i < 8; i++) {
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
         for(int i = 0; i < 8; i++) {
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
         fPostInfDer->vertices->push_back(v85[8]);
         fPostInfDer->vertices->push_back(mPostAux[0][8]);
         fPostInfDer->vertices->push_back(v51[0]);


         for(int i = 0; i < 9; i++) {
                delete[] mPostAux[i];
         }
         delete[] mPostAux;

        //------------Fin Cara Posterior-------------------------------

        //------------Cara Superior-------------------------------

                //Genero los vértices intermedios de la cara por filas
                double espacioY = y/10;
                double espacioX = x/10;
                double posY = 0;
                Vertex3D ***m1Aux;
                m1Aux = new Vertex3D**[9];
                for(int i = 0; i < 9; i++) {
                        m1Aux[i] = new Vertex3D*[9];
                        posY += espacioY;
                        double posX = 0;
                        for(int j = 0; j < 9; j++) {
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

                for(int i = 0; i < 8; i++) {
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
                fSupDer->vertices->push_back(m1Aux[0][8]);
                fSupDer->vertices->push_back(v41[8]);

                for(int i = 0; i < 8; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(v12[i]);
                        f->vertices->push_back(v12[i+1]);
                        f->vertices->push_back(m1Aux[i+1][8]);
                        f->vertices->push_back(m1Aux[i][8]);
                }

                //Entramado
                for(int i = 0; i < 8; i++) {
                        for(int j = 0; j < 8; j++) {
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
                for(int i = 0; i < 8; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = 1;
                        f->normal->t = 0;
                        f->vertices->push_back(v23[i+1]);
                        f->vertices->push_back(v23[i]);
                        f->vertices->push_back(m1Aux[8][i]);
                        f->vertices->push_back(m1Aux[8][i+1]);
                }

                Face3D *fInfIzq = new Face3D(); faces->push_back(fInfIzq);
                fInfIzq->normal->z = 1;
                fInfIzq->normal->t = 0;
                fInfIzq->vertices->push_back(v3);
                fInfIzq->vertices->push_back(v34[8]);
                fInfIzq->vertices->push_back(m1Aux[8][0]);
                fInfIzq->vertices->push_back(v23[0]);

                //Columna Izquierda
                for(int i = 0; i < 8; i++) {
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
                fInfDer->vertices->push_back(v23[8]);
                fInfDer->vertices->push_back(m1Aux[8][8]);
                fInfDer->vertices->push_back(v12[8]);


                for(int i = 0; i < 9; i++) {
                        delete[] m1Aux[i];
                }
                delete[] m1Aux;

        //------------Fin Cara Superior-------------------------------

        //------------Cara Inferior-------------------------------

                //Genero los vértices intermedios de la cara por filas
                double espacioInfY = y/10;
                double espacioInfX = x/10;
                double posInfY = 0;
                Vertex3D ***mInfAux;
                mInfAux = new Vertex3D**[9];
                for(int i = 0; i < 9; i++) {
                        mInfAux[i] = new Vertex3D*[9];
                        posInfY += espacioInfY;
                        double posInfX = 0;
                        for(int j = 0; j < 9; j++) {
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

                for(int i = 0; i < 8; i++) {
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
                fInfSupDer->vertices->push_back(mInfAux[0][8]);
                fInfSupDer->vertices->push_back(v85[8]);

                for(int i = 0; i < 8; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(v56[i]);
                        f->vertices->push_back(v56[i+1]);
                        f->vertices->push_back(mInfAux[i+1][8]);
                        f->vertices->push_back(mInfAux[i][8]);
                }

                //Entramado
                for(int i = 0; i < 8; i++) {
                        for(int j = 0; j < 8; j++) {
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
                for(int i = 0; i < 8; i++) {
                        Face3D *f = new Face3D(); faces->push_back(f);
                        f->normal->z = -1;
                        f->normal->t = 0;
                        f->vertices->push_back(v67[i+1]);
                        f->vertices->push_back(v67[i]);
                        f->vertices->push_back(mInfAux[8][i]);
                        f->vertices->push_back(mInfAux[8][i+1]);
                }

                Face3D *fInfInfDer = new Face3D(); faces->push_back(fInfInfDer);
                fInfInfDer->normal->z = -1;
                fInfInfDer->normal->t = 0;
                fInfInfDer->vertices->push_back(v6);
                fInfInfDer->vertices->push_back(v67[8]);
                fInfInfDer->vertices->push_back(mInfAux[8][8]);
                fInfInfDer->vertices->push_back(v56[8]);

                //Columna Izquierda
                for(int i = 0; i < 8; i++) {
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
                fInfInfIzq->vertices->push_back(v78[8]);
                fInfInfIzq->vertices->push_back(mInfAux[8][0]);
                fInfInfIzq->vertices->push_back(v67[0]);

                for(int i = 0; i < 9; i++) {
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
