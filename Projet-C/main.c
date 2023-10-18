#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>


#define ENTEr 13
#define BKSP 8
#define SPACE 32
#define TAB 9



struct utilisateur
{
	char code[8];
	char nom[30];
	char password[8];
	char c;

};
typedef struct utilisateur user;


// fonctions des differents menu;
void wel_come(void);
void identification();
void MenuPrincipal();


// fonction des différentes parties;
void aleatoire();
void manuelle();


void main(void)
{
	wel_come();    // appeler la fonction ecran de bienvenue
	identification();   // appeler la fonction identifie
	MenuPrincipal(); // appeler le menu de choix


}


void wel_come(void)
{
	time_t t;
	time(&t);
	printf("                                                                                                         \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t%s", ctime(&t));
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t==================================\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t|\t     BIENVENUE DANS VOTRE \t |\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t|\tLOGICIEL DE SIMULATION\t |\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t==================================\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t       AUTEURS: T & Y &  K        \t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t     NIVEAU: 3A  \t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t      \"NOUS CROYONS A LA QUALITE\"\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|Appuyez entrer pour continuer.........\t\t\t\t\t\t\t\t\t\t|\n");

	printf("---------------------------------------------------------------------------------------------------------\n");

	getch();
	system("cls");

}

void identification()
{
	int a = 0, i = 0;
	char nomutilisateur[10];
	char c;
	char modedepasse[10], code[10];
	char utlisateur[10] = "FISA";
	char motdepasse[10] = "1234";
	do
	{
		printf("\n  ========================  IDENTIFICATION   ========================  ");
		printf(" \n                        NOM UTILISATEUR:-");
		scanf("%s", &nomutilisateur);
		printf(" \n                        MOT DE PASSE:-");
		while (i < 10)
		{
			motdepasse[i] = getch();
			c = motdepasse[i];
			if (c == 13) break;
			else printf("*");
			i++;
		}
		motdepasse[i] = '\0';
		//char code=pword;
		i = 0;
		//scanf("%s",&pword);
		if (strcmp(nomutilisateur, "FISA") == 0 && strcmp(motdepasse, "1234") == 0)
		{
			printf("  \n\n\n    SOYEZ LA BIENVENUE: NOUS Allons Commencer !!!! ID ET MOT DE PASSE CORRECTS");
			printf("\n\n\n\t\t\t\tappuyez sur la touche entrer pour continuer...");
			getch();//arr te l'ecran
			break;
		}
		else
		{
			printf("\n        DESOLE !!!!  IDENTIFIANT N'EST PAS CORRECTE");
			a++;

			getch();//arr te l'ecran

		}
	} while (a <= 2);
	if (a > 2)
	{
		printf("\nDesole vous entrer le mauvais mot de passe et le nom d'utlisateur   04 reprises!!!");

		getch();

	}
	system("cls");

}

void MenuPrincipal(void) {
	int choix;
	system("cls");
main:
	do {
		printf("\n======================== Faites un choix ========================");
		printf("                                                                                          ");
		printf("                                                                                          ");
		printf("\n\t\tAppuyer <1> Remplissage Aleatoire");
		printf("\n\t\tAppuyer <2> Remplissage Manuel");
        printf("\n\t\tAppuyer <0> Quitter");

		printf("\n\n\tEentrer votre choix[0-2]:\t");
		scanf("%i", &choix);
		system("cls");
		switch (choix) {

		case 1:
            manuelle();

			break;

		case 2:
            aleatoire();

			break;
			//getch();

		}
		//system("cls");
	} while (choix != 2);

}

// Fonction aleatoire;


char symboleAleatoire() {
    char symbole[] = { '+', ' ', '*', 'x', '#', '/', '-', '@' };
    int taille = sizeof(symbole) - 1;
    //recuperer un chiffre aleatoire entre 0 et la taille de mon tableau -1
    srand(time(NULL));
    int index = rand() % taille;
    // retourne un symbole de facon aleatoire
    return symbole[index];
}



#define SOL '+'
#define ARBRE '*'
#define FEUILLE ' '
#define ROCHE '#'
#define HERBE 'x'
#define EAU '/'
#define CENDRES '-'
#define CENDRES_ETEINTES '@'

void lancerFeu(int x, int y, char** matrice, int* degres, int* etats) {
    char typeCellule = matrice[x][y];


    if (etats[typeCellule] == 1 && degres[typeCellule] == 2) {
        matrice[x][y] = '-';
        degres[typeCellule] = degres[CENDRES];
        printf("Feu lancé sur la position [%d][%d]\n", x, y);
        printf("Mise à jour du degré : %d\n", degres[typeCellule]);

    }

    if (etats[typeCellule] == 1 && degres[typeCellule] > 2) {
        printf("Feu lancé sur la position [%d][%d]\n", x, y);
        degres[typeCellule]--; // Diminuer le degré
        printf("Mise à jour du degré : %d\n", degres[typeCellule]);
    }

    if (matrice[x][y] == '-') {
        printf("Feu lancé sur la position [%d][%d]\n", x, y);
        degres[typeCellule] = degres[CENDRES_ETEINTES];
        etats[typeCellule] = etats[CENDRES_ETEINTES];
        printf("Position [%d] [%d] : Mise à jour du degré : %d || Mise à jour de l'état (1 = en feu, 0 = pas en feu) : %d \n", x, y, degres[typeCellule], etats[typeCellule]);
        matrice[x][y] = '@'; // Transformation de la cendre en cendre éteinte
    }


}




