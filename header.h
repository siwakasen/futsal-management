#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TimMax 16
#define PemainMax 20
typedef char string[50];

typedef struct {
	string namaPemain;
	int noPunggung;
	float harga;
}Pemain;
typedef struct {
	string username;
	string password;
	string namaTim;
	float saldo;
	Pemain pemain[PemainMax];
}Tim;



void init(Tim tim[]);
void testInit(Tim tim[]);

void makeCaptcha();

int cekLoginAdmin(string username, string password);
void gotoLoginPanitia();
void gotoPanitiaMenu();
int LoginManager(Tim tim[]);

/////////////////////////////////////////////////////////
int menuTim(Tim tim[],int id);

int loginTim(Tim tim[],string username,string password);

Pemain makePemain(string nama,int no,float harga);

int cekJumlahPemain(Tim tim);
int cekNoPunggungPemain(Pemain pemain[], int cek);

int findTimByNama(Tim tim[],string search);
int findPemainByNoPunggung(Pemain pemain[], int search);

void bubbleSortPemain(Pemain pemain[]);
int tampilPemain(Pemain pemain);
int tampilPemainTim(Pemain pemain[]);
