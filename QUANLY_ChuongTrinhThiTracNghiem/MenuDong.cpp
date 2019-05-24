
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include "mylib.h"
#include <time.h>
using namespace std;
const int MAXLIST =100;
typedef struct node
{  int info ;
    struct node *next ;
};
typedef struct node *PTR;

const int so_item = 10;
const int dong =2;
const int cot = 2 ;
const int Up = 72;
const int Down = 80;
char thucdon [so_item][50] = {"1. Tao day so ngau nhien    ",
			                  "2. Nhap day tu file         ",
			                  "3. Them ve dau danh sach    ",
			                  "4. Liet ke day so           ",
			                  "5. Xoa cac phan tu bang x   ",
			                  "6. Them so vao ds co thu tu ",
			                  "7. Loc phan tu trung        ",
							  "8. Dao nguoc danh sach      ", 
							  "9. Xoa tren ds co thu tu    ",
							  "10.Ket thuc chuong trinh    "};




void Normal () {
	SetColor(WHITE);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}
int MenuDong(char td [so_item][50]){
  Normal();
  system("cls");   int chon =0;
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  }  // end switch
  } while (1);
}

int Menu (char td [so_item][50]){

  system("cls");   int chon =0;
  int i;
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
Nhaplai:
  gotoxy (cot, dong + so_item);
  cout << "Ban chon 1 so (1..10) :    ";
  gotoxy (wherex()-4, wherey());
  cin >> chon;
  if (chon <1 || chon >so_item) goto Nhaplai;
  return chon;

}
void InsertLast (PTR &First, int x){
  PTR p=new node;	
  p->info = x; 
  p->next=NULL;
  PTR Last ;
  if (First ==NULL ) First=p;
  else {
   for (Last=First; Last->next != NULL; Last =Last->next) ;
   Last->next =p;
  }
}

void DayNgauNhien (PTR &First) {
	int n;
	cout << "So phan tu muon tao :";
	cin >> n;
	srand(time(NULL));
	for (int i =0 ; i <n ;i++)
	  InsertLast(First, (rand() % 20 )+1);
}
void TaoDayTuFile(PTR &First, char *tenfile ){
	FILE *fp;  int n;
	fp=fopen(tenfile,"rt");
	if (fp==NULL) {
		cout << "Loi mo file de doc";		return;
	}
	fscanf(fp,"%d ",&n);	int so;
	for(int i=0; i< n; i++){
		fscanf(fp,"%d ",&so);	InsertLast(First, so);
	}
	fclose(fp);
}

void LietKe(PTR First)
{  for (PTR p = First ; p  != NULL; p = p->next)
      printf( "%d  ",   p->info);
}

int main (){
  PTR First=NULL;	
	
  int chon;  
    while  (1) {
        chon = MenuDong (thucdon);
        switch (chon) {
        
        case 1: DayNgauNhien(First); break;
        case 2: TaoDayTuFile(First, "D:/DAYSO.txt"); break;
		case 4: LietKe(First);
        case so_item  : return 0; 
         }
    }
    return 0;
}
