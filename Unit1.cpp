//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <sqlite3.h>
#pragma hdrstop

using namespace std;

extern "C" {
#include "sqlite3.h"
}

#include "Unit1.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
VirtualStringTree1->NodeDataSize = sizeof(FileStruct);
}
//---------------------------------------------------------------------------

//ñhange smth   ñhange smth   ñhange smth

// branch another here

//right here another

//paint
void __fastcall TForm1::Button1Click(TObject *Sender)
{

	Label2->Caption="            ";
	Label1->Caption="            ";

   //open
   sqlite3* Database;
   int openmsg = sqlite3_open("History",&Database);

   if(openmsg)
   {
		Label2->Caption=sqlite3_errmsg(Database);
   }
   else
   {
		Label2->Caption="Opened database successfully";
   }


   //statement
   char *errmsg;
   sqlite3_stmt *statement;

   int result = sqlite3_prepare_v2(Database,"SELECT id, last_visit_time, url FROM urls",-1,&statement,NULL);

   if(result != SQLITE_OK)
   {
		Label1->Caption=sqlite3_errmsg(Database);
		//(unsigned char*)
   }
   else
   {
		Label1->Caption="Successful request";
   }


   //write it to the tree
   while(true)
	{
		//VirtualStringTree1->BeginUpdate();
		result = sqlite3_step(statement);

		if(result == SQLITE_ROW)
		{
			int n = sqlite3_column_int(statement, 0 /*íîìåð ñòîëáöà*/);
			__int64 m = sqlite3_column_int64(statement, 1);
			unsigned char *str = (unsigned char *)sqlite3_column_text(statement, 2);

			PVirtualNode entryNode = VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);

			FileStruct *nodeData = (FileStruct*)VirtualStringTree1->GetNodeData(entryNode);


			nodeData->id = n;
			nodeData->time = m;
			strcpy(nodeData->name, str);
		}
		else
		{
			//VirtualStringTree1->EndUpdate();
			break;
		}

	 }

	sqlite3_finalize(statement);
	sqlite3_close(Database);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
		  TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
	if(Node == NULL)	return;
	FileStruct *nodeData = (FileStruct*)VirtualStringTree1->GetNodeData(Node);

	switch(Column)
	{
		case 0: CellText = nodeData->id; break;
		case 1: CellText = nodeData->time; break;
		case 2: CellText = nodeData->name; break;
	}



}
//---------------------------------------------------------------------------

//ñhange smth   ñhange smth   ñhange smth

//ñhange smth   ñhange smth   ñhange smth

//delete record

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Label4->Caption="            ";
	Label3->Caption="            ";
	Label2->Caption="            ";
	Label1->Caption="            ";

	sqlite3* Database;
   int openmsg = sqlite3_open("HistoryDel1",&Database);

   if(openmsg)
   {
		Label2->Caption=sqlite3_errmsg(Database);
   }
   else
   {
		Label2->Caption="Opened database successfully";
   }

   //statement
   char *errmsg;
   sqlite3_stmt *statement;

	PVirtualNode entryNode = VirtualStringTree1->GetFirstSelected(false);

	PVirtualNode selectedNode = VirtualStringTree1->FocusedNode;

	wchar_t* query = new wchar_t[1024];
	wchar_t* sql = new wchar_t[1024];

	if(!selectedNode)
	{
	  Label4->Caption="Error!"  ;
	  return;
	}

	FileStruct *nodeData = (FileStruct*)VirtualStringTree1->GetNodeData(selectedNode);
	_itow(nodeData->id,query,10);
	wcscpy(sql,L"DELETE FROM urls WHERE id=");
	wcscat(sql,query);


	VirtualStringTree1->DeleteNode(entryNode);

   FileStruct *selected = (FileStruct*)VirtualStringTree1->GetNodeData(selectedNode);

   int result = sqlite3_prepare16_v2(Database,sql,-1,&statement,NULL);

   if(result != SQLITE_OK)
   {
		Label1->Caption=sqlite3_errmsg(Database);
   }
   else
   {
		Label1->Caption="Successful request";
   }


   //write it to the tree
   while(true)
	{
		result = sqlite3_step(statement);

		if(result != SQLITE_ROW)
		{
		   break;
		}
	}

	Label3->Caption="Successful deleted";

	delete[] query;
	delete[] sql;

	sqlite3_finalize(statement);
	sqlite3_close(Database);

}
//---------------------------------------------------------------------------
//clear

void __fastcall TForm1::Button3Click(TObject *Sender)
{
   	Label3->Caption="            ";
	Label2->Caption="            ";
	Label1->Caption="            ";

	 sqlite3* Database;
   int openmsg = sqlite3_open("HistoryDel",&Database);

   if(openmsg)
   {
		Label2->Caption=sqlite3_errmsg(Database);
   }
   else
   {
		Label2->Caption="Opened database successfully";
   }

   //statement
   char *errmsg;
   sqlite3_stmt *statement;

   int result = sqlite3_prepare_v2(Database,"DELETE FROM urls",-1,&statement,NULL);

   if(result != SQLITE_OK)
   {
		Label1->Caption=sqlite3_errmsg(Database);
   }
   else
   {
		Label1->Caption="Successful request";
   }


   //write it to the tree
   while(true)
	{
		result = sqlite3_step(statement);

		if(result != SQLITE_ROW)
		{
		   break;
		}
	}

	VirtualStringTree1->Clear();

	Label3->Caption="Successful cleared";

	sqlite3_finalize(statement);
	sqlite3_close(Database);
}
//---------------------------------------------------------------------------

