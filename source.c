#include "header.h"

void init(Tim tim[]){
	int i,j;
	for(i=0;i<TimMax;i++){
		strcpy(tim[i].namaTim,"-");
		strcpy(tim[i].password,"-");
		strcpy(tim[i].username,"-");
		tim[i].saldo = 0;
		for(j=0;j<PemainMax;j++){
			strcpy(tim[i].pemain[j].namaPemain,"-");
			tim[i].pemain[j].noPunggung = 0;
			tim[i].pemain[j].harga = 0;
		}
	}
}

void testInit(Tim tim[]){
	strcpy(tim[0].namaTim,"AAA");
	strcpy(tim[0].password,"aaa");
	strcpy(tim[0].username,"aaa");
	tim[0].saldo = 10000;
		strcpy(tim[0].pemain[0].namaPemain,"A");
		tim[0].pemain[0].noPunggung = 2;
		tim[0].pemain[0].harga = 1000;
		strcpy(tim[0].pemain[1].namaPemain,"B");
		tim[0].pemain[1].noPunggung = 3;
		tim[0].pemain[1].harga = 2000;
		strcpy(tim[0].pemain[2].namaPemain,"C");
		tim[0].pemain[2].noPunggung = 1;
		tim[0].pemain[2].harga = 3000;
	
	strcpy(tim[1].namaTim,"BBB");
	strcpy(tim[1].password,"bbb");
	strcpy(tim[1].username,"bbb");
	tim[1].saldo = 20000;
		strcpy(tim[1].pemain[0].namaPemain,"Z");
		tim[1].pemain[0].noPunggung = 3;
		tim[1].pemain[0].harga = 1000;
		strcpy(tim[1].pemain[1].namaPemain,"X");
		tim[1].pemain[1].noPunggung = 1;
		tim[1].pemain[1].harga = 2000;
		strcpy(tim[1].pemain[2].namaPemain,"Y");
		tim[1].pemain[2].noPunggung = 2;
		tim[1].pemain[2].harga = 3000;
	
}

int cekLoginAdmin(string username, string password){
	if(strcmp(username,"panitia")==0 && strcmp(password,"admin")==0){
		return 1;
	}else{
		return 0;
	}
}

void gotoLoginPanitia(){
	string username,password;
	while(1){
		printf("\n\tUsername: ");fflush(stdin);gets(username);
		printf("\tPassword: ");fflush(stdin);gets(password);
		if(cekLoginAdmin){
			printf("\n\tLogin berhasil...");
			break;
		}else{
			printf("\n\tUsername / Password salah!");
		}
	}
	gotoPanitiaMenu();
	
}

void gotoPanitiaMenu(){
	system("cls");
	char menu;
	
	while(1){
		printf("\n\t[1]. Daftar Tim");
		printf("\n\t[2]. Hapus Tim");
		printf("\n\t[3]. Edit Tim");
		printf("\n\t[4]. Tampil Tim");
		printf("\n\t[5]. Cari Tim");
		menu=getch();
		switch(menu){
			case '1':
				
				break;
			default:
				printf("Menu tidak ada");
		}
	}
	
}


