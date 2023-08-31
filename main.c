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



    void main(void)
    {
       wel_come();    // appeler la fonction ecran de bienvenue
       identification();   // appeler la fonction identifie

    }


    void wel_come(void)
    {
        time_t t;
        time(&t);
        printf("                                                                                                         \n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t%s",ctime(&t));
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
        int a=0, i=0;
        char nomutilisateur[10];
        char c;
        char modedepasse[10],code[10];
        char utlisateur[10]="FISA";
        char motdepasse[10]="1234";
        do
        {
           printf("\n  ========================  IDENTIFICATION   ========================  ");
    printf(" \n                        NOM UTILISATEUR:-");
	scanf("%s", &nomutilisateur);
	printf(" \n                        MOT DE PASSE:-");
	while(i<10)
	{
	    motdepasse[i]=getch();
	    c=motdepasse[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	motdepasse[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(nomutilisateur,"FISA")==0 && strcmp(motdepasse,"1234")==0)
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
}
	while(a<=2);
	if (a>2)
	{
		printf("\nDesole vous entrer le mauvais mot de passe et le nom d'utlisateur   04 reprises!!!");

		getch();

		}
		system("cls");

        }



