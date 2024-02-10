#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#define MAX_SIZE 80

#define SOL '+'
#define ARBRE '*'
#define FEUILLE ' '
#define ROCHE '#'
#define HERBE 'x'
#define EAU '/'
#define CENDRES '-'
#define CENDRES_ETEINTES '@'

#define dSOL 0
#define dARBRE 4
#define dFEUILLE 2
#define dROCHE 5
#define dHERBE 3
#define dEAU 0
#define dCENDRES 1
#define dCENDRES_ETEINTES 0

#define TMAX 20



// Fonctions des interfaces;



struct utilisateur
{
    char code[8];
    char nom[30];
    char password[8];
    char c;

};
typedef struct utilisateur user;

void color(int t, int f)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, f * 16 + t);
}
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    //cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void cadre(long int x1, long int x2, long int y1, long int y2)
{
    int i;
    for (i = x1; i <= x2; i++) {
        gotoxy(i, y1);
        printf("%c", 196);
        gotoxy(i, y2);
        printf("%c", 196);
    }
    for (i = y1; i <= y2; i++) {
        gotoxy(x1, i);
        printf("%c", 179);
        gotoxy(x2, i);
        printf("%c", 179);
    }
    gotoxy(x1, y1);
    printf("%c", 218);
    gotoxy(x2, y1);
    printf("%c", 191);
    gotoxy(x1, y2);
    printf("%c", 192);
    gotoxy(x2, y2);
    printf("%c", 217);

}
void ASCII() {
    int i;
    for (i = 0; i < 256; i++) {
        printf("%c=%d\t\t", i, i);
        if (i % 7 == 0) {
            printf("\n\n");
        }
    }
}

int home() {
    color(0, 15);
    gotoxy(15, 2);
    system("cls");
    int i, j = 0, n, m, c_home = 7;
    char curs;
    gotoxy(25, 4);
    //printf(" BIENVENUE ");
    m = 1;
    do {
        for (i = 7;i <= 9;i = i + 2) {
            if (c_home == i) { color(12, 15); }
            else { color(0, 15); }
            gotoxy(15, i);
            // color(15, 0);
            color(0, 15);
            color(12, 15);
            j++;
        }
        curs = getch();

        if (curs == 13)
            return(c_home);
    } while (curs != 13);
}



// fonctions des differents menu;
void wel_come(void)
{
    system("COLOR f0");
    color(0, 15);
    gotoxy(15, 2);
    gotoxy(25, 4);
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
    printf("|\t\t\t\t|\t     BIENVENUE DANS VOTRE \t|\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t|\tLOGICIEL DE SIMULATION   \t|\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t==================================\t\t\t\t\t\t|\n");
    color(3, 15);
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
    color(0, 15);
    gotoxy(15, 2);
    gotoxy(25, 4);
    printf("---------------------------------------------------------------------------------------------------------\n");
    color(0, 15);
    gotoxy(15, 2);
    gotoxy(25, 4);

    getch();
    // system("pause");
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
        color(0, 15);
        //gotoxy(15, 2);
        printf("\n\t\t  ========================  IDENTIFICATION   ========================  ");
        printf(" \n\t\t                        NOM UTILISATEUR:-");
        scanf("%s", &nomutilisateur);
        printf(" \n\t\t                        MOT DE PASSE:-");
        while (i < 10)
        {
            color(0, 15);
            //gotoxy(15, 2);
            //gotoxy(25, 4);
            motdepasse[i] = getch();
            c = motdepasse[i];
            if (c == 13) break;
            else printf("*");
            i++;
            //system("cls");
        }
        motdepasse[i] = '\0';
        //char code=pword;
        i = 0;
        //scanf("%s",&pword);
        if (strcmp(nomutilisateur, "FISA") == 0 && strcmp(motdepasse, "1234") == 0)
        {
            color(3, 15);
            gotoxy(15, 2);
            gotoxy(25, 4);
            printf("  \n\n\n    SOYEZ LA BIENVENUE: NOUS Allons Commencer !!!! ID ET MOT DE PASSE CORRECTS");
            printf("\n\n\n\t\t\t\tappuyez sur la touche entrer pour continuer...");
            color(0, 15);
            getch();//arr te l'ecran
            break;
        }
        else
        {
            color(0, 15);
            printf("\n\t\t        DESOLE !!!!  IDENTIFIANT N'EST PAS CORRECTE");
            a++;

            getch();//arr te l'ecran

        }
    } while (a <= 2);
    if (a > 2)
    {
        color(3, 15);
        printf("\n\t\tDesole vous entrer le mauvais mot de passe et le nom d'utlisateur   04 reprises!!!");

        getch();

    }
    system("cls");

}


