
#include "header.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char menu;
	Tim tim[TimMax];
	init(tim);
	
	while(1){
		printf("[1]. Panitia");
		printf("\n[2]. Manager");
		menu=getch();
		switch(menu){
			case '1':
				gotoLoginPanitia();
				break;
			case '2':
				//gotoManager();
				break;
			default:
				printf("\nMenu tidak ada");
		}
	}
	return 0;
}