void aleatoire(void) {
    char nom[50];
    int longueur, largeur;
    char** matrice = NULL;
    int i, j;


    printf("Entrez la longueur de la forêt : ");
    scanf("%d", &longueur);
    printf("Entrez la largeur de la forêt : ");
    scanf("%d", &largeur);

    // Allocation Matrice
    matrice = malloc(longueur * sizeof(char*));

    for (i = 0; i < longueur; i++) {
        matrice[i] = malloc(largeur * sizeof(char));
    }



    int degres[128] = { 0 }; // Initialisés à zéro
    int etats[128] = { 0 };  // Initialisés à zéro
    degres[SOL] = 0;
    degres[ARBRE] = 4;
    degres[FEUILLE] = 2;
    degres[ROCHE] = 5;
    degres[HERBE] = 3;
    degres[EAU] = 0;
    degres[CENDRES] = 1;
    degres[CENDRES_ETEINTES] = 0;



    // Affichage de la forêt
    for (i = 0; i < longueur; i++) {
        for (j = 0; j < largeur; j++) {
            printf("+---");
        }
        printf("+\n");

        for (j = 0; j < largeur; j++) {
            printf("| ");
            matrice[i][j] = symboleAleatoire();

            switch (matrice[i][j]) {
            case '+':
                printf("+ ");
                break;
            case '*':
                printf("* ");
                break;
            case ' ':
                printf("  ");
                break;
            case '#':
                printf("# ");
                break;
            case 'x':
                printf("x ");
                break;
            case 'X':
                printf("x ");
                break;
            case '/':
                printf("/ ");
                break;
            case '-':
                printf("- ");
                break;
            case '@':
                printf("@ ");
                break;
            default:
                printf("INCONNU ");
            }
        }
        printf("|\n");


        for (j = 0; j < largeur; j++) {
            printf("+---");
        }
        printf("+\n");



        // Etat de chaque cellule
        int degre;
        if (matrice[i][j] == '+') {
            degre = 0;
        }
        if (matrice[i][j] == '*') {
            degre = 4;
        }
        if (matrice[i][j] == ' ') {
            degre = 2;
        }
        if (matrice[i][j] == '#') {
            degre = 5;
        }
        if (matrice[i][j] == 'x') {
            degre = 3;
        }
        if (matrice[i][j] == '/') {
            degre = 0;
        }
        if (matrice[i][j] == '-') {
            degre = 1;
        }
        if (matrice[i][j] == '@') {
            degre = 0;
        }
    }



    //Effet propagation du feu
    int x, y;
    printf("Entrez la position x dans laquelle le feu se propagera : ");
    scanf("%d", &x);
    printf("Entrez la position y dans laquelle le feu se propagera : ");
    scanf("%d", &y);
    lancerFeu(x, y, matrice, degres, etats);

    // Affichage de la nouvelle forêt
    printf("Mise à jour de la forêt : \n");
    for (i = 0; i < longueur; i++) {
        for (j = 0; j < largeur; j++) {
            printf("+---");
        }
        printf("+\n");

        for (j = 0; j < largeur; j++) {
            printf("| ");
            switch (matrice[i][j]) {
            case '+':
                printf("+ ");
                break;
            case '*':
                printf("* ");
                break;
            case ' ':
                printf("  ");
                break;
            case '#':
                printf("# ");
                break;
            case 'x':
                printf("x ");
                break;
            case 'X':
                printf("x ");
                break;
            case '/':
                printf("/ ");
                break;
            case '-':
                printf("- ");
                break;
            case '@':
                printf("@ ");
                break;
            default:
                printf("INCONNU ");
            }
        }
        printf("|\n");


        for (j = 0; j < largeur; j++) {
            printf("+---");
        }
        printf("+\n");
    }




    // Destruction Matrice
    for (i = 0; i < longueur; i++) {
        free(matrice[i]);
        matrice[i] = NULL;
    }

    free(matrice);
    matrice = NULL;


}




// Fonction Manuelle;




#define SOL '+'
#define ARBRE '*'
#define FEUILLE ' '
#define ROCHE '#'
#define HERBE 'x'
#define EAU '/'
#define CENDRES '-'
#define CENDRES_ETEINTES '@'

