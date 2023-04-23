
#include "header.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char menu;
	Tim tim[TimMax];
	init(tim);
	testInit(tim);
	int cekLoginTim;
	while(1){
		system("cls");
		printf("[1]. Panitia");
		printf("\n[2]. Manager");
		menu=getch();
		switch(menu){
			case '1':
				gotoLoginPanitia();
				break;
			case '2':
				cekLoginTim = LoginManager(tim);
				if(cekLoginTim>=0){
					menuTim(tim,cekLoginTim);
				}
				break;
			default:
				printf("\nMenu tidak ada");
				getch();
		}
	}
	return 0;
}
