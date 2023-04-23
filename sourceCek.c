#include "header.h"

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