void LancerFeu(int x, int y, char** matrice, int* degres, int* etats) {
    char typeCellule = matrice[x][y];


    if (etats[typeCellule] == 1 && degres[typeCellule] == 2) {
        matrice[x][y] = '-';
        degres[typeCellule] = degres[CENDRES];
        printf("Feu lancé sur la position [%d][%d]\n", x, y);
        printf("Mise à jour du degré : %d\n", degres[typeCellule]);

    }

    if (etats[typeCellule] == 1 && degres[typeCellule] > 2) {
        printf("Feu lancé sur la position [%d][%d]\n", x, y);
        degres[typeCellule]--; // Diminuer le degré
        printf("Mise à jour du degré : %d\n", degres[typeCellule]);
    }

    if (matrice[x][y] == '-') {
        printf("Feu lancé sur la position [%d][%d]\n", x, y);
        degres[typeCellule] = degres[CENDRES_ETEINTES];
        etats[typeCellule] = etats[CENDRES_ETEINTES];
        printf("Position [%d] [%d] : Mise à jour du degré : %d || Mise à jour de l'état (1 = en feu, 0 = pas en feu) : %d \n", x, y, degres[typeCellule], etats[typeCellule]);
        matrice[x][y] = '@'; // Transformation de la cendre en cendre éteinte
    }


}




void manuelle(void) {
    char nom[50];
    int longueur, largeur;
    char** matrice = NULL;
    int i, j;


   /* printf("Entrez le nom de l'utilisateur : ");
    scanf("%s", &nom);
    printf("Bonjour %s ! \n", nom);*/

    printf("Entrez la longueur de la forêt : ");
    scanf("%d", &longueur);
    printf("Entrez la largeur de la forêt : ");
    scanf("%d", &largeur);

    // Allocation Matrice
    matrice = malloc(longueur * sizeof(char*));

    for (i = 0; i < longueur; i++) {
        matrice[i] = malloc(largeur * sizeof(char));
    }

    // Entrée des valeurs
    for (i = 0; i < longueur; i++) {
        for (j = 0; j < largeur; j++) {
            printf("Entrez la valeur pour [%d][%d] ", i, j);
            scanf(" %c", &matrice[i][j]);
        }
    }


    int degres[128] = { 0 }; // Initialisés à zéro
    int etats[128] = { 0 };  // Initialisés à zéro
    degres[SOL] = 0;
    degres[ARBRE] = 4;
    degres[FEUILLE] = 2;
    degres[ROCHE] = 5;
    degres[HERBE] = 3;
    degres[EAU] = 0;
    degres[CENDRES] = 1;
    degres[CENDRES_ETEINTES] = 0;



    // Affichage de la forêt
    for (i = 0; i < longueur; i++) {
        for (j = 0; j < largeur; j++) {
            printf("+---");
        }
        printf("+\n");

        for (j = 0; j < largeur; j++) {
            printf("| ");
            switch (matrice[i][j]) {
            case '+':
                printf("+ ");
                break;
            case '*':
                printf("* ");
                break;
            case ' ':
                printf("  ");
                break;
            case '#':
                printf("# ");
                break;
            case 'x':
                printf("x ");
                break;
            case 'X':
                printf("x ");
                break;
            case '/':
                printf("/ ");
                break;
            case '-':
                printf("- ");
                break;
            case '@':
                printf("@ ");
                break;
            default:
                printf("INCONNU ");
            }
        }
        printf("|\n");


        for (j = 0; j < largeur; j++) {
            printf("+---");
        }
        printf("+\n");



        // Etat de chaque cellule
        int degre;
        if (matrice[i][j] == '+') {
            degre = 0;
        }
        if (matrice[i][j] == '*') {
            degre = 4;
        }
        if (matrice[i][j] == ' ') {
            degre = 2;
        }
        if (matrice[i][j] == '#') {
            degre = 5;
        }
        if (matrice[i][j] == 'x') {
            degre = 3;
        }
        if (matrice[i][j] == '/') {
            degre = 0;
        }
        if (matrice[i][j] == '-') {
            degre = 1;
        }
        if (matrice[i][j] == '@') {
            degre = 0;
        }
    }



    //Effet propagation du feu
    int x, y;
    printf("Entrez la position x dans laquelle le feu se propagera : ");
    scanf("%d", &x);
    printf("Entrez la position y dans laquelle le feu se propagera : ");
    scanf("%d", &y);
    LancerFeu(x, y, matrice, degres, etats);

    // Affichage de la nouvelle forêt
    printf("Mise à jour de la forêt : \n");
    for (i = 0; i < longueur; i++) {
        for (j = 0; j < largeur; j++) {
            printf("+---");
        }
        printf("+\n");

        for (j = 0; j < largeur; j++) {
            printf("| ");
            switch (matrice[i][j]) {
            case '+':
                printf("+ ");
                break;
            case '*':
                printf("* ");
                break;
            case ' ':
                printf("  ");
                break;
            case '#':
                printf("# ");
                break;
            case 'x':
                printf("x ");
                break;
            case 'X':
                printf("x ");
                break;
            case '/':
                printf("/ ");
                break;
            case '-':
                printf("- ");
                break;
            case '@':
                printf("@ ");
                break;
            default:
                printf("INCONNU ");
            }
        }
        printf("|\n");


        for (j = 0; j < largeur; j++) {
            printf("+---");
        }
        printf("+\n");
    }




    // Destruction Matrice
    for (i = 0; i < longueur; i++) {
        free(matrice[i]);
        matrice[i] = NULL;
    }

    free(matrice);
    matrice = NULL;

 
}


