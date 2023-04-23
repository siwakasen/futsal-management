#include "header.h"

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

int LoginManager(Tim tim[]){
	string user,pass;
	int cekLogin=-1;
	int i;
	printf("\n\tUsername: ");fflush(stdin);gets(user);
	printf("\tPassword: ");fflush(stdin);gets(pass);
	cekLogin=loginTim(tim,user,pass);
	if(cekLogin>=0){
		printf("\n\tLogin Berhasil...");
	}else{
		printf("\n\tUsername/Password salah!");
	}
	return cekLogin;
}
