#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#define ESC 27
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

typedef struct{
	string a,b;
}Relation;
Tim createTim(string nama, string user, string pass, float saldo);
void init(Tim tim[]);
void initPemain(Tim *T);
void makeCaptcha();
bool check_username_tim(Tim tim[], string user);
bool cekLogin(string username, string password);
int getEmptyTim(Tim tim[]);
int getCertainTim(Tim tim[], string name);
bool isEmptyTim(Tim tim[]);
void gotoLoginPanitia();
void gotoPanitiaMenu(Tim tim[]);
void showAll(Tim tim[]);
void showPemain(Pemain pemain[]);
void showTim(Tim tim[], int i);

void quickSortTim(Tim tim[], int low, int high);
int lomutoTim(Tim tim[], int low, int high);
void swapTim(Tim *X, Tim *Y);
void quickSortPemain(Pemain pemain[], int low, int high);
int lomutoPemain(Pemain pemain[], int low, int high);
void swapPemain(Pemain *X, Pemain *Y);

int countTim(Tim tim[]);
bool countPlayer(Tim tim[]);
void splitTimInto2(Tim tim[], string timA[], string timB[]);
void showMatch(Relation r[],string timA[]);
int countString(string x[]);
void matchRelation(Relation r[], string timA[], string timB[]);
////////////////////////////////////////////////////////////////////////////
int LoginManager(Tim tim[]);
int loginTim(Tim tim[],string username,string password);
int menuTim(Tim tim[], int id);
Pemain makePemain(string nama,int no,float harga);

int cekJumlahPemain(Tim tim);
int cekNoPunggungPemain(Pemain pemain[], int cek);

int findTimByNama(Tim tim[],string search);
int findPemainByNoPunggung(Pemain pemain[], int search);

void bubbleSortPemain(Pemain pemain[]);
int tampilPemain(Pemain pemain);
int tampilPemainTim(Pemain pemain[]);
