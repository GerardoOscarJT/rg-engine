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
USEUNIT("Revolution3D.cpp");
USEUNIT("Glass3D.cpp");
USEUNIT("Event.cpp");
USEUNIT("EventRoll.cpp");
USEUNIT("EventFactory.cpp");
USEUNIT("LeftRoomFurn.cpp");
USEUNIT("Disk3D.cpp");
USEUNIT("EventGlass.cpp");
USEFORM("Help.cpp", Form2);
USEUNIT("EventPitch.cpp");
USEUNIT("EventYaw.cpp");
USEUNIT("EventHouse.cpp");
USEUNIT("EventZoom.cpp");
USEUNIT("Sphere3D.cpp");
USEUNIT("EventSphere.cpp");
USEUNIT("EventOrthogonal.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