int menuTim(Tim tim[], int id){
	int menu,searchedTim,loop=1;
	string search,konfirm;
	int indexPemain, indexPemain2;
	string namaPemain;
	int noPunggung;
	float hargaPemain;
	loop: while(loop){
		system("cls");
		printf("TIM\t: %s",tim[id].namaTim);
		printf("\nSALDO\t: Rp. %.2f",tim[id].saldo);
		printf("\n[1]. Daftarkan Pemain");
		printf("\n[2]. Transfer Pemain");
		printf("\n[3]. Hapus Pemain");
		printf("\n[4]. Edit Pemain");
		printf("\n[5]. Tampil Pemain");
		printf("\n[0]. Logout");
		printf("\n>>> ");scanf("%d",&menu);
		switch(menu){
			case 1:
				indexPemain = cekNoPunggungPemain(tim[id].pemain,0);//cek masih ada kosong tidak
				if(indexPemain==-1){
					printf("\n\tPemain sudah penuh!");
				}else{
					printf("\nNama Pemain: ");fflush(stdin);gets(namaPemain);
					noPunggung = 1;
					while(1){
						if(cekNoPunggungPemain(tim[id].pemain,noPunggung) >= 0){
							noPunggung++;
						}else{
							break;
						}
					}
					printf("\nHarga\t: ");scanf("%f",&hargaPemain);
					tim[id].pemain[indexPemain] = makePemain(namaPemain,noPunggung,hargaPemain);
					printf("\nPemain berhasil ditambahkan");
				}
				break;
			case 2:
				indexPemain = cekNoPunggungPemain(tim[id].pemain,0);//cek masih ada kosong tidak
				if(indexPemain!=-1){
					printf("\nCari Tim: ");fflush(stdin);gets(search);
					searchedTim = findTimByNama(tim,search);
					if(searchedTim==-1){
						printf("\n\tTim tidak ditemukan!");
					}else if(searchedTim==id){
						printf("\n\tTim invalid!");
					}else if(cekJumlahPemain(tim[searchedTim])==0){
						printf("\n\tTim tidak punya pemain!");
					}else{
						tampilPemainTim(tim[searchedTim].pemain);
						printf("\nPemain yang ingin ditransfer[No Punggung]: ");scanf("%d",&noPunggung);
						indexPemain2 = cekNoPunggungPemain(tim[searchedTim].pemain,noPunggung);
						if( indexPemain2 == -1){
							printf("\n\tPemain tidak ditemukan!");
						}else if(tim[searchedTim].pemain[indexPemain2].harga>tim[id].saldo){
							tampilPemain(tim[searchedTim].pemain[indexPemain2]);
							printf("\n\tSaldo tidak cukup!");
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
							printf("\nPemain telah ditransfer...");
						}
					}
				}
				break;
			case 3:
				if(cekJumlahPemain(tim[id])>0){
					printf("\nCari Pemain: ");scanf("%d",&noPunggung);
					indexPemain = findPemainByNoPunggung(tim[id].pemain,noPunggung);
					if(indexPemain!=-1){
						tampilPemain(tim[id].pemain[indexPemain]);
						printf("\n\tYakin ingin dihapus ?[iya/tidak] ");fflush(stdin);gets(konfirm);
						if(strcmpi(konfirm,"iya")==0){
							tim[id].pemain[indexPemain] = makePemain("-",0,0);
							printf("\n\tData terhapus...");
						}else{
							printf("\n\tData tidak terhapus...");
						}
					}else{
						printf("\nPemain tidak ditemukan!");
					}
				}else{
					printf("\nTidak ada pemain!");
				}
				
				break;
			case 4:
				if(cekJumlahPemain(tim[id])>0){
					printf("\nCari Pemain: ");scanf("%d",&noPunggung);
					indexPemain = findPemainByNoPunggung(tim[id].pemain,noPunggung);
					if(indexPemain!=-1){
						tampilPemain(tim[id].pemain[indexPemain]);
						printf("\n\tYakin ingin diubah ?[iya/tidak] ");fflush(stdin);gets(konfirm);
						if(strcmpi(konfirm,"iya")==0){
							
							printf("\nNama Pemain: ");fflush(stdin);gets(namaPemain);
							printf("\nHarga\t: ");scanf("%f",&hargaPemain);
							
							tim[id].pemain[indexPemain] = makePemain(namaPemain,noPunggung,hargaPemain);
							printf("\n\tData terubah...");
						}else{
							printf("\n\tData tidak terubah...");
						}
					}else{
						printf("\nPemain tidak ditemukan!");
					}
				}else{
					printf("\nTidak ada pemain!");
				}
				break;
			case 5:
				tampilPemainTim(tim[id].pemain);
				break;
			case 0:
				loop=0;
				break;
			default:
				printf("Menu tidak ada!");
		}getch();
	}
}
