# E-Vote
Usefull program for election! You can give vote and read out the result and save the result in .txt file 

There are two main programs for this project, first is the program for the voters and the second is the program for the server to find out the result o

PROGRAM TUTORIALS
======

This tutorial will explain steps to build E-Vote program (both for the voter and for the server). These program use array in most of their parts and this program was built by modular principal, read and write data in .txt files and also comparing data in those files.

Server E-Vote
--------

1. Declare the global variables and the modulars
```
#include<stdio.h>
#include<windows.h>

int suma=0;
int sumb=0;
int sumc=0;
int satu=0, dua=0, tiga= 0;
int hasil();              
int list();
int hapus();              
void menu();                       
void keluar();            
void loading();
```
2. Modular for loading effect
```
void loading(){     
	int z;
	printf("\n\t\t\t\t\t\t LOADING ");
      for (z=1;z<6;z++){
	   printf(". ");
	   sleep(1);
      }
      system("cls");    
}
```
3. Modular for showing and choose menu
```
void menu(){
    int m;
	printf("\n\nMenu :\n\t1. HASIL\n\t2. LIST DAFTAR PEMILIH\n\t3. HAPUS\n\t4. KELUAR"); //daftar menu
	printf("\n\nPilih Nomor Menu: ");
	scanf("%d",&m);
	
	switch(m){ 
		case 1:
            loading();
            hasil();
            main();
            break;    
        case 2:
            loading();
            list();
            main();
            break;
        case 3 :
            loading();
        	hapus();
        	main();
        	break;
        case 4 :
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
```
4. Modular for erasing data for inizialitation
```
int hapus(){              
FILE * awal;
FILE * awal2;
awal2 = fopen("calon.txt","w");
awal = fopen("cocok.txt","w");
fprintf(awal,"");
fprintf(awal2,"calon1 :0\ncalon2 :0\ncalon3 :0\n");
fclose(awal);
fclose(awal2);
printf("\n\n\t\t\t\tData di System Telah Di Hapus!\n\n\t\t\t\t");
system("PAUSE");
}

```
5. Modular for show voter that has already registered
```
int list(){                                              
    system("cls");
    printf("\t\t\t\t\t\tDaftar NPM Yang Telah Terdaftar\n\n");
	unsigned long long int angka;
	FILE * baca;
	baca = fopen("data.txt","r");
	int g = 0;
	while(!feof(baca)){
		fscanf(baca,"%llu\n",&angka);fflush(stdin);printf("\n\n");             //membaca setiap baris pada file "data.txt"
		printf("NPM Pemilih ke %d :  %llu",g,angka);                           //menampilkan hasil pembacaan
		g++;
	}
	fclose(baca);
	printf("\n\n");
	system("Pause");
}
```
6. Modular for showing result of the election
```
int hasil(){                          
    system("cls");
    FILE * calon1;
	calon1 = fopen("calon.txt","r");
	fscanf(calon1,"calon1 :%d\ncalon2 :%d\ncalon3 :%d\n",&satu,&dua,&tiga);     //membaca jumlah dari file dengan format .txt
	fclose(calon1);
	suma = satu;
	sumb = dua;
	sumc = tiga;
    printf("Total suara: \n");
	printf("1. CALON 1= %d suara\n", suma);
	printf("2. CALON 2= %d suara\n", sumb);
	printf("3. CALON 3= %d suara\n", sumc);

	if ((suma>sumb) && (suma>sumc)){
		printf ("\nKETUA TERPILIH (CALON 1)\n\n");                             //menampilkan ketua terpilih dari hasil suara terbanyak
	}
	else if ((sumb>suma) && (sumb>sumc)){
		printf ("\nKETUA TERPILIH (CALON 2)\n\n");
	}
	else if ((sumc>sumb) && (suma<sumc)){
		printf ("\nKETUA TERPILIH (CALON 3)\n\n");
	}
	else if((suma==0)&&(sumb==0)&&(sumc==0)){
        printf ("\n\t\t\t\t\t PEMILIHAN BELUM DILAKUKAN\n\n");
        }
	else{
		printf("\n\t\t\t KETUA TERPILIH MEMILIKI POIN SERI MAKA AKAN DIADAKAN PEMILIHAN ULANG\n\n"); //ditampilkan jika terdapat jumlah suara sama
		}	
	calon1 = fopen("calon.txt","w");
	fprintf(calon1,"calon1 :%d\ncalon2 :%d\ncalon3 :%d\n",suma,sumb,sumc);
	fclose(calon1);
	system("pause");
}
```
7. Modular for end the program
```
void keluar (){
     system("cls");
     printf("\n\n\n\n\t\t\t\t\t TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI\n\t\t\t\t\tSARAN DAN MASUKKAN HUBUNGI CALL CENTER 115000\n");
     system("pause");
	 }
```

Voters E-Vote
-----------

1. Declare the global variables and the modulars
```
#include<stdio.h>
#include<windows.h>

int suma=0;
int sumb=0;
int sumc=0;
int satu = 0,dua = 0,tiga = 0;
void loading();  
void menu();     
void bantuan();  
void keluar();   
void error();    
void error2();
int verifikasi();
int pilih();     
```
2. modular for showing and choose menu
```
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
```
3. modular for verifying registered voters and voters those haven't been voted yet 
```
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
```
4. modular for give vote
```
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
	else{
     system("cls");
     printf("\n\n\t\t\t\t\t\tSemua Peserta Sudah Memilih\n");
     system("pause");
     main();
     }
}
```
5. modular for show program information
```
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
```
6. modular for eror handling 1
```
void error()
{
	printf("\n\t\t\t\t\t\tMAAF INPUT YANG ANDA MASUKKAN SALAH\n\t\t\t\t\t\tHARAP PILIH BERDASARKAN ANGKA YANG TERTERA\n");
    system("pause");
    bantuan();
}
```
7. modular for eror handling 2
```
void error2()
{	printf("Input salah. Masukkan nomor calon sesuai yang tertera\n\n");
    system("pause");
    pilih();
}
```
