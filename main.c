
#include "header.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char menu;
	Tim tim[TimMax];
	init(tim);
	srand(time(NULL));
	do{
		system("cls");
		printf("\n\t--== Registrasi Tim Futsal ==--\n");
		printf("\n[1]. Panitia");
		printf("\n[2]. Manager");
		printf("\n[ESC]. Exit");
		printf("\n>>> ");
		menu=getch();
		switch(menu){
			case '1':
				gotoLoginPanitia();
				gotoPanitiaMenu(tim);
				break;
			case '2':
				//gotoManager();
				break;
			case 27:
				printf("\n[!] Keluar dari program . . .");
			break;
			default:
				printf("\n\t[!] Menu tidak tersedia");
			break;
		}getch();
	}while(menu!=27);
	return 0;
}
