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
void makeCaptcha();
int cekLogin(string username, string password){
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
		if(cekLogin){
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