struct foret {
    int tour;
    char** foret;
    int** etats;
    int** degres;
    int longueur;
    int largeur;
    int** enFeu;
};

char getSymbole() {
    char symbole[] = { SOL,FEUILLE,ARBRE,HERBE,ROCHE,EAU,CENDRES,CENDRES_ETEINTES };
    int taille = sizeof(symbole) / sizeof(symbole[0]);
    int index = rand() % taille;
    return symbole[index];
}

void creationForet(struct foret* f, int longueur, int largeur) {
    f->tour = 0;
    f->longueur = longueur;
    f->largeur = largeur;

    f->foret = malloc(longueur * sizeof(char*));
    f->degres = malloc(longueur * sizeof(int*));
    f->etats = malloc(longueur * sizeof(int*));
    f->enFeu = malloc(longueur * sizeof(int*));

    for (int i = 0;i < longueur;i++) {
        f->foret[i] = malloc(largeur * sizeof(char));
        f->degres[i] = malloc(largeur * sizeof(int));
        f->etats[i] = malloc(largeur * sizeof(int));
        f->enFeu[i] = malloc(largeur * sizeof(int));
    }

}

void copie_foret(struct foret* f1, struct foret* f2) {
    int longueur = f1->longueur; int largeur = f1->largeur;
    creationForet(f2, longueur, largeur);;
    for (int i = 0;i < longueur;i++) {
        for (int j = 0;j < largeur;j++) {
            f2->etats[i][j] = f1->etats[i][j];
            f2->degres[i][j] = f1->degres[i][j];
            f2->foret[i][j] = f1->foret[i][j];
            f2->enFeu[i][j] = f1->enFeu[i][j];
        }
    }
}

void remplissageForet(int choix, struct foret* f) {
    int longueur = f->longueur;
    int largeur = f->largeur;
    if (choix) {
        for (int i = 0; i < longueur; i++) {
            color(1, 15);
            if (i % 2 == 0) color(6, 15);
            for (int j = 0; j < largeur; j++) {
                f->enFeu[i][j] = 0;
                //color(0, 15);
                printf("\n\t\tEntrez la valeur pour [%d][%d] ", i, j);
                //color(0, 15);
                scanf(" %c", &f->foret[i][j]);
                switch (f->foret[i][j]) {
                case SOL:
                    //color(1, 15);
                    f->degres[i][j] = dSOL;
                    break;
                case ARBRE:
                    //color(1, 15);
                    f->degres[i][j] = dARBRE;
                    break;
                case FEUILLE:
                    f->degres[i][j] = dFEUILLE;
                    break;
                case ROCHE:
                    f->degres[i][j] = dROCHE;
                    break;
                case HERBE:
                    f->degres[i][j] = dHERBE;
                    break;
                case EAU:
                    f->degres[i][j] = dEAU;
                    break;
                case CENDRES:
                    f->degres[i][j] = dCENDRES;
                    break;
                case CENDRES_ETEINTES:
                    f->degres[i][j] = dCENDRES_ETEINTES;
                    break;
                }
            }
        }
    }
    else {
        for (int i = 0; i < longueur; i++) {
            for (int j = 0; j < largeur; j++) {
                f->enFeu[i][j] = 0;
                f->etats[i][j] = 0;
                f->foret[i][j] = getSymbole();
                //color(0, 15);
                gotoxy(15, 2);
                gotoxy(25, 4);
                switch (f->foret[i][j]) {
                case SOL:
                    f->degres[i][j] = dSOL;
                    break;
                case ARBRE:
                    f->degres[i][j] = dARBRE;
                    break;
                case FEUILLE:
                    f->degres[i][j] = dFEUILLE;
                    break;
                case ROCHE:
                    f->degres[i][j] = dROCHE;
                    break;
                case HERBE:
                    f->degres[i][j] = dHERBE;
                    break;
                case EAU:
                    f->degres[i][j] = dEAU;
                    break;
                case CENDRES:
                    f->degres[i][j] = dCENDRES;
                    break;
                case CENDRES_ETEINTES:
                    f->degres[i][j] = dCENDRES_ETEINTES;
                    break;
                }
            }
        }
    }
}

void lancerFeu(int x, int y, struct foret* f) {
    char typeCellule = f->foret[x][y];
    //printf("Etat de la case %d %d : %d\n",x, y, f->etats[x][y]);

    // Vérifier que la case n'est pas déjà en feu
    if (f->etats[x][y] == 0 && (typeCellule != EAU && typeCellule != SOL))
    {
        f->enFeu[x][y] = 1;
        f->etats[x][y] = 1;  // Mettre la case en feu
        printf("\n\n\t\Feu lancé sur %c en position [%d][%d]\n", f->foret[x][y], x, y);
    }

}

