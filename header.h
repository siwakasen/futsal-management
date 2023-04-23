#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <math.h>
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


Tim createTim(string nama, string user, string pass, float saldo);
void init(Tim tim[]);
void initPemain(Tim *T);
void makeCaptcha();
bool check_username_tim(Tim tim[], string user);
bool cekLogin(string username, string password);
int getEmptyTim(Tim tim[]);
int getCertainTim(Tim tim[], string name);

void gotoLoginPanitia();
void gotoPanitiaMenu(Tim tim[]);
void showAll(Tim tim[]);
void showPemain(Pemain pemain[]);

void quickSortTim(Tim tim[], int low, int high);
int lomutoTim(Tim tim[], int low, int high);
void swapTim(Tim *X, Tim *Y);
void quickSortPemain(Pemain pemain[], int low, int high);
int lomutoPemain(Pemain pemain[], int low, int high);
void swapPemain(Pemain *X, Pemain *Y);

int countTim(Tim tim[]);
bool countPlayer(Tim tim[]);
void createMatch(Tim tim[], string timA[], string timB[]);
void showMatch(string timA[], string timB[]);
int countString(string x[]);
