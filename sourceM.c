#include "header.h"

int LoginManager(Tim tim[]){
	string user,pass;
	int cekLogin=-1;
	int i;
	printf("\n\tUsername: ");fflush(stdin);gets(user);
	printf("\tPassword: ");fflush(stdin);gets(pass);
	cekLogin=loginTim(tim,user,pass);
	if(cekLogin>=0){
		printf("\n\tLogin Berhasil..."); getch();
	}else{
		printf("\n\tUsername atau password salah!");
	}
	return cekLogin;
}
int loginTim(Tim tim[],string username,string password){
	int i,found=-1;
	for(i=0;i<TimMax;i++){
		if(strcmp(username,tim[i].username)==0 && strcmp(password,tim[i].password)==0){
			found = i;
			break;
		}
	}
	return found;
}
int menuTim(Tim tim[], int id){
	int searchedTim,loop=1;
	string search,konfirm;
	int indexPemain, indexPemain2;
	string namaPemain;
	int noPunggung;
	float hargaPemain;
	char menu;
	do{
		system("cls");
		printf("\n\t--== Login sebagai Tim\t: %s ==--",tim[id].namaTim);
		printf("\n\tSaldo : Rp. %.2f\n",tim[id].saldo);
		printf("\n\t[1]. Daftarkan Pemain");
		printf("\n\t[2]. Transfer Pemain");
		printf("\n\t[3]. Hapus Pemain");
		printf("\n\t[4]. Edit Pemain");
		printf("\n\t[5]. Tampil Pemain");
		printf("\n\t[ESC]. Logout");
		printf("\n\t>>> "); menu=getch();
		switch(menu){
			case '1':
				indexPemain = cekNoPunggungPemain(tim[id].pemain,0);//cek masih ada kosong tidak
				if(indexPemain==-1){
					printf("\n\t[!] Pemain sudah penuh!");
				}else{
					printf("\n\t[Pendaftaran Pemain]\n");
					do{
						printf("\tNama Pemain: ");fflush(stdin);gets(namaPemain);
						if(strlen(namaPemain)==0) printf("\t[!] Nama pemain tidak boleh kosong");
						else if(strcmp(namaPemain,"-")==0) printf("\t[!] Nama pemain tidak boleh menggunakan'-'");
						printf("\n");
					}while(strlen(namaPemain)==0 || strcmp(namaPemain,"-")==0);
					noPunggung = 1;
					while(1){
						if(cekNoPunggungPemain(tim[id].pemain,noPunggung) >= 0){
							noPunggung++;
						}else{
							break;
						}
					}
					do{
						printf("\tMasukkan harga pemain : "); scanf("%f", &hargaPemain);
						if(hargaPemain<0){
							printf("\t[!] Harga Pemain tidak boleh kurang dari 0");
						}
					}while(hargaPemain<0);
					tim[id].pemain[indexPemain] = makePemain(namaPemain,noPunggung,hargaPemain);
					printf("\n\t[!] Pemain berhasil ditambahkan");
				}
				break;
			case '2':
				indexPemain = cekNoPunggungPemain(tim[id].pemain,0);//cek masih ada kosong tidak
				if(indexPemain!=-1){
					printf("\n\t[Transfer Pemain]\n");
					printf("\tCari Tim: ");fflush(stdin);gets(search);
					searchedTim = findTimByNama(tim,search);
					if(searchedTim==-1){
						printf("\n\t[!] Tim tidak ditemukan!");
					}else if(searchedTim==id){
						printf("\n\t[!] Tim invalid!");
					}else if(cekJumlahPemain(tim[searchedTim])==0){
						printf("\n\t[!] Tim tidak punya pemain!");
					}else{
						tampilPemainTim(tim[searchedTim].pemain);
						printf("\nPemain yang ingin ditransfer[No Punggung]: ");scanf("%d",&noPunggung);
						indexPemain2 = cekNoPunggungPemain(tim[searchedTim].pemain,noPunggung);
						if( indexPemain2 == -1){
							printf("\n\t[!] Pemain tidak ditemukan!");
						}else if(tim[searchedTim].pemain[indexPemain2].harga>tim[id].saldo){
							tampilPemain(tim[searchedTim].pemain[indexPemain2]);
							printf("\n\t[!] Saldo tidak cukup!");
						}else{
							tim[id].saldo -= tim[searchedTim].pemain[indexPemain2].harga;
							tim[searchedTim].saldo += tim[searchedTim].pemain[indexPemain2].harga;
							noPunggung = tim[searchedTim].pemain[indexPemain2].noPunggung;
							while(1){
								if(cekNoPunggungPemain(tim[id].pemain,noPunggung) >= 0){
									noPunggung++;
								}else{
									break;
								}
							}
							tim[id].pemain[indexPemain] = tim[searchedTim].pemain[indexPemain2];
							tim[id].pemain[indexPemain].noPunggung = noPunggung;
							tim[searchedTim].pemain[indexPemain2] = makePemain("-",0,0);
							printf("\n\t[!] Pemain telah ditransfer...");
						}
					}
				}
				break;
			case '3':
				if(cekJumlahPemain(tim[id])>0){
					printf("\n\tNomor punggung pemain : ");scanf("%d",&noPunggung);
					indexPemain = findPemainByNoPunggung(tim[id].pemain,noPunggung);
					if(indexPemain!=-1){
						printf("\n\t[Hapus Pemain]\n");
						tampilPemain(tim[id].pemain[indexPemain]);
						printf("\n\tYakin ingin dihapus ? (y/n) : ");fflush(stdin);gets(konfirm);
						if(strcmpi(konfirm,"y")==0){
							tim[id].pemain[indexPemain] = makePemain("-",0,0);
							printf("\n\t[!] Data terhapus...");
						}else{
							printf("\n\t[!] Data tidak terhapus...");
						}
					}else{
						printf("\n\t[!] Pemain tidak ditemukan!");
					}
				}else{
					printf("\n\t[!] Tidak ada pemain!");
				}
				
				break;
			case '4':
				if(cekJumlahPemain(tim[id])>0){
					printf("\n\tNomor punggung pemain : ");scanf("%d",&noPunggung);
					indexPemain = findPemainByNoPunggung(tim[id].pemain,noPunggung);
					if(indexPemain!=-1){
						printf("\n\t[Edit Data Pemain]\n");
						tampilPemain(tim[id].pemain[indexPemain]);
						printf("\n\tYakin ingin diubah ? (y/n) : ");fflush(stdin);gets(konfirm);
						if(strcmpi(konfirm,"y")==0){
							
							printf("\nNama Pemain: ");fflush(stdin);gets(namaPemain);
							printf("\nHarga\t: ");scanf("%f",&hargaPemain);
							do{
								printf("\tNama Pemain: ");fflush(stdin);gets(namaPemain);
								if(strlen(namaPemain)==0) printf("\t[!] Nama pemain tidak boleh kosong");
								else if(strcmp(namaPemain,"-")==0) printf("\t[!] Nama pemain tidak boleh menggunakan'-'");
								printf("\n");
							}while(strlen(namaPemain)==0 || strcmp(namaPemain,"-")==0);
							
							do{
								printf("\tMasukkan harga pemain : "); scanf("%f", &hargaPemain);
								if(hargaPemain<0){
									printf("\t[!] Harga Pemain tidak boleh kurang dari 0");
								}
							}while(hargaPemain<0);

							tim[id].pemain[indexPemain] = makePemain(namaPemain,noPunggung,hargaPemain);
							printf("\n\t[!] Data berhasil diedit");
						}else{
							printf("\n\t[!] Edit data dibatalkan");
						}
					}else{
						printf("\n\t[!] Pemain tidak ditemukan!");
					}
				}else{
					printf("\n\t[!] Tidak ada pemain!");
				}
				break;
			case '5':
				tampilPemainTim(tim[id].pemain);
				break;
			case 27:
				printf("\n\t[!] Kembali ke menu utama . . .");
				break;
			default:
				printf("\n\t[!] Menu tidak tersedia");
		}
		if(menu!=27) getch();
	}while(menu!=27);
}
int cekJumlahPemain(Tim tim){
	int i,sum=0;
	for(i=0;i<PemainMax;i++){
		if(tim.pemain[i].noPunggung!=0){
			sum++;
		}
	}
	return sum;
}

