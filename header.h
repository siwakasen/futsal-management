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
void makeCaptcha();

int cekLogin(string username, string password);
int cekEmptyTim();

void gotoLoginPanitia();
void gotoPanitiaMenu();
