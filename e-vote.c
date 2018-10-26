#include<stdio.h>
#include<windows.h>


int suma=0;
int sumb=0;
int sumc=0;
int satu = 0,dua = 0,tiga = 0;
void loading();  //memberikan efek loading
void menu();     //memilih menu
void bantuan();  //deskripsi dan informasi penggunaan program
void keluar();   //menghentikan program
void error();    //mengatasi eror
void error2();
int verifikasi();//memverifikasi hak suara sesorang berdasarkan npm yang terdaftar
int pilih();     //melakukan pemilihan

int main()
{
  system("color E0");   //mengatur warna background
  system("cls");
  printf("\n========================================================================================================================"); 
  printf("\n====================================================E-VOTE V1.0========================================================="); //judul program
  printf("\n===================================OLEH: GITA AYU SALSABILA & BAYU SATRIA PERSADA=======================================");
  printf("\n========================================================================================================================");
  menu();
}

void menu(){
    int m;
	printf("\n\nMenu :\n\t1. PILIH\n\t2. BANTUAN\n\t3. KELUAR\n"); //daftar menu
	printf("\n\nPilih Nomor Menu: ");
	scanf("%d",&m);
	
	switch(m){
		case 1:
			loading(); 
			verifikasi();
			main();
            break;
		case 2:
            loading();
            bantuan();
            break;
        case 3:
            loading();
            keluar();
            break;
        default:       
            printf("\n\t\t\t\t\t\tMaaf, harap pilih MENU berdasarkan angka yang tertera");
            sleep (1);                  //pesan eror jika input yang dimasukkan tidak sesuai dengan pilihan apapun
            system("cls");
            main();                     //kembali untuk memilih menu
            break;          
	}
}

void loading(){
	int z;
	printf("\n\t\t\t\t\t\t LOADING ");
      for (z=1;z<6;z++){
	   printf(". ");
	   sleep(1);
      }
      system("cls");    
}

int pilih()                                       
{
    int hitung = 0;
	int angka;
	int pilihan,k;
	int calon[3] = {1, 2, 3};
	FILE * baca;
	baca = fopen("data.txt","r");
	while(!feof(baca))
	{
		fscanf(baca,"%d\n",&angka);fflush(stdin);               
		hitung++;
	}
	fclose(baca);
	int a[hitung];
	int b[hitung];
	int c[hitung];	
	static int i = 0;
	int x = i+1;
	static	int j =0;
	for (k=0;k<hitung;k++)
	{
		a[k]=0;
		b[k]=0;
		c[k]=0;
	}
  if ( i < hitung)
  {	
 for (i; i<x; i++)
 {
	system("cls");

	printf("\n\nDaftar calon ketua \n\n");
	printf("\n\n 1. NAMA CALON 1\n\n");
	printf("\n\n 2. NAMA CALON 2\n\n");
	printf("\n\n 3. NAMA CALON 3\n\n");
	printf("Masukkan Nomor Calon Pilihan Anda: ");
	scanf("%d", &pilihan);
	
	if(pilihan == calon[0]){                   //menyimpan suara yang dimasukkan kedalam array untuk setiap calon yang berkesesuaian
		a[i]=1;
	}
	else if(pilihan == calon[1]){
		b[i]=1;
	}
	else if(pilihan == calon[2]){
		c[i]=1;
	}
	else{
        error2();
	}
    printf("\n\n TERIMAKASIH TELAH BERPARTISIPASI DENGAN MEMILIH\n\n");
 }
  FILE * sumk;
    sumk = fopen("calon.txt","r");
	fscanf(sumk,"calon1 :%d\ncalon2 :%d\ncalon3 :%d\n",&suma,&sumb,&sumc);
    fclose(sumk);

	for (j=0;j<hitung;j++){                   //menghitung jumlah suara yang dihasilkan untuk sementara
		suma=suma+a[j];
		sumb=sumb+b[j];
		sumc=sumc+c[j];
		}
	FILE * sum;
	sum = fopen("calon.txt","w");
	fprintf(sum,"calon1 :%d\ncalon2 :%d\ncalon3 :%d\n",suma,sumb,sumc);
	fclose(sum);
	x++;
	system("pause");}
	else
	{
     system("cls");
     printf("\n\n\t\t\t\t\t\tSemua Peserta Sudah Memilih\n");
     system("pause");
     main();
}
}

