//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <stdio.h>
#include <sqlite3.h>
#include "VirtualTrees.hpp"
//---------------------------------------------------------------------------
typedef struct
{
	__int64 id;
	__int64 time;
	char name[256];

} FileStruct;
//---------------------------------------------------------------------------


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
	TVirtualStringTree *VirtualStringTree1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
