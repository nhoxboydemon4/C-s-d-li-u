void xoa_nv(nhanvien *a,int &n){
	char d[255];
	printf("nhap ten nhan vien can xoa: ");
	fflush(stdin);
	gets(d);
	for(int i =0; i<n; i++){
		if(strcmp(d,(a+i)->ten)==0){
			while(i<n){
				a[i]=a[i+1];
				i++;
			}
		}
		n--;
	}
}
