#include "header.h"

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
