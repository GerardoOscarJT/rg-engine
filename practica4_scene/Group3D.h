#ifndef Group3DH
#define Group3DH

#include "Figure3D.h"
#include "Color3D.h"
#include "Group3Delement.h"
#include <list.h>
#include <gl\gl.h>
#include <gl\glu.h>


class Group3D : public Figure3D {
public:

//        list<Figure3D*>* figures;

        Group3D();
        ~Group3D();
//        void addFigure(Figure3D *&f);

        // Extiendo clase Figure3D
        void Repaint();
        String getName();

        list<Figure3D*> * elements;

        Color3D * color;


private:





};



#endif
