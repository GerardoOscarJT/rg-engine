//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("EngineRG.res");
USEFORM("Window.cpp", Form1);
USEUNIT("PV3D.cpp");
USEUNIT("testPV3D.cpp");
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
