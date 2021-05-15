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
	int ma;
	int luong;
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
void xoa_nv(nhanvien *a,int &n);
void them_nv(nhanvien *a, int &n);
void outprintf(nhanvien *a,int n,FILE *f);
void tinhluong(nhanvien *a,int n);
void phanloai(nhanvien *a,int n);
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
	  printf("\n\tNhap ma so nhan vien:");
	  scanf("%d",&(a+i)->ma);
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
			printf("Nhan vien thu %d \n%s\t %s\t %d\t\n",i+1, (a+i)->ten,(a+i)->tinh, (a+i)->nam,(a+i)->ma);
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
	int b[250];
	for(int i=0;i<n;i++){
		b[i] = 1;//gia trin chua dc xet
	}
	SetColor(11);
	printf("\n\t\t|TINH THANH   \t    SO LAN| \n");
	for(int i=0;i<n;i++){
		int k=1;
		if(b[i]==1){
		b[i]=0;
		  for(int j=1+i;j<n;j++){
			if(strcmp((a+i)->tinh,a[j].tinh)==0){
				k++;
				b[j] = 0;
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
	printf("\n\t_________________________________THONG TIN NHAN VIEN DA NHAP VAO:_____________________________________\n\n");
	SetColor(2);
	printf("\t||TEN NHAN VIEN \t\t||TINH THANH\t\t||NAM SINH\t\t||Ma so\n");
	for(int i=0;i<n;i++)
	{	SetColor(7);
		printf("\t %s\t\t\t  %s\t\t  %d\t\t\t  %d\n",(a+i)->ten,(a+i)->tinh,(a+i)->nam,(a+i)->ma);
	}
	SetColor(7);
	printf("\n\t______________________________________________________________________________________________________");
}
void sapxep(nhanvien *a, int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp((a+i)->tinh,(a+j)->tinh)<0){
				nhanvien k = *(a+i);
				*(a+i)=*(a+j);
				*(a+j)= k ;
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
	fprintf(f,"ho va ten nhan vien la \tque quan nhan vien la \tnam sinh cua nhan vien la \the so luong cua nha vien la\tluong nhan vien la\n");
    for(int i=0; i<n;i++){
    	fprintf(f,"\t%s\t\t%s\t\t%d\n",(a+i)->ten,(a+i)->tinh,(a+i)->nam,(a+i)->ma);
	} 
    fclose(f);
}
void tinhluong(nhanvien *a,int n){
	int hsl[255];
	int lcb[255];
	for(int i=0;i<n;i++){
		printf("Nhap he so luong cua %s : ", (a+i)->ten);
		scanf("%d",&hsl[i]);
		printf("Nhap luong co ban cua %s :", (a+i)->ten);
		scanf("%d",&lcb[i]);
		printf("\n");
		}
	printf("\t||Ten nhan vien\t\t\t||Tong luong\n");
	for(int i=0;i<n;i++){
		printf("\t  %s\t\t  %d\n",(a+i)->ten, hsl[i]*lcb[i]);
	}
	getch();
	}
void xoa_nv(nhanvien *a,int &n){
	int d;
	printf("nhap ma so nhan vien can xoa: ");
	scanf("%d", &d);
	for(int i =0; i<n; i++){
		if(d==(a+i)->ma){
			while(i<n){
				a[i]=a[i+1];
				i++;
			}
			n--;
		}
	}
}
void them_nv(nhanvien *a, int &n){
	int g;
	printf("nhap so nhan vien muon them: ");
	scanf("%d", &g);
	for(int i =0 ; i<g;i++){
		nhanvien temp;
	  fflush(stdin);
	  printf("\n\tNhap ten nhan vien: ");
	  gets(temp.ten);
	  printf("\n\tNhap tinh: ");
	  gets(temp.tinh);
	  fflush(stdin);
	  printf("\n\tNhap nam sinh: ");
	  scanf("%d", &temp.nam);
	  printf("\n\tNhap ma so nhan vien: ");
	  scanf("%d", &temp.ma);
	  fflush(stdin);
	  for(int i =n;i>=0;i--)
	  {
	  	 a[i]=a[i-1];
	  }
	a[0]=temp;
	n++;
	}
	
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
		printf("\t\t5. Tinh luong cua tung nhan vien.\n");
		printf("\t\t6. Them, Xoa nhan vien.\n");
		printf("\t\t7. Thoat.\n");
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
				system("cls");
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
				tinhluong(a,n);
				system("cls");
				getch();
				break;
			case 6:
				int r;
			printf("Chon 1 de xoa nhan vien\n");
			printf("Chon 2 de them nhan vien\n");
			scanf("\t%d",&r);
			if(r==1){
				xoa_nv(a,n);
				sapxep(a,n);
				Xuat(a,n);
				getch();
				system("cls");
				printf("\n\n\n");
				break;
			}
			else if(r==2)
			{
				fflush(stdin);
				them_nv(a,n);
				sapxep(a,n);
	            Xuat(a,n);
	            getch();
				system("cls");
				printf("\n\n\n");
				break;
			}
			case 7:
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
	int x = 10, y = 18;
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
	while (y <= 18)
	{
		gotoXY(x, y);
		printf ("*");
		y++;
	}
}
void ve_tuong_trai()
{
	int x = 10, y = 1;
	while (y <= 18)
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

