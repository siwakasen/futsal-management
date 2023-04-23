#include "header.h"

Pemain makePemain(string nama,int no,float harga){
	Pemain pemain;
	strcpy(pemain.namaPemain,nama);
	pemain.noPunggung = no;
	pemain.harga = harga;
	return pemain;
}


