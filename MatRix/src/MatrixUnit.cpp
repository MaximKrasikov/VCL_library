//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MatrixUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
delete_params();//������� �����(��������� ������� � .h)
try{
n=StrToInt(Edit1->Text);  //����� ����� 1� �������
k=StrToInt(Edit2->Text);  //����� �������� 2� �������
n1=StrToInt(Edit3->Text); //����� ����� 2� �������
k1=StrToInt(Edit4->Text); //����� �������� 2� �������
Current = 0;
ProgressBar1->Position = Current;
// ����������� ������ - n * k1
mas = new int*[n];
mas2=new int*[n1]; // ������ � ���� ������� � n � n1 ��������
delete_table();//�������� ������ �����(��������� ������� � .h)
for (int i=0;i<n;i++) mas[i] = new int[k]; // ��������� ������� ������ ��� mas[n][k]
 for (int i = 0; i <n; i++)   // ������������� ������ �������
   {
	   for (int j = 0; j < k; j++)
	   {
		  mas[i][j] = rand()%9+1;// ���������� ��������� ������� ���������� �������
		StringGrid1->Cells[j][i]=mas[i][j];
	   }

	}
 for(int l=0;l<n1;l++) mas2[l]= new int[k1];// ��������� ������� ������ ��� mas2[n1][k1]
 for (int i = 0; i <n1; i++) //������������� ������ �������
   {
	   for (int j = 0; j < k1; j++)
	   {
		  mas2[i][j] = rand()%9+1; // ���������� ��������� ������� ���������� �������
	   StringGrid2->Cells[j][i]=mas2[i][j];
	   }

   }
}
	catch(...){
	 Application->MessageBox(L"������� ���������� ������.",L"��������!",MB_OK);
	}
	if (k!=n1) {
	 Application->MessageBox(L"����� ����� ������ ������� �� ����� ����� �������� ������!",L"��������!",MB_OK);
	}
	  else {
	 ansver = new int*[n];
	 for (int i=0;i<n;i++) ansver[i] = new int[k1]; // ��������� ������ ��� �����

	  }

 //------------------------------//
// �������� ��������� ������ //
   for(int i=0; i < n; i++)
   {
 for(int j=0; j < k1; j++){
 ansver[i][j]=0;
 for(int k=0; k < n1; k++) {
 ansver[i][j]+=mas[i][k]*mas2[k][j];  //��������� ������
  StringGrid3->Cells[j][i]=ansver[i][j]; //����� ������ � �������
 }
	 }
	 Current = 100;                // ����������
ProgressBar1->Position = Current; // ProgressBar'a
	  }

// �������� �� ������������ ������(����)
for (int i=0;i<n;i++) {
delete mas[i]; // �������� i-�� �������� ������� �� mas
delete ansver[i]; // �������� i-�� �������� ������� �� ansver
}
delete []mas;
delete []ansver;
 for (int i=0;i<n1;i++) delete mas2[i]; //�������� i-�� �������� ������� �� mas2
delete []mas2;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//�������� ����� �� �����
void TForm2::delete_params(void)
{
for(int i=0;i<StringGrid1->ColCount;i++)
{
for(int j=0; j<StringGrid1->RowCount;j++)
{
StringGrid1->Cells[i][j] = ""; //������� ����� ������� 1
}
}
for(int i=0;i<StringGrid2->ColCount;i++)
{
for(int j=0; j<StringGrid2->RowCount;j++)
{
StringGrid2->Cells[i][j] = ""; //������� ����� ������� 2
}
}
for(int i=0;i<StringGrid3->ColCount;i++)
{
for(int j=0; j<StringGrid3->RowCount;j++)
{
StringGrid3->Cells[i][j] = ""; //������� ����� ������� ������
}
}
}
//------------------------------------------------------------
//�������� �������� �����
void TForm2::delete_table(void)
{
while (StringGrid1->RowCount>n){
StringGrid1->RowCount-=1;
}
while (StringGrid1->RowCount<=n){
StringGrid1->RowCount+=1;
}
while(StringGrid1->ColCount>k) {
StringGrid1->ColCount-=1;
}
while(StringGrid1->ColCount<=k) {
StringGrid1->ColCount+=1;
}
while (StringGrid2->RowCount>n1){
StringGrid2->RowCount-=1;
}
while (StringGrid2->RowCount<=n1){
StringGrid2->RowCount+=1;
}
while(StringGrid2->ColCount>k1) {
StringGrid2->ColCount-=1;
}
while(StringGrid2->ColCount<=k1) {
StringGrid2->ColCount+=1;
}
while (StringGrid3->RowCount>n){
StringGrid3->RowCount-=1;
}
while (StringGrid3->RowCount<=n){
StringGrid3->RowCount+=1;
}
while(StringGrid3->ColCount>k1) {
StringGrid3->ColCount-=1;
}
while(StringGrid3->ColCount<=k1) {
StringGrid3->ColCount+=1;
}
}
//------------------------------------------------------------