int cekNoPunggungPemain(Pemain pemain[], int cek){
	int i;
	for(i=0;i<PemainMax;i++){
		if(pemain[i].noPunggung==cek){
			return i;
		}
	}
	return -1;
}
Pemain makePemain(string nama,int no,float harga){
	Pemain pemain;
	strcpy(pemain.namaPemain,nama);
	pemain.noPunggung = no;
	pemain.harga = harga;
	return pemain;
}
int findTimByNama(Tim tim[],string search){
	int i;
	for(i=0;i<TimMax;i++){
		if(strcmpi(tim[i].namaTim,search)==0){
			return i;
		}
	}
	return -1;
}

int findPemainByNoPunggung(Pemain pemain[], int search){
	int i;
	for(i=0;i<PemainMax;i++){
		if(pemain[i].noPunggung == search){
			return i;
		}
	}
	return -1;
}
// void bubbleSortPemain(Pemain pemain[]){
// 	int i,swap;
// 	Pemain temp;
// 	do{
// 		swap=0;
// 		for(i=0;i<PemainMax-1;i++){
// 			if(pemain[i].noPunggung !=0 && pemain[i].noPunggung > pemain[i+1].noPunggung){
// 				temp = pemain[i];
// 				pemain[i] = pemain[i+1];
// 				pemain[i+1] = temp;
// 				swap=1;
// 			}
// 		}
// 	}while(swap);
// }


int tampilPemain(Pemain pemain){
	printf("\n\tNomor Punggung: %d",pemain.noPunggung);
	printf("\n\tNama\t\t: %s",pemain.namaPemain);
	printf("\n\tHarga\t\t: Rp.%.2f\n",pemain.harga);
}

int tampilPemainTim(Pemain pemain[]){
	int i;
	Pemain temp[PemainMax];
	for(i=0;i<PemainMax;i++){
		temp[i]=pemain[i];
	}
	quickSortPemain(temp,0,PemainMax-1);
	
	for(i=0;i<PemainMax;i++){
		if(strcmp(temp[i].namaPemain,"-")!=0){
			tampilPemain(temp[i]);
		}
	}
	
}
