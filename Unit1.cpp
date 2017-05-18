//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <sstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
String mes;
int decode;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Memo1->Lines->Clear();
String Phone;
String Phone1;
String k;
String result;
String result1;
String result2;

if((Edit1->Text=="")||(Edit1->Text=="+"))
{ShowMessage("Вы не указали номер телефона");}
else
{
//Цифры----------------------------------------------------------------------
  int A;
  int i=1;
  char q;
  Phone=Edit1->Text;
	if(Phone[1]=='+')
	 {
		Phone.Delete(1,1);
	 }
	A = Phone.Length();

	k=IntToHex(A,2);

   if(Phone.Length()%2!=0)
   {
   Phone+="F";
   }

	 while(i<Phone.Length())
   {
	q=Phone[i+1];
	Phone[i+1]=Phone[i];
	Phone[i]=q;
	i=i+2;
   }

   Phone1="000100"+k+"91"+Phone;

//Текст----------------------------------------------------------------------
if(Edit3->Text!="")
{
 String str;
 str=Edit3->Text;
 TBytes ucs2;

 ucs2=TEncoding::Unicode->GetBytes(str);
 str="";
for (int i=0; i<ucs2.Length; i=i+2)
 {
   result=result+IntToHex(ucs2[i+1],2)+""+IntToHex(ucs2[i], 2);
 }
 String Len = IntToHex((str.Length())*2, 2);

result2="0008"+Len+result;

}
}
Memo1->Lines->Add(Phone1+result2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
if (Edit1->Text=="")
{
Edit1->Text="+";
Button1->SetFocus();
}
if (Edit1->Text[1]!='+') {
Edit1->Text="+";
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{ Memo2->Lines->Clear();

if((Edit4->Text==""))
{ShowMessage("Вы не ввели PDU-сообщение");}
else
{
String Phone;
String result;

Phone=Edit4->Text;
AnsiString len = Phone.SubString(7, 2);
   std::string hex;
	hex = len.c_str();
	std::istringstream stream(hex);
	stream >> std::hex >> decode;
	Phone=Phone.Delete(1,10);
	Phone=Phone.Delete(decode+4,Phone.Length());
  int i=1;
  result = "";
  while(i<Phone.Length())
  {
	result=result+Phone[i+1]+Phone[i];
	i=i+2;
  }
   Phone=result;
   Phone=Phone.Delete(decode+1,Phone.Length());
Memo2->Lines->Add("+"+Phone);
mes=Edit4->Text;
if (decode%2!=0) {
mes=mes.Delete(1,decode+17);
}
else mes=mes.Delete(1,decode+16);
 String t;
String Str;
String Str1;
for (int i = 1; i <mes.Length(); i+=4) {
Str1=mes.SubString(i,4);

 Str=wchar_t(StrToInt("0x"+Str1));

t=t+""+Str;
Str="";
Str1="";
}
 Memo2->Lines->Add(t);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
  if( Key != 8 && ( (Key < '0' || Key > '9' ) ) ) Key = NULL;
	else if( Key == 8 && Edit1->Text.Length() == 1 && Edit1->Text[1] == '+')
		Key = NULL;

	return;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Edit1->Text = "+";
 Edit2->Text = "";
 Edit3->Text = "";
 Edit4->Text = "";
 Memo1->Lines->Clear();
 Memo2->Lines->Clear();
}

//---------------------------------------------------------------------------
