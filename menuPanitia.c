#include "header.h"
void gotoPanitiaMenu(Tim tim[]){
	system("cls");
	string user,pass,nama,confirm;
	float saldo;
	char menu;
	int i,lastCount=0;
	int index;
	string timA[8],timB[8];
    Relation r[8];
	do{
		system("cls");
		printf("\n\t--== Login sebagai 'Panitia' ==--");
		printf("\n\t[1]. Daftarkan Tim");
		printf("\n\t[2]. Hapus Tim");
		printf("\n\t[3]. Edit Tim");
		printf("\n\t[4]. Tampil Tim");
		printf("\n\t[5]. Cari Tim");
		printf("\n\t[6]. Pertandingan");
		printf("\n\t[ESC]. Log-out");
		printf("\n\t>>> "); menu=getch();
		switch(menu){
			case '1':
				if(getEmptyTim(tim)!=-1){
					index=getEmptyTim(tim);
					printf("\n\t[Pendaftaran Tim]\n\n");
					do{
						printf("\tMasukkan nama tim : "); fflush(stdin); gets(nama);
						if(strlen(nama)==0) printf("\t[!] Nama tim tidak boleh kosong\n");
						else if(strcmp(nama,"-")==0) printf("\t[!] Nama tim tidak boleh menggunakan'-'\n");
						else if(findTimByNama(tim,nama) != -1) printf("\t[!] Nama tim sudah ada\n");
					}while(strlen(nama)==0 || strcmp(nama,"-")==0 || findTimByNama(tim,nama) != -1);
					do{
						printf("\tMasukkan username : "); fflush(stdin); gets(user);
						if(strlen(user)==0) printf("\t[!] Username tidak boleh kosong\n");
						else if(strcmp(user,"-")==0) printf("\t[!] Username tidak boleh menggunakan '-'\n");
						else if(check_username_tim(tim,user)) printf("\n\t[!] Username sudah digunakan\n");
					}while(check_username_tim(tim,user) || strlen(user)==0 || strcmp(user,"-")==0);
					do{
						printf("\tMasukkan password : "); fflush(stdin); gets(pass);
						if(strlen(pass)==0) printf("\t[!] Password tidak boleh kosong\n");
						else if(strcmp(pass,"-")==0) printf("\t[!] Password tidak boleh menggunakan '-'\n");
					}while(strlen(pass)==0 || strcmp(pass,"-")==0);
					tim[index]=createTim(nama,user,pass,10000);
					printf("\n\t[+] Tim berhasil terdaftar");
					printf("\n\t--> Saldo awal : %.2f",tim[index].saldo);
				}else{
					printf("\n\t[!] Tim yang terdaftar sudah penuh");
				}
			break;
			case '2':
				printf("\n\t[Hapus Tim]\n");
				printf("\n\tMasukkan nama tim : "); fflush(stdin); gets(nama);
				index=getCertainTim(tim,nama);
				if(index!=-1){
					printf("\n\tNama Tim : %s", tim[index].namaTim);
					printf("\n\tUsername : %s",tim[index].username);
					printf("\n\tPassword : %s",tim[index].password);
					printf("\n\tSaldo 	 : %.2f",tim[index].saldo);
					do{
						printf("\n\tYakin akan menghapus tim ? (y/n) :"); fflush(stdin); gets(confirm);
						if(strcmpi(confirm,"y")==0){
							tim[index]=createTim("-","-","-",0);
							printf("\n\t[!] Tim yang terdaftar berhasil dihapus");
						}else if(strcmpi(confirm,"n")==0){
							printf("\n\t[!] Penghapusan Tim dibatalkan");
						}else{
							printf("\t[!] Inputan invalid\n");
						}
					}while(strcmpi(confirm,"y")!=0 && strcmpi(confirm,"n")!=0);
				}else{
					printf("\n\t[!] Tim yang dicari tidak ditemukan");
				}
			break;
			case '3':
				printf("\n\t[Edit Data Tim]\n");
				printf("\n\tMasukkan nama tim : "); fflush(stdin); gets(nama);
				index=getCertainTim(tim,nama);
				if(index!=-1){
					showTim(tim,index);
					do{
						printf("\n\tYakin akan mengedit data ? (y/n) : "); fflush(stdin); gets(confirm);
						if(strcmpi(confirm,"y")==0){
							do{
								printf("\n\tMasukkan nama baru tim : "); fflush(stdin); gets(nama);
								if(strlen(nama)==0) printf("\t[!] Nama tim tidak boleh kosong");
								else if(strcmp(nama,"-")==0) printf("\t[!] Nama tim tidak boleh menggunakan'-'");
								else if(strcmp(tim[index].namaTim,nama)==0) printf("\t[!] Nama tim tidak boleh sama");
								else if(findTimByNama(tim,nama) != -1) printf("\t[!] Nama tim sudah ada");
							}while(strlen(nama)==0 || strcmp(nama,"-")==0 || strcmp(tim[index].namaTim,nama)==0 || findTimByNama(tim,nama) != -1);
							do{
								printf("\tMasukkan saldo baru : "); scanf("%f", &saldo);
								if(saldo<0){
									printf("\t[!] Saldo tidak boleh kurang dari 0\n");
								}
							}while(saldo<0);
							tim[index].saldo=saldo;
							strcpy(tim[index].namaTim,nama);
							printf("\n\t[+] Data Tim berhasil diedit");
						}else if(strcmpi(confirm,"n")==0){
							printf("\n\t[!] Edit Tim dibatalkan");
						}else{
							printf("\t[!] Inputan invalid\n");
						}
					}while(strcmpi(confirm,"y")!=0 && strcmpi(confirm,"n")!=0);
					
				}else{
					printf("\n\t[!] Tim yang dicari tidak ditemukan");
				}
			break;
			case '4':
			if(isEmptyTim(tim)){
				printf("\n\t[!] Tidak ada tim yang terdaftar");
			}else{
				printf("\n\t[Tampil Data Tim dan Pemain]\n");
				quickSortTim(tim,0,TimMax-1);
				for(i=0;i<TimMax;i++){
					quickSortPemain(tim[i].pemain,0,PemainMax-1);
				}
				showAll(tim);
			}
			break;
			case '5':
				printf("\n\t[Cari Tim]\n");
				printf("\n\tMasukkan nama tim : "); fflush(stdin); gets(nama);
				index=getCertainTim(tim,nama);
				if(index!=-1){
					printf("\n\tNama Tim : %s", tim[index].namaTim);
					printf("\n\tUsername : %s",tim[index].username);
					printf("\n\tPassword : %s",tim[index].password);
					printf("\n\tSaldo    : %.2f",tim[index].saldo);
					showPemain(tim[index].pemain);
				}else{
					printf("\n\t[!] Tim yang dicari tidak ditemukan");
				}
			break;
			case '6':
				if(countTim(tim)>=4 && countTim(tim)%2==0){
					if(countPlayer(tim)){
						if(lastCount!=countPlayer(tim)){
							splitTimInto2(tim,timA,timB);
                            matchRelation(r,timA,timB);
                            showMatch(r,timA);
							lastCount=countPlayer(tim);
						}else{
							showMatch(r,timA);
						}
					}else{
						printf("\n\t[!] Semua tim harus memiliki 5 pemain");
					}
				}else if(countTim(tim)<4){
					printf("\n\t[!] Jumlah tim kurang dari 4");
				}else{
					printf("\n\t[!] Jumlah tim tidak boleh ganjil");
				}
			break;
			case 27:
				printf("\n\t[!] Kembali ke menu utama . . .");
			break;
			default:
				printf("\n\t[!] Menu tidak tersedia");
			break;
		}
		if(menu!=27) getch();
	}while(menu!=27);
	
}