int verifikasi(){
	int angka,pemasti,cocok;
	int npm;
	system("cls");
	printf("Silahkan masukan NPM: ");
	scanf("%d",&npm);
	FILE * pasti;
	pasti = fopen("data.txt","r");
	FILE * pasti2;
	pasti2 = fopen("cocok.txt","r");
			while(!feof(pasti2)){
			fscanf(pasti2,"%d\n",&cocok);fflush(stdin);
			 if (npm == cocok){                              //memastikan pemilih belum pernah memilih sebelumnya
				system("cls");
				printf("\t\t\t\tAnda sudah memilih\n\n");
				system("pause");
				break;
			 }
		    }
	while(!feof(pasti)){
		fscanf(pasti,"%d\n",&angka);fflush(stdin);           //memastikan data pemilih telah terdaftar
		if(angka == npm && npm != cocok){
			FILE *tulis;
			tulis = fopen("cocok.txt","a");
			fprintf(tulis,"%d\n",npm);
			fclose(tulis);
			pilih();//ketika nilai yang dimasukan dengan data yang di inginkan sama maka akan memanggil pilih dengan pass by value hitung 1
			break;
		}
		else if(feof(pasti)&& angka != npm && npm != cocok){   
			system("cls");
			printf("\t\t\t\tAnda Tidak Terdaftar\n\n\t\t\t\t");
			system("pause");
		}
	}
	fclose(pasti);
	fclose(pasti2);
}

void bantuan(){
	system("cls");
    int a;    

     printf("\n\t\t\t\t\t\t[INFORMASI PROGRAM]\n\n");
     printf("   Program ini dibuat untuk mempermudah perhitungan suara dalam suatu pemilihan umum dilingkungan UI. Fitur-fitur\n"); 
     printf("yang terdapat pada program ini mempermudah pengguna dalam menggunakan hak pilihnya serta menghitung hasil pemili-\n"); 
     printf("han, selain itu dengan adanya fitur verifikasi, kecurangan dalam proses pemilihan dapat dihindari karena hanya pe-\n");
     printf("milih dengan NPM terdaftar dapat menggunakan fitur 'PILIH'.\n");
     printf("\n[1] PILIH               = memilih salah satu dari calon yang tersedia dengan mencocokkan NPM yang dimasukkkan");
	 printf("\n[2] BANTUAN             = berisi penjelasan mengenai program");
     printf("\n[3] KELUAR              = mengakhiri program dan keluar");
     printf("\n\n\n\t\t\t\t\t\tKembali ke Menu?\n\n\t\t\t\t\t\t [1]Ya\t[2]Tidak\n");
	 printf("\t\t\t\t\t\t Pilih Nomor= ");
  	 scanf("%d", &a);
    	   if (a==1){
    	    	main();
     		}
           else if (a==2){
     	 	    keluar();
     		}
  		   else{
     		   	error();
			}
}
 
void keluar (){
     system("cls");
     printf("\n\n\n\n\t\t\t\t\t TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI\n\t\t\t\t\tSARAN DAN MASUKKAN HUBUNGI CALL CENTER 115000\n");
     system("pause");
	 }

void error()
{
	printf("\n\t\t\t\t\t\tMAAF INPUT YANG ANDA MASUKKAN SALAH\n\t\t\t\t\t\tHARAP PILIH BERDASARKAN ANGKA YANG TERTERA\n");
    system("pause");
    bantuan();
}

void error2()
{	printf("Input salah. Masukkan nomor calon sesuai yang tertera\n\n");
    system("pause");
    pilih();
}
     