void diminuerDeg(struct foret* f)
{
    int longueur = f->longueur;
    int largeur = f->largeur;
    for (int i = 0; i < longueur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            if (f->etats[i][j] == 1 && f->degres[i][j] != 0)
            {
                f->degres[i][j]--;
                if (f->degres[i][j] == 1) {
                    f->foret[i][j] = CENDRES;
                }
                else if (f->degres[i][j] == 0) {
                    f->foret[i][j] = CENDRES_ETEINTES;
                    f->degres[i][j] = 0;
                    f->etats[i][j] = 1;
                }
            }
            else if (f->etats[i][j] == 1 && f->degres[i][j] == 0)
            {
                f->degres[i][j] = 0;
            }
        }
    }
}

void propagationCase(struct foret* f1, struct foret* f2, int x, int y) {
    int longueur = f1->longueur; int largeur = f1->largeur;

    int voisinsX[] = { x - 1, x + 1, x, x, x - 1, x + 1, x - 1, x + 1 };
    int voisinsY[] = { y, y, y - 1, y + 1, y - 1, y + 1, y + 1, y - 1 };

    for (int i = 0;i < 8;i++) {
        int voisinX = voisinsX[i];
        int voisinY = voisinsY[i];

        if (voisinX >= 0 && voisinX < longueur && voisinY >= 0 && voisinY < largeur) {
            if (f1->etats[x][y] == 1 && f1->etats[voisinX][voisinY] == 0) {
                lancerFeu(voisinX, voisinY, f2);
            }
        }
    }
}
void propagationForet(struct foret* f1, struct foret* f2) {
    int i, j;
    int longueur = f1->longueur;
    int largeur = f1->largeur;
    copie_foret(f1, f2);
    for (i = 0;i < longueur;i++) {
        for (j = 0;j < largeur;j++) {
            propagationCase(f1, f2, i, j);
        }
    }
}


void afficherEtat(int x, int y, struct foret* f) {
    printf("L'état de la case %c en position [%d][%d] est : %d \n\t\t", f->foret[x][y], x, y, f->etats[x][y]);
}

void afficherDegre(int x, int y, struct foret* f) {
    printf("Le degré de la case %c en position [%d][%d] est : %d \n\t\t", f->foret[x][y], x, y, f->degres[x][y]);
}
void afficherForet(struct foret f) {
    printf("\n\t\tMise à jour de la forêt : \n\n");
    for (int i = 0; i < f.longueur; i++) {
        printf("\t\t");
        for (int j = 0; j < f.largeur; j++) {
            color(0, 15);
            printf("+---");
        }
        color(0, 15);
        printf("+\n");
        printf("\t\t");
        for (int j = 0; j < f.largeur; j++) {
            color(0, 15);
            printf("| ");
            switch (f.foret[i][j]) {
            case SOL:
                color(1, 15);
                printf("%c ", f.foret[i][j]);
                break;
            case ARBRE:
                color(2, 15);
                printf("%c ", f.foret[i][j]);
                break;
            case FEUILLE:
                color(3, 15);
                printf("%c ", f.foret[i][j]);
                break;
            case ROCHE:
                color(4, 15);
                printf("%c ", f.foret[i][j]);
                break;
            case HERBE:
                color(5, 15);
                printf("%c ", f.foret[i][j]);
                break;
            case EAU:
                color(6, 15);
                printf("%c ", f.foret[i][j]);
                break;
            case CENDRES:
                color(8, 15);
                printf("%c ", f.foret[i][j]);
                break;
            case CENDRES_ETEINTES:
                color(9, 15);
                printf("%c ", f.foret[i][j]);
                break;
            default:
                color(0, 15);
                printf("%c", f.foret[i][j]);
            }
        }
        color(0, 15);
        printf("|\n");
    }
    printf("\t\t");
    for (int j = 0; j < f.largeur; j++) {

        color(0, 15);
        printf("+---");
    }
    color(0, 15);
    printf("+\n");
}

void destructionForet(struct foret* f) {
    for (int i = 0; i < f->longueur; i++) {
        free(f->foret[i]);
        free(f->etats[i]);
        free(f->degres[i]);
        f->foret[i] = NULL;
        f->etats[i] = NULL;
        f->degres[i] = NULL;
    }
    free(f->foret);
    free(f->degres);
    free(f->etats);
    f->degres = NULL;
    f->etats = NULL;
    f->foret = NULL;
}

