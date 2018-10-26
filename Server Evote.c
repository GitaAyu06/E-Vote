#include<stdio.h>
#include<windows.h>

int suma=0;
int sumb=0;
int sumc=0;
int satu=0, dua=0, tiga= 0;
int hasil();              //menampilkan hasil pemungutan suara sementara
int list();
int hapus();              //mengosongkan data untuk inisialisasi jumlah suara
void menu();              //memilih menu            
void keluar();            //keluar dari program
void loading();

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
int main(){
  system("color E0");   //mengatur warna background
  system("cls");
  printf("\n========================================================================================================================"); 
  printf("\n=============================================SERVER E-VOTE V1.0========================================================="); //judul program
  printf("\n===================================OLEH: GITA AYU SALSABILA & BAYU SATRIA PERSADA=======================================");
  printf("\n========================================================================================================================");
  menu();
}

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

void loading(){     
	int z;
	printf("\n\t\t\t\t\t\t LOADING ");
      for (z=1;z<6;z++){
	   printf(". ");
	   sleep(1);
      }
      system("cls");    
}
 
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

void keluar (){
     system("cls");
     printf("\n\n\n\n\t\t\t\t\t TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI\n\t\t\t\t\tSARAN DAN MASUKKAN HUBUNGI CALL CENTER 115000\n");
     system("pause");
	 }
