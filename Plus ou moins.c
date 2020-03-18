#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(int max,int min){
    int nbMystere,nbUser,nbCoups,continuerPartie = 1;
    char replay;
    while(continuerPartie!=0){
        nbUser=nbCoups=0;
        system("@cls||clear");
        srand(time(NULL));
        nbMystere = (rand()%(max-min+1))+min;
        printf("trouve le nombre entre %d et %d :\n",min,max);
        while(nbUser != nbMystere){
            nbCoups++;
            scanf("%d", &nbUser);
            if(nbUser < nbMystere){
                printf("Plus\n");
            }else if(nbUser > nbMystere){
                printf("Moins\n");
            }
        }
        printf("Bravo vous avez trouver en %d coups\nLe nombre Mystere est %d",nbCoups,nbMystere);
        printf("\n\n\tVoulez vous rejouer ? [Y/N]\n\t > ");
        scanf(" %c",&replay);
        if(replay == 'N' || replay =='n'){
            continuerPartie=0;
        }
    }
    return 0;
}

int main (int argc,char **argv){
    int choix = 0;
    system("@cls||clear");
    while(choix < 1 || choix > 3){
        printf("\n\t1 = entre 1 et 100\n\t2 = entre 1 et 1000\n\t3 = entre 1 et 10000\n\nChoisi un niveaux de difficulte : ");
        scanf("%d",&choix);
    }
    switch (choix){
        case 1:
            game(100,1);
            break;
        case 2:
            game(1000,1);
            break;
        case 3:
            game(10000,1);
            break;
    }
    return 0;
}