int main() {
    char nom[50];
    int tmax;
    int i, j;
    srand(time(NULL));
    int remp;
    int longueur, largeur;
    int t = 0;

    wel_come();
    identification();

    printf("\n\t\tEntrez la longueur de la forêt : ");
    scanf("%d", &longueur);
    printf("\n\t\tEntrez la largeur de la forêt : ");
    scanf("%d", &largeur);
    printf("\n\t\tEntrez le nombre de tour voulez vous : ");
    scanf("%d", &tmax);

    struct foret* f = malloc(tmax * sizeof(struct foret));

    printf("\n\t======================== Faites un choix ========================");
    printf("                                                                                          ");
    printf("                                                                                          ");
    printf("\n\t\tAppuyer <0> Remplissage Aléatoire");
    printf("\n\t\tAppuyer <1> Remplissage Manuelle");
    printf("\n\t\tEntrer votre choix[0-1]:\t");
    scanf("\n%d", &remp);
    system("cls");

    creationForet(&f[0], longueur, largeur);

    remplissageForet(remp, &f[0]);

    int x, y;
    int propagation = 1;
    int retour = 0;
    int options;
    while (propagation && t < tmax) {
        // Tant que nous sommes au tour 0
        while (t == 0)
        {
            afficherForet(f[t]);
            printf("\n\t\tVous êtes au tour %d\n\n", t);

            printf("\n\t======================== Que Voulez Vous Faire ========================");
            printf("                                                                                          ");
            printf("                                                                                          ");
            printf("\n\t\tAppuyer 1 Lancer la Propagation");
            printf("\n\t\tAppuyer 2 Modifier une Cellule");
            printf("\n\t\tAppuyer 3 Afficher l'état d'une Case");
            printf("\n\t\tAppuyer 4 Afficher le Degrés d'une Case");
            printf("\n\t\tEntrer votre choix[1-4]:\t");
            int choix;
            if (choix % 4 == 0) color(6, 15);
            scanf("%d", &choix);
            system("cls");
            if (choix == 2) {
                int x, y, newdeg, newetat, choixt, choixd, choixe;
                char newtype;

                printf("\n\t\tEntrez la position x de la case à modifier : ");
                scanf("%d", &x);
                printf("\n\t\tEntrez la position y de la case à modifier : ");
                scanf("%d", &y);
                printf("\n\t\tVoulez-vous modifier son type (1 pour OUI; 0 pour NON) ? \n\t\t");
                scanf("%d", &choixt);
                if (choixt) {
                    printf("\n\t\tEntrez son nouveau type : ");
                    scanf(" %c", &newtype);
                    f[t].foret[x][y] = newtype;
                    switch (f[t].foret[x][y]) {
                    case SOL:
                        f[t].degres[i][j] = dSOL;
                        break;
                    case ARBRE:
                        f[t].degres[i][j] = dARBRE;
                        break;
                    case FEUILLE:
                        f[t].degres[i][j] = dFEUILLE;
                        break;
                    case ROCHE:
                        f[t].degres[i][j] = dROCHE;
                        break;
                    case HERBE:
                        f[t].degres[i][j] = dHERBE;
                        break;
                    case EAU:
                        f[t].degres[i][j] = dEAU;
                        break;
                    case CENDRES:
                        f[t].degres[i][j] = dCENDRES;
                        break;
                    case CENDRES_ETEINTES:
                        f[t].degres[i][j] = dCENDRES_ETEINTES;
                        break;
                    }
                }

                printf("Voulez-vous modifier son degré (1 pour OUI; 0 pour NON) ? \n\t\t");
                scanf("%d", &choixd);

                if (choixd) {
                    int nvdeg;
                    printf("Entrez son nouveau degré : \n\t\t");
                    scanf("%d", &nvdeg);
                    f[t].degres[x][y] = nvdeg;
                }

                printf("Voulez-vous modifier son état (1 pour OUI; 0 pour NON) ? \n\t\t");
                scanf("%d", &choixe);

                if (choixe) {
                    int etat;
                    printf("Entrez son nouvel état : \n\t\t");
                    scanf("%d", &etat);
                    f[t].etats[x][y] = etat;
                }

            }
            else if (choix == 3) {
                int posX, posY;
                printf("\n\t\tEntrez la position x de la case à afficher : ");
                scanf("%d", &posX);
                printf("Entrez la position y de la case à afficher : ");
                scanf("%d", &posY);
                afficherEtat(posX, posY, &f[t]);
            }

            else if (choix == 4) {
                int posX, posY;
                printf("\n\t\tEntrez la position x de la case à afficher : ");
                scanf("%d", &posX);
                printf("\n\t\tEntrez la position y de la case à afficher : ");
                scanf("%d", &posY);
                afficherDegre(posX, posY, &f[t]);
            }
            else if (choix == 1)
            {
                printf("\t\tEntrez la position x de la case à mettre en feu : \n");
                scanf("%d", &x);
                printf("\t\tEntrez la position y de la case à mettre en feu :\n");
                scanf("%d", &y);
                t++;
                copie_foret(&f[t - 1], &f[t]);
                lancerFeu(x, y, &f[t]);
                afficherForet(f[t]);
            }
        }

        // Fin du tour 0 //

        printf("\n\t\tVous êtes au tour %d\n", t);
        printf("\n\t======================== Que Voulez Vous Faire ========================");
        printf("                                                                                          ");
        printf("                                                                                          ");
        printf("\n\t\tAppuyer 0 Sortie ");
        printf("\n\t\tAppuyer 1 Continuer la propagation ");
        printf("\n\t\tAppuyer 2 Revenir d'un temps en arrière");
        printf("\n\t\tAppuyer 3 Modifier une cellule");
        printf("\n\t\tAppuyer 4 Afficher l'état d'une case ");
        printf("\n\t\tAppuyer 5 Afficher le degrés d'une case ");
        printf("\n\t\tEntrer votre choix[0-5]:\t");
        scanf("%d", &options);

        if (options == 1) {
            diminuerDeg(&f[t]);
            t++;
            propagationForet(&f[t - 1], &f[t]);
            afficherForet(f[t]);
        }
        else if (options == 2)
        {
            t--;
            afficherForet(f[t]);
            printf("Vous êtes au tour %d\n\t\t", t);
        }
        else if (options == 3)
        {
            int x, y, newdeg, newetat, choixt, choixd, choixe;
            char newtype;

            printf("\n\t\tEntrez la position x de la case à modifier : ");
            scanf("%d", &x);
            printf("\n\t\tEntrez la position y de la case à modifier : ");
            scanf("%d", &y);
            printf("\n\t\tVoulez-vous modifier son type (1 pour OUI; 0 pour NON) ? \n\t\t");
            scanf("%d", &choixt);
            if (choixt) {
                printf("\n\t\tEntrez son nouveau type : ");
                scanf(" %c", &newtype);
                f[t].foret[x][y] = newtype;
                switch (f[t].foret[x][y]) {
                case SOL:
                    f[t].degres[i][j] = dSOL;
                    break;
                case ARBRE:
                    f[t].degres[i][j] = dARBRE;
                    break;
                case FEUILLE:
                    f[t].degres[i][j] = dFEUILLE;
                    break;
                case ROCHE:
                    f[t].degres[i][j] = dROCHE;
                    break;
                case HERBE:
                    f[t].degres[i][j] = dHERBE;
                    break;
                case EAU:
                    f[t].degres[i][j] = dEAU;
                    break;
                case CENDRES:
                    f[t].degres[i][j] = dCENDRES;
                    break;
                case CENDRES_ETEINTES:
                    f[t].degres[i][j] = dCENDRES_ETEINTES;
                    break;
                }
            }

            printf("Voulez-vous modifier son degré (1 pour OUI; 0 pour NON) ? \n\t\t");
            scanf("%d", &choixd);

            if (choixd) {
                int nvdeg;
                printf("Entrez son nouveau degré : \n\t\t");
                scanf("%d", &nvdeg);
                f[t].degres[x][y] = nvdeg;
            }

            printf("Voulez-vous modifier son état (1 pour OUI; 0 pour NON) ? \n\t\t");
            scanf("%d", &choixe);

            if (choixe) {
                int etat;
                printf("Entrez son nouvel état : \n\n\t\t");
                scanf("%d", &etat);
                f[t].etats[x][y] = etat;
            }
            afficherForet(f[t]);
        }

        else if (options == 4)
        {
            int posX, posY;
            printf("Entrez la position x de la case à afficher :\n\t\t");
            scanf("%d", &posX);
            printf("Entrez la position y de la case à afficher :\n\t\t ");
            scanf("%d", &posY);
            afficherEtat(posX, posY, &f[t]);
        }
        else if (options == 5)
        {
            int posX, posY;
            printf("Entrez la position x de la case à afficher : \n\t\t");
            scanf("%d", &posX);
            printf("Entrez la position y de la case à afficher : \n\t\t");
            scanf("%d", &posY);
            afficherDegre(posX, posY, &f[t]);
        }
    }

    printf("FIN DE LA PROPAGATION \n\n\t\t");
    for (int i = 0;i < t;i++)
        destructionForet(&f[i]);

    free(f);
    return EXIT_SUCCESS;
}
