#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "Pendu.h"

int main(int argc,char **argv){
    char words[100], uLetter,*fWord = NULL,*sWord = NULL;
    int i = 0,coups = 10, size = 0,wordp = 0, win = 0,cookie = 0;
	word(words);
	sWord = malloc(strlen(words) * sizeof(char));
	strcpy(sWord,words);
    size = strlen(sWord);
 	fWord = malloc(size * sizeof(char));
	 if (fWord == NULL){exit(0);}
	for(i = 0; i < size; i++){
		fWord[i]='_';
	}
	while(coups != 0 && win==0){
		cookie=0;
		system("@cls||clear");
		pendu(coups,size,sWord);
	    wordtofind(size,fWord);
	    uLetter=read();
	    if((wordp = test(sWord,uLetter,fWord,size)) != 1){
	    	for(i = 0; i < size; i++){
	    		if(fWord[i] != '_') cookie++;
	    	}
	    	if(cookie >= size) win=1;
    	}else{
			coups--;
		}
		
	}
	if(win==1){
		WIN()
	}else pendu(coups,size,sWord);
    free(fWord);
	scanf("%c");

return 0;
}

void word(char *sword){
	int nbW=0,i = 0;
	char letter;
	FILE* file = NULL;
	file = fopen("mots.txt", "r");
srand(time(NULL));
	do{
		letter = fgetc(file); // On lit le caractère
		if(letter=='\n')nbW++;
	} while (letter != EOF);
	i=rand()%nbW;
	rewind(file);
	while (i > 0){
    letter = fgetc(file);
    if (letter == '\n') i--;
}

fgets(sword, 100, file);

// On vire le \n à la fin
sword[strlen(sword) - 1] = '\0';
	fclose(file);
}

void wordtofind(int size, char *fWord){
    int i;
    for(i = 0; i < size; i++){
        printf("%c ",fWord[i]);
    }
}

int test(char *sWord,char uLetter,char *fWord,int size){
	int i = 1,ok= 0;
	for (i = 0; i < size; i++){
		if (sWord[i] == uLetter){
			fWord[i]=sWord[i];
			ok++;
		}
	}
	if(ok != 0)return 0;
	return 1;
}

char read(){ 
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) 
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu 
}
void pendu(int coups,int size,char *fWord){
	
	switch(coups){
		case 9:
			printf("Nombre de coups : %d/10\n\n\n\n\n\n\t       __|\n\n",coups);
			break;
		case 8:
			printf("Nombre de coups : %d/10\n\n\n\n\n\t         |\n\t         |\n\t       __|\n\n",coups);
			break;
		case 7:
			printf("Nombre de coups : %d/10\n\n\n\n\t         |\n\t         |\n\t         |\n\t         |\n\t       __|\n\n",coups);
			break;
		case 6:
			printf("Nombre de coups : %d/10\n\n\n\t  |------|\n\t         |\n\t         |\n\t         |\n\t         |\n\t       __|\n\n",coups);
			break;
		case 5:
			printf("Nombre de coups : %d/10\n\n\n\t  |------|\n\t  O      |\n\t         |\n\t         |\n\t         |\n\t       __|\n\n",coups);
			break;
		case 4:
			printf("Nombre de coups : %d/10\n\n\n\t  |------|\n\t  O      |\n\t /|\\     |\n\t         |\n\t         |\n\t       __|\n\n",coups);
			break;
		case 3:
			printf("Nombre de coups : %d/10\n\n\n\t  |------|\n\t  O      |\n\t /|\\     |\n\t / \\     |\n\t         |\n\t       __|\n\n",coups);
			break;
		case 2:
			printf("Nombre de coups : %d/10\n\n\n\t  |------|\n\t  O      |\n\t /|\\     |\n\t / \\     |\n\t|'''|    |\n\t|   |  __|\n\n",coups);
			break;
		case 1:
			printf("Nombre de coups : %d/10\n\n\n\t  |------|\n\t  O NOOO!|\n\t /|\\     |\n\t / \\     |\n\t  |'''|  |\n\t  |   |__|\n\n",coups);
			break;
		case 0:
		system("@cls||clear");
			printf("Nombre de coups : %d/10\n\n\tGAME OVER!\n\t  |------|\n\t  O      |\n\t /|\\     |\n\t / \\     |\n\t         |\n\t       __|\n\n",coups);wordtofind(size,fWord);
			break;
	}
}