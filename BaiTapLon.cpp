#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct nhanvien
{
	char ten[255];
	char tinh[255];
	int nam;
	char b[255] ;
};
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_phai();
void ve_tuong_duoi();
void ve_tuong();
void gotoXY(int x, int y);
void SetColor(WORD color);
void Nhap(nhanvien *a, int &n);
void timque(nhanvien *a, int n);
void dem(nhanvien *a, int n);
void Xuat(nhanvien *a,int n);
void sapxep(nhanvien *a, int n);
void outprintf(nhanvien *a,int n,FILE *f);
void menu();
int main()
{
	gotoXY(5,3);
	SetColor(4);
	printf("\t\t\t\t     ---CHUONG TRINH QUAN LY SINH VIÊN---\n\n\n");
	menu();
}
void Nhap(nhanvien *a, int &n)
{
	system("cls");
	for(int i=0;i<n;i++)
	{
	  SetColor(7);
	  fflush(stdin);
	  printf("\n\tNhap ten nhan vien thu %d: ",i+1);
	  gets((a+i)->ten);
	  printf("\n\tNhap tinh: ");
	  gets((a+i)->tinh);
	  printf("\n\tNhap nam sinh: ");
	  scanf("%d",&(a+i)->nam);
	}
	getch();
	system("cls");
}
void timque(nhanvien *a, int n)
{
	system("cls");
	char s[255];
	int k=0;
	SetColor(2);
	printf("\n\tNHAP TINH CAN TIM: ");
	fflush(stdin);
	SetColor(7.);
	gets(s); 
	for(int i=0;i<n;i++){
		if(strcmp(s,(a+i)->tinh)==0){
			SetColor(7);
			printf("Nhan vien thu %d \n %s\t %s\t %d\t\n",i+1, (a+i)->ten,(a+i)->tinh, (a+i)->nam);
			k++;
		}
	}
	if(k==0){
		SetColor(4);
		printf("\t\t\t\tKHONG TIM THAY SINH VIEN\n");
	}
	getch();
	system("cls");
} 
void dem(nhanvien *a, int n){
	for(int i=0;i<n;i++){
		strcpy((a+i)->b,(a+1)->ten);//gia trin chua dc xet
	}
	SetColor(11);
	printf("\n\t\t|TINH THANH   \t    SO LAN| \n");
	for(int i=0;i<n;i++){
		int k=1;
		if(strcmp((a+i)->b,(a+1)->ten)==0){
		strcpy((a+i)->b,(a+2)->ten);
		  for(int j=1+i;j<n;j++){
			if(strcmp((a+i)->tinh,a[j].tinh)==0){
				k++;
				strcpy((a+j)->b,(a+2)->ten);
			}
		}
		SetColor(7);
		printf("\t\t|%s\t    \t%d |\n", (a+i)->tinh , k);
	}
  }
  getch();
  system("cls");
  
}
	

void Xuat(nhanvien *a,int n){
	system("cls");
	SetColor(7);
	printf("\n\t____________THONG TIN NHAN VIEN DA NHAP VAO:_____________\n\n");
	SetColor(2);
	printf("\t|TEN NHAN VIEN \t\tTINH THANH\t\tNAM SINH|");
	for(int i=0;i<n;i++)
	{	SetColor(7);
		printf("\n");
		printf("\t %s\t\t\t%s\t\t     %d",(a+i)->ten , (a+i)->tinh, (a+i)->nam );
	}
	SetColor(7);
	printf("\n\t_________________________________________________________");
}
void sapxep(nhanvien *a, int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp((a+i)->tinh,a[j].tinh)<0){
				nhanvien k = a[i];
				a[i]=a[j];
				a[j]= k ;
			}
		}
	}
}
void outprintf(nhanvien *a,int n,FILE *f){
	getchar();
	char filename[30];
	printf("Nhap ten file: \n");
	gets(filename);
    f= fopen (filename,"ab");
    if(f==NULL){
    	printf("KHONG THE GHI FILE!!!");
    	exit(0);
	}
	fprintf(f,"ho va ten nhan vien la \tque quan nhan vien la \tnam sinh cua nhan vien la \n");
    for(int i=0; i<n;i++){
    	fprintf(f,"\t%s\t\t%s\t\t%d\n",(a+i)->ten,(a+i)->tinh,(a+i)->nam);
	} 
    fclose(f);
}
void menu(){
	int chon, flat=1;
	while(flat==1){
		SetColor(7);
		printf("\t\tMoi ban chon chuc nang:\n\n");
		SetColor(2);
		printf("\t\t1. Nhap du lieu cua tung nhan vien.\n");
		printf("\t\t2. Sap xep, thong kê va hien thi thong tin chi tiet cua tung nhan vien theo tinh.\n");
		printf("\t\t3. Tim nhân vien theo tinh.\n");
		printf("\t\t4. Ghi vao tap tin nhi phan employee.dat.\n");
		printf("\t\t5. Thoat.\n");
		ve_tuong();
		printf("\n\t\t\t ==>  ");
		scanf("%d", &chon);
		switch(chon){
			case 1: 
			    system("cls");
				struct nhanvien *a;
				int n;
				SetColor(2);
				gotoXY(48,9);
				printf ("Nhap so sinh vien: ");
				scanf ("%d", &n);
				a=(nhanvien*)malloc(n*sizeof(nhanvien));
				Nhap(a,n);
				printf("\n\n\n");
				break;
			case 2:
				printf("\nThong tin sinh vien da nhap vao la: \n");
				sapxep(a,n);
				Xuat(a,n);
				printf("\n\n");
				dem(a,n);
				printf("\n\n\n");
				break;
			case 3:
				printf("tim nhan vien theo tinh >>\n");
				timque(a,n);
				printf("\n\n\n");
				break;
			case 4: 
			    FILE *f;
				outprintf(a,n,f);
				system("cls");
				break;
			case 5:
				flat=0;		
		}
	}	
}
void ve_tuong_tren()
{
	int x = 10, y = 1;
	while (x <= 100)
	{
		gotoXY(x, y);
		printf ("*");
		x++;
	}
}
void ve_tuong_duoi()
{
	int x = 10, y = 13;
	while (x <= 100)
	{
		gotoXY(x, y);
		printf ("*");
		x++;
	}
}
void ve_tuong_phai()
{
	int x = 100, y = 1;
	while (y <= 13)
	{
		gotoXY(x, y);
		printf ("*");
		y++;
	}
}
void ve_tuong_trai()
{
	int x = 10, y = 1;
	while (y <= 13)
	{
		gotoXY(x, y);
		printf ("*");
		y++;
	}
}
void ve_tuong()
{
	SetColor(11);
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_phai();
	ve_tuong_trai();
	SetColor(7);
}
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

