#ifndef Mesh3DH
#define Mesh3DH
#include "Face3D.h"
#include "Figure3D.h"
#include <gl\gl.h>
#include <gl\glu.h>


class Mesh3D : public Figure3D {
public:
        Mesh3D();
        ~Mesh3D();

        Color3D *color;
        int mode;
        list<Vertex3D*>* vertices;
        list<Face3D*>* faces;
        bool showNormals;
        bool filled;

        void RecalculateNormals();
        void drawNormals();

        // Extiendo clase Figure3D
        void Repaint();
        String getName();

protected:
        void clearLists();

private:

};




#endif
 