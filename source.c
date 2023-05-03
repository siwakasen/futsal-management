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
		printf("\n\t[Login Panitia]");
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


void showAll(Tim tim[]){
	int i;
	for(i=0;i<TimMax;i++){
		if(strcmp(tim[i].namaTim,"-")!=0){
			showTim(tim,i);
			printf("\n");
			showPemain(tim[i].pemain);
		}
	}
}
void showPemain(Pemain pemain[]){
	int j;
	for(j=0;j<PemainMax;j++){
		if(strcmp(pemain[j].namaPemain,"-")!=0){
			printf("\n\t\tNama Pemain    : %s",pemain[j].namaPemain);
			printf("\n\t\tNomor Punggung : %d",pemain[j].noPunggung);
			printf("\n\t\tHarga Pemain   : %.2f",pemain[j].harga);
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
	int pivot=pemain[high].noPunggung;
	int i=(low-1);
	int j;
	for(j=low;j<high;j++){
		if(pemain[j].noPunggung<=pivot){
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

void splitTimInto2(Tim tim[], string timA[], string timB[]){
	
	int i,j=0,k=0;
	char random;
	//init string team
	for(i=0;i<8;i++){
		strcpy(timA[i],"-");
		strcpy(timB[i],"-");
	}
	//split into 2 team
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
void matchRelation(Relation r[], string timA[], string timB[]){
	bool alreadyTaken[countString(timB)];
	int i;
	for(i=0;i<8;i++){
		strcpy(r[i].a,"-");
		strcpy(r[i].b,"-");
	}
	int saveTimB;

	//init team B, semua blm punya opponent
	for(i=0;i<countString(timB);i++){
		alreadyTaken[i]=false;
	}
	//bikin relasi antara tim A sm tim B
	for(i=0;i<countString(timA);i++){
		 strcpy(r[i].a,timA[i]);
		 do{
			saveTimB=(rand()% ((countString(timB)-1) - 0 +1)+0);
		 }while(alreadyTaken[saveTimB]);
		 alreadyTaken[saveTimB]=true;
		 strcpy(r[i].b,timB[saveTimB]);
	}
}
void showMatch(Relation r[],string timA[]){
	int i;
	printf("\n\t[Bracket Pertandingan]");
	for(i=0;i<countString(timA);i++){
		printf("\n\t[%s] VS [%s]",r[i].a,r[i].b);
	}
}
int countString(string x[]){
	int i,count=0;
	for(i=0;i<8;i++){
		if(strcmp(x[i],"-")!=0) count++;
	}
	return count;
}
void showTim(Tim tim[], int i){
	printf("\n\tNama Tim : %s", tim[i].namaTim);
	printf("\n\tUsername : %s",tim[i].username);
	printf("\n\tPassword : %s",tim[i].password);
	printf("\n\tSaldo    : %.2f",tim[i].saldo);
}
bool isEmptyTim(Tim tim[]){
	int i;
	for(i=0;i<TimMax;i++){
		if(strcmp(tim[i].namaTim,"-")!=0) return false;
	}
	return true;
}
