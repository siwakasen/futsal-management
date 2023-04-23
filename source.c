#include "header.h"

void init(Tim tim[]){
	int i,j;
	for(i=0;i<TimMax;i++){
		strcpy(tim[i].namaTim,"-");
		strcpy(tim[i].password,"-");
		strcpy(tim[i].username,"-");
		tim[i].saldo = 0;
		initPemain(&tim[i]);
	}
}
void initPemain(Tim *T){
	int i;
	for(i=0;i<PemainMax;i++){
		strcpy((*T).pemain[i].namaPemain,"-");
		(*T).pemain[i].noPunggung = 0;
		(*T).pemain[i].harga = 0;
	}
}
void makeCaptcha(){
	string capt;
	char arr[7];
	int i,j;
	do{
		/*format captcha (index)
			0 uppercase
			1 lowercase
			2 digit
			3 random -> uppercase/lowercase/digit
			4 uppercase
			5 lowercase
			6 digit
		*/
		for(i=0;i<7;i++){
			if(i%4==0) arr[i]=(rand() % ('Z'-'A'+1)+'A');
			else if(i%4==1) arr[i]=(rand() % ('z'-'a'+1)+'a');
			else if(i%4==2) arr[i]=(rand() % ('9'-'0'+1)+'0');
			else if(i==3){
				j=(rand() % (3-1+1)+1);
				if(j==1) arr[i]=(rand() % ('Z'-'A'+1)+'A');
				else if(j==2) arr[i]=(rand() % ('z'-'a'+1)+'a');
				else if(j==3) arr[i]=(rand() % ('9'-'0'+1)+'0');
			}
		}
		arr[i]='\0';
		printf("\n\tCaptcha : %s",arr);
		printf("\n\t> "); fflush(stdin); gets(capt);
		if(strcmp(capt,arr)!=0){
			printf("\n\t[!] Captcha salah\n");
		}
	}while(strcmp(capt,arr)!=0);

}
bool cekLogin(string username, string password){
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
		if(cekLogin(username,password)){
			makeCaptcha();
			printf("\n\t[~] Login berhasil..."); getch();
			break;
		}else{
			printf("\n\t[!] Username atau Password salah!");
		}
		printf("\n");
	}
}

