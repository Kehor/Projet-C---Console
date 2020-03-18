#define WIN() system("@cls||clear");printf("\n\tYOU WIN\n\n\t\t\\O/   YEAHH !!\n\t\t |\n\t\t/ \\\n\n\t");wordtofind(size,fWord);

size_t strlen(const char* chaine);
void* malloc(size_t octets);
char* strchr(const char* chaine, int letter);
FILE* fopen(const char* nomDuFichier, const char* modeOuverture);
int fclose(FILE* pointeurSurFichier);
char* fgets(char* chaine, int nbreDeCaracteresALire, FILE* pointeurSurFichier);
char* strcpy(char* copieDeLaChaine, const char* chaineACopier);

void wordtofind(int size, char *fWord);
int test(char *sWord,char uLetter,char *fWord,int size);
char read();
void pendu(int coups,int size,char *fWord);
void word(char *sword);