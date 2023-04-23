#include "header.h"

void bubbleSortPemain(Pemain pemain[]){
	int i,swap;
	Pemain temp;
	do{
		swap=0;
		for(i=0;i<PemainMax-1;i++){
			if(pemain[i].noPunggung !=0 && pemain[i].noPunggung > pemain[i+1].noPunggung){
				temp = pemain[i];
				pemain[i] = pemain[i+1];
				pemain[i+1] = temp;
				swap=1;
			}
		}
	}while(swap);
}


int tampilPemain(Pemain pemain){
	printf("\n\tNomor Punggung: %d",pemain.noPunggung);
	printf("\nNama\t\t: %s",pemain.namaPemain);
	printf("\nHarga\t\t: Rp.%.2f\n",pemain.harga);
}

int tampilPemainTim(Pemain pemain[]){
	int i;
	Pemain temp[PemainMax];
	for(i=0;i<PemainMax;i++){
		temp[i]=pemain[i];
	}
	bubbleSortPemain(temp);
	
	for(i=0;i<PemainMax;i++){
		if(strcmp(temp[i].namaPemain,"-")!=0){
			tampilPemain(temp[i]);
		}
	}
	
}
