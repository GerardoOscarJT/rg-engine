//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("EngineRG.res");
USEFORM("Window.cpp", Form1);
USEUNIT("Scene3D.cpp");
USEUNIT("Camera3D.cpp");
USEUNIT("ViewPort3D.cpp");
USEUNIT("PV3D.cpp");
USEUNIT("FrenetFrame.cpp");
USEUNIT("FrenetFrameEpitrochoid.cpp");
USEUNIT("Mesh3D.cpp");
USEUNIT("Face3D.cpp");
USEUNIT("Figure3D.cpp");
USEUNIT("Vertex3D.cpp");
USEUNIT("Color3D.cpp");
USEUNIT("Box3D.cpp");
USEUNIT("Cylinder3D.cpp");
USEUNIT("Epitrochoid3D.cpp");
USEUNIT("Group3D.cpp");
USEUNIT("Group3Delement.cpp");
USEUNIT("EpiCar3D.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