void gotoPanitiaMenu(Tim tim[]){
	system("cls");
	string user,pass,nama,confirm;
	float saldo;
	char menu;
	int i,lastCount=0;
	int index;
	string timA[8],timB[8];
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
					printf("\n\t[Pendaftaran Tim]\n");
					do{
						printf("\tMasukkan nama tim : "); fflush(stdin); gets(nama);
						if(strlen(nama)==0) printf("\t[!] Nama tim tidak boleh kosong");
						else if(strcmp(nama,"-")==0) printf("\t[!] Nama tim tidak boleh menggunakan'-'");
						printf("\n");
					}while(strlen(nama)==0 || strcmp(nama,"-")==0);
					do{
						printf("\tMasukkan username tim %s : ",nama); fflush(stdin); gets(user);
						if(strlen(user)==0) printf("\t[!] Username tidak boleh kosong");
						else if(strcmp(user,"-")==0) printf("\t[!] Username tidak boleh menggunakan '-'");
						else if(check_username_tim(tim,user)) printf("\n\t[!] Username sudah digunakan");
						printf("\n");
					}while(check_username_tim(tim,user) || strlen(user)==0 || strcmp(user,"-")==0);
					do{
						printf("\tMasukkan password : "); fflush(stdin); gets(pass);
						if(strlen(pass)==0) printf("\t[!] Password tidak boleh kosong");
						else if(strcmp(pass,"-")==0) printf("\t[!] Password tidak boleh menggunakan '-'");
						printf("\n");
					}while(strlen(pass)==0 || strcmp(pass,"-")==0);
					tim[index]=createTim(nama,user,pass,10000);
					printf("\n\t[+] Tim berhasil terdaftar");
					printf("\n\t--> Saldo awal : %.2f",tim[index].saldo);
				}else{
					printf("\n\t[!] Tim yang terdaftar sudah mencapai maksimal");
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
					printf("\n\tYakin akan menghapus tim ? (y/n) :"); fflush(stdin); gets(confirm);
					if(strcmpi(confirm,"y")==0){
						tim[index]=createTim("-","-","-",0);
						printf("\n\t[!] Tim yang terdaftar berhasil dihapus");
					}else{
						printf("\n\t[!] Penghapusan Tim dibatalkan");
					}
				}else{
					printf("\n\t[!] Tim yang dicari tidak ditemukan");
				}
			break;
			case '3':
				printf("\n\t[Edit Tim]\n");
				printf("\n\tMasukkan nama tim : "); fflush(stdin); gets(nama);
				index=getCertainTim(tim,nama);
				if(index!=-1){
					do{
						printf("\tMasukkan nama baru tim : "); fflush(stdin); gets(nama);
						if(strlen(nama)==0) printf("\t[!] Nama tim tidak boleh kosong");
						else if(strcmp(nama,"-")==0) printf("\t[!] Nama tim tidak boleh menggunakan'-'");
						printf("\n");
					}while(strlen(nama)==0 || strcmp(nama,"-")==0);
					do{
						printf("\tMasukkan saldo baru : "); scanf("%f", &saldo);
						if(saldo<0){
							printf("\t[!] Saldo tidak boleh kurang dari 0");
						}
					}while(saldo<0);
					tim[index].saldo=saldo;
					strcpy(tim[index].namaTim,nama);
					printf("\n\t[+] Data Tim berhasil diedit");
				}else{
					printf("\n\t[!] Tim yang dicari tidak ditemukan");
				}
			break;
			case '4':
				quickSortTim(tim,0,TimMax-1);
				for(i=0;i<TimMax;i++){
					quickSortPemain(tim[i].pemain,0,PemainMax-1);
				}
				showAll(tim);
			break;
			case '5':
				printf("\n\t[Cari Tim]\n");
				printf("\n\tMasukkan nama tim : "); fflush(stdin); gets(nama);
				index=getCertainTim(tim,nama);
				if(index!=-1){
					printf("\n  Nama Tim : %s", tim[index].namaTim);
					printf("\n  Username : %s",tim[index].username);
					printf("\n  Password : %s",tim[index].password);
					printf("\n  Saldo 	 : %.2f",tim[index].saldo);
					showPemain(tim[index].pemain);
				}else{
					printf("\n\t[!] Tim yang dicari tidak ditemukan");
				}
			break;
			case '6':
				if(countTim(tim)>=4 && countTim(tim)%2==0){
					if(countPlayer(tim)){
						if(lastCount!=countPlayer(tim)){
							createMatch(tim,timA,timB);
							showMatch(timA,timB);
							lastCount=countPlayer(tim);
						}else{
							showMatch(timA,timB);
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
		getch();
	}while(menu!=27);
	
}
void showAll(Tim tim[]){
	int i;
	for(i=0;i<TimMax;i++){
		if(strcmp(tim[i].namaTim,"-")!=0){
			printf("\n  Nama Tim : %s", tim[i].namaTim);
			printf("\n  Username : %s",tim[i].username);
			printf("\n  Password : %s",tim[i].password);
			printf("\n  Saldo    : %.2f",tim[i].saldo);
			showPemain(tim[i].pemain);
		}
	}
}
void showPemain(Pemain pemain[]){
	int j;
	for(j=0;j<PemainMax;j++){
		if(strcmp(pemain[j].namaPemain,"-")!=0){
			printf("\n\tNama Pemain    : %s",pemain[j].namaPemain);
			printf("\n\tNomor Punggung : %d",pemain[j].noPunggung);
			printf("\n\tHarga Pemain   : %.2f",pemain[j].harga);
			printf("\n");
		}
	}
}

void quickSortTim(Tim tim[], int low, int high){
	if(low<high){
		int pi=lomutoTim(tim,low,high);
		quickSortTim(tim,low,pi-1);
		quickSortTim(tim,pi+1,high);
	}
}
int lomutoTim(Tim tim[], int low, int high){
	string pivot;
	strcpy(pivot,tim[high].namaTim);
	int i=(low-1);
	int j;
	for(j=low;j<high;j++){
		if(strcmp(tim[j].namaTim,pivot)<0){
			i++;
			swapTim(&tim[i], &tim[j]);
		}
	}
	swapTim(&tim[i+1], &tim[high]);
	return(i+1);
}
void swapTim(Tim *X, Tim *Y){
	Tim temp=(*X);
	(*X)=(*Y);
	(*Y)=temp;
}
void quickSortPemain(Pemain pemain[], int low, int high){
	if(low<high){
		int pi=lomutoPemain(pemain,low,high);
		quickSortPemain(pemain,low,pi-1);
		quickSortPemain(pemain,pi+1,high);
	}
}
int lomutoPemain(Pemain pemain[], int low, int high){
	string pivot;
	strcpy(pivot,pemain[high].namaPemain);
	int i=(low-1);
	int j;
	for(j=low;j<high;j++){
		if(strcmp(pemain[j].namaPemain,pivot)<0){
			i++;
			swapPemain(&pemain[i], &pemain[j]);
		}
	}
	swapPemain(&pemain[i+1], &pemain[high]);
	return(i+1);
}
void swapPemain(Pemain *X, Pemain *Y){
	Pemain temp=(*X);
	(*X)=(*Y);
	(*Y)=temp;
}
Tim createTim(string nama, string user, string pass, float saldo){
	Tim T;
	strcpy(T.namaTim,nama);
	strcpy(T.username,user);
	strcpy(T.password,pass);
	T.saldo=10000;
	initPemain(&T);
	return T;
}
int getEmptyTim(Tim tim[]){
	int i;
	for(i=0;i<TimMax;i++){
		if(strcmp(tim[i].namaTim,"-")==0) return i;
	}
	return -1;
}
bool check_username_tim(Tim tim[], string user){
	int i;
	for(i=0;i<TimMax;i++){
		if(strcmp(user,tim[i].username)==0) return true;
	}
	return false;
}
int getCertainTim(Tim tim[], string name){
	int i;
	for(i=0;i<TimMax;i++){
		if(strcmp(name,tim[i].namaTim)==0 && strcmp(name,"-")!=0 ) return i;
	}
	return -1;
}
int countTim(Tim tim[]){
	int i,sum=0;
	for(i=0;i<TimMax;i++){
		if(strcmp(tim[i].namaTim,"-")!=0) sum++;
	}
	return sum;
}
bool countPlayer(Tim tim[]){
	int i,j, count;
	for(i=0;i<TimMax;i++){
		count=0;
		if(strcmp(tim[i].namaTim,"-")!=0){
			for(j=0;j<PemainMax;j++){
				if(strcmp(tim[i].pemain[j].namaPemain,"-")!=0) count++;
			}
			if(count<5) return false;
		}
	}
	return true;
}
void createMatch(Tim tim[], string timA[], string timB[]){
	int i,j=0,k=0;
	char random;
	for(i=0;i<8;i++){
		strcpy(timA[i],"-");
		strcpy(timB[i],"-");
	}
	for(i=0;i<TimMax;i++){
		if(strcmp(tim[i].namaTim,"-")!=0){
			do{
				random=(rand() % ('B' - 'A'+1)+'A');
				if(random=='A'){
					if(countString(timA)>countString(timB)){
						continue;
					}else{
						strcpy(timA[j],tim[i].namaTim);
						j++;
						break;
					}
				}else{
					if(countString(timB)>countString(timA)){
						continue;
					}else{
						strcpy(timB[k],tim[i].namaTim);
						k++;
						break;
					}
				}
			}while(true);
		}
	}
}
void showMatch(string timA[], string timB[]){
	int i;
	for(i=0;i<countString(timA);i++){
		printf("\n\t[%s] VS [%s]",timA[i],timB[i]);
	}
}
int countString(string x[]){
	int i,count=0;
	for(i=0;i<8;i++){
		if(strcmp(x[i],"-")!=0) count++;
	}
	return count;
}
