//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Window.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

        randomize();
        ListBox1->Items->Clear();

        // Test1
        if (testPV3D::test1()) {
                ListBox1->Items->Add("Test 1 OK");
        } else {
                ListBox1->Items->Add("* Test 1 FAILED");
        }

        // Test2
        if (testPV3D::test2()) {
                ListBox1->Items->Add("Test 2 OK");
        } else {
                ListBox1->Items->Add("* Test 2 FAILED");
        }

        // Test3
        if (testPV3D::test3()) {
                ListBox1->Items->Add("Test 3 OK");
        } else {
                ListBox1->Items->Add("* Test 3 FAILED");
        }

        // Test4
        if (testPV3D::test4()) {
                ListBox1->Items->Add("Test 4 OK");
        } else {
                ListBox1->Items->Add("* Test 4 FAILED");
        }

        // Test5
        if (testPV3D::test5()) {
                ListBox1->Items->Add("Test 5 OK");
        } else {
                ListBox1->Items->Add("* Test 5 FAILED");
        }

        // Test6
        if (testPV3D::test6()) {
                ListBox1->Items->Add("Test 6 OK");
        } else {
                ListBox1->Items->Add("* Test 6 FAILED");
        }



}
//---------------------------------------------------------------------------

