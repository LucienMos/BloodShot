#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// ------------------------------------------- [ Fonctions ] ------------------------------------------- //

// --- [ Effacer ] --- //

void clear(void) { // Fonction pour effacer l'ecran

    system("cls"); // Cette fonction utilise une commande systeme specifique pour effacer l'ecran

}

// --- [ Curseur ] --- //

void cursor (int x, int y) { // Fonction pour deplacer le curseur à une position specifique sur l'ecran

    printf("\033[%d;%dH", x, y); // Cette fonction utilise un code d'echappement ASCII pour deplacer le curseur

}

// --- [ Balls ] --- //

int balls(int emptyBalls, int fullBalls){ // Fonction pour determiner quelle balle est tiree (pleine ou vide)

    int number;
    int i= 0;

    while(i == 0){

        number = rand() % 2 + 1;

        if (number == 1){

            if(fullBalls > 0){

                i++;

                return number;

            }

        }

        else if (number == 2){

            if(emptyBalls > 0){

                i++;

                return number;

            }

        }

    }

}

void attente(char *name, int playerLife, int dealerLife, int emptyBalls, int fullBalls){ // Fonction pour gerer l'attente entre les actions des joueurs

    int i = 0;

    clear();

    while(i <= 2){

        bloodshot(name, playerLife, dealerLife, 99, 99);

        if (i == 0){

            cursor(25, 28);
            printf(".");

            cursor(11, 28);
            printf(".");

            sleep(1);
            clear();

        }

        else if (i == 1){

            cursor(25, 28);
            printf("..");

            cursor(11, 28);
            printf("..");

            sleep(1);
            clear();

        }

        else if (i == 2){

            cursor(25, 28);
            printf("...");

            cursor(11, 28);
            printf("...");

            sleep(1);
            clear();

        }

        i++;

    }

}



int dealer(int emptyBalls, int fullBalls){ // Fonction pour que le dealer prenne sa decision sur quelle balle tirer

    int shot;

    if(emptyBalls < fullBalls){ // Dealer choisit de tirer une balle pleine

        shot = 2;

        return shot;

    }

    else if(emptyBalls > fullBalls){ // Dealer choisit de tirer une balle vide


        shot = 1;

        return shot;

    }

    else if(emptyBalls == fullBalls){ // Dealer choisit al�atoirement entre une balle vide ou pleine

        shot = rand() % 2 + 1;

        return shot;

    }

}

void displayBonus(int nbChain, int nbUnloading, int nbAddingLife, int nbLookBall, int nbSawing, int nbShield, int dealerNbChain, int dealerNbUnloading, int dealerNbAddingLife, int dealerNbLookBall, int dealerNbSawing, int dealerNbShield) {

    cursor(9, 64);
    printf("Menottes : %i", dealerNbChain);

    cursor(10, 64);
    printf("Balles : %i", dealerNbUnloading);

    cursor(11, 64);
    printf("Cigarettes : %i", dealerNbAddingLife);

    cursor(12, 64);
    printf("Loupes : %i", dealerNbLookBall);

    cursor(13, 64);
    printf("Scies : %i", dealerNbSawing);

    cursor(14, 64);
    printf("Boucliers : %i", dealerNbShield);


    cursor(22, 64);
    printf("Menottes : %i", nbChain);

    cursor(23, 64);
    printf("Balles : %i", nbUnloading);

    cursor(24, 64);
    printf("Cigarettes : %i", nbAddingLife);

    cursor(25, 64);
    printf("Loupes : %i", nbLookBall);

    cursor(26, 64);
    printf("Scies : %i", nbSawing);

    cursor(27, 64);
    printf("Boucliers : %i", nbShield);

}

// --- [ Menu ] --- //

int menu(void) { // Fonction pour afficher le menu et permettre � l'utilisateur de naviguer

    int navigation;

    printf("#############################################################\n");
    printf("#                                                           #\n");
    printf("#  ###   #     ###    ###   ###    ###  #  #   ###   #####  #\n");
    printf("#  #  #  #    #   #  #   #  #  #   #    #  #  #   #    #    #\n");
    printf("#  ###   #    #   #  #   #  #   #  ###  ####  #   #    #    #\n");
    printf("#  #  #  #    #   #  #   #  #  #     #  #  #  #   #    #    #\n");
    printf("#  ###   ###   ###    ###   ###    ###  #  #   ###     #    #\n");
    printf("#                                                           #\n");
    printf("#############################################################\n");
    printf("#                                                           #\n");
    printf("#                                                           #\n");
    printf("#                         [1] Jeu                           #\n");
    printf("#                                                           #\n");
    printf("#                       [2] Histoire                        #\n");
    printf("#                                                           #\n");
    printf("#                      [3] Sauvgardes                       #\n");
    printf("#                                                           #\n");
    printf("#                       [4] Quitter                         #\n");
    printf("#                                                           #\n");
    printf("#                                                           #\n");
    printf("#############################################################\n");

    printf("Navigation : ");

    scanf("%i", &navigation); // Demande à l'utilisateur de choisir une option

    clear();

    return navigation;
}

// --- [ Contrat ] --- //

void contrat(char *signature) {

    printf("#############################################################\n");
    printf("#                                                           #\n");
    printf("#       ###   ###   ##    #  #####  ###    ###   #####      #\n");
    printf("#      #     #   #  # #   #    #    #  #  #   #    #        #\n");
    printf("#      #     #   #  #  #  #    #    ###   #####    #        #\n");
    printf("#      #     #   #  #   # #    #    #  #  #   #    #        #\n");
    printf("#       ###   ###   #    ##    #    #  #  #   #    #        #\n");
    printf("#                                                           #\n");
    printf("#############################################################\n");
    printf("#                                                           #\n");
    printf("#                                                           #\n");
    printf("#                                                           #\n");
    printf("#                        Je soussigne,                      #\n");
    printf("#   accepte volontairement de participer au jeu Bloodshot.  #\n");
    printf("#             Je comprends les risques encourus             #\n");
    printf("#   et decharge les organisateurs de toute responsabilite   #\n");
    printf("#        en cas de prejudice ou de blessure resultant       #\n");
    printf("#                     de ma participation.                  #\n");
    printf("#                                                           #\n");
    printf("#                                                           #\n");
    printf("#                                                           #\n");
    printf("#############################################################\n");

    cursor(20,5);
    printf("Signature : ");

    scanf("%49s", signature);

	clear();

}

// --- [ Niveau 1 ] --- //

void display1(void){ // Fonction d'affichage du niveau 1

     printf("##   ##   ####    ##   ##  #######    ##     ##   ##             ##  \n");
     printf("###  ##    ##     ##   ##   ##   #   ####    ##   ##            ###  \n");
     printf("#### ##    ##      ## ##    ## #    ##  ##   ##   ##             ##  \n");
     printf("## ####    ##      ## ##    ####    ##  ##   ##   ##             ##  \n");
     printf("##  ###    ##       ###     ## #    ######   ##   ##             ##  \n");
     printf("##   ##    ##       ###     ##   #  ##  ##   ##   ##             ##  \n");
     printf("##   ##   ####       #     #######  ##  ##    #####            ######\n");

}

// --- [ Niceau 2 ] --- //

void display2(void){ // Fonction d'affichage du niveau 1

     printf("##   ##   ####    ##   ##  #######    ##     ##   ##            #### \n");
     printf("###  ##    ##     ##   ##   ##   #   ####    ##   ##           ##  ##\n");
     printf("#### ##    ##      ## ##    ## #    ##  ##   ##   ##               ##\n");
     printf("## ####    ##      ## ##    ####    ##  ##   ##   ##             ### \n");
     printf("##  ###    ##       ###     ## #    ######   ##   ##            ##   \n");
     printf("##   ##    ##       ###     ##   #  ##  ##   ##   ##           ##  ##\n");
     printf("##   ##   ####       #     #######  ##  ##    #####            ######\n");

}

// --- [ Niveau 3 ] --- //

void display3(void){ // Fonction d'affichage du niveau 1

    printf("##   ##   ####    ##   ##  #######    ##     ##   ##            #### \n");
    printf("###  ##    ##     ##   ##   ##   #   ####    ##   ##           ##  ##\n");
    printf("#### ##    ##      ## ##    ## #    ##  ##   ##   ##               ##\n");
    printf("## ####    ##      ## ##    ####    ##  ##   ##   ##             ### \n");
    printf("##  ###    ##       ###     ## #    ######   ##   ##               ##\n");
    printf("##   ##    ##       ###     ##   #  ##  ##   ##   ##           ##  ##\n");
    printf("##   ##   ####       #     #######  ##  ##    #####             #### \n");

}

// --- [ Redimention ] --- //

void config(void){ //permet de garentire le bon fonctionnement de la donction curse

    printf("##############                                                                         ##############\n");
    printf("#                                                                                                   #\n");
    printf("#                                                                                                   #\n");
    printf("#                                                                                                   #\n");
    printf("#                                                                                                   #\n");
    printf("#                                                                                                   #\n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                     Attention redimensionner votre terminal ! (ctr + molette)                       \n");
	printf("                                  Et ensuite appuyer sur entrer                                      \n");
	printf("                                                                                                     \n");
    printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
	printf("                                                                                                     \n");
    printf("#                                                                                                   #\n");
    printf("#                                                                                                   #\n");
    printf("#                                                                                                   #\n");
    printf("#                                                                                                   #\n");
    printf("#                                                                                                   #\n");
    printf("##############                                                                         ##############\n");

    char c = getchar();

     while (c != '\n' && c != EOF){

        c = getchar();

     }

    clear();

}

// --- [ Ecran ] --- //

void bloodshot(char *name, int playerLife, int dealerLife, int emptyBalls, int fullBalls) {

    clear();

	printf("################################################################################################\n");
	printf("#                                                           #                                  #\n");
	printf("#  Dealeur                                                  #                                  #\n");
	printf("#                                                           #                                  #\n");
    printf("################################################################################################\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #  Inventaire :                    #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#              ###############################              #                                  #\n");
	printf("#              #                             #              #                                  #\n");
	printf("################                             ###################################################\n");
	printf("#              #                             #              #                                  #\n");
	printf("#              ###############################              #  Inventaire :                    #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
    printf("################################################################################################\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
	printf("#                                                           #                                  #\n");
    printf("################################################################################################\n");
	printf("#                                                                                              #\n");
	printf("#                                                                                              #\n");
	printf("#                                                                                              #\n");
	printf("#                                                                                              #\n");
	printf("#                                                                                              #\n");
    printf("#                                                                                              #\n");
    printf("#                                                                                              #\n");
	printf("#                                                                                              #\n");
	printf("#                                                                                              #\n");
	printf("#                                                                                              #\n");
    printf("################################################################################################\n");

    if(emptyBalls != 99 || fullBalls != 99){

        cursor(18,22);
        printf("%i Vides / %i Pleines", emptyBalls, fullBalls);

    }

    cursor(3,65);
	printf("%i Coeurs", dealerLife);

	cursor(33,65);
	printf("%i Coeurs", playerLife);

	cursor(33,4);
	printf("%s", name);

	cursor(37,4);

}

// --- [ Niveau 1 ] --- //

int level1(char name[50]) {

    // --- [ Variables ] --- //
    int i = 0;
    int leave;
    int shot = 0;
    int round = 1;
    int choiceBall = 0;
    int nbBalls = 4;
    int emptyBalls = 0;
    int fullBalls = 0;
    int playerLife;
    int dealerLife;

    // --- [ Programme ] --- //

    while (dealerLife > 0) {

        playerLife = 6;
        dealerLife = 6;

        emptyBalls = 0;
        fullBalls = 0;

        clear();
        display1();
        sleep(1);

        while (dealerLife > 0 && playerLife > 0) { // Quitte la partie si le joureur ou le dealer sont mort.

            round = 1;

            if (dealerLife > 0 && playerLife > 0){  // Verifie si le dealer et le joueur sont encore en vie

                while (round == 1) { // Tour du joueur.

                    if (emptyBalls == 0 && fullBalls == 0) { // Verifie si il y a encore des balles et recharge si ce n'est pas le cas.

                        fullBalls = rand() % (nbBalls - 1) + 1;
                        emptyBalls = nbBalls - fullBalls;

                        bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                        cursor(11, 25);
                        printf("Rechargement...");

                        cursor(25, 25);
                        printf("Rechargement...");

                        sleep(2);

                    }

                    scanf("%*[^\n]%*c");

                    shot = 0;

                    bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                    cursor(37, 4);
                    printf("Sur qui voulez-vous tirer ?");

                    cursor(38, 4);
                    printf("[1] %s", name);

                    cursor(39, 4);
                    printf("[2] Dealer");

                    cursor(40, 4);
                    scanf("%i", &shot); // Recupere  le choix du joueur pour savoir sur qui il tire.

                    while(shot != 1 && shot != 2){ // Verifie si le joueur entre bien un caractere valide.

                        scanf("%*[^\n]%*c");

                        shot = 0;

                        cursor(11, 25);
                        printf("Choix invalide");

                        cursor(25, 25);
                        printf("Choix invalide");

                        sleep(1);

                        bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                        cursor(37, 4);
                        printf("Sur qui voulez-vous tirer ?");

                        cursor(38, 4);
                        printf("[1] %s", name);

                        cursor(39, 4);
                        printf("[2] Dealer");

                        cursor(40, 4);
                        scanf("%i", &shot);

                    }

                    if (shot == 1) { // Si le joueur decide de ce tire dessus.

                        choiceBall = balls(emptyBalls, fullBalls); // Choisi aleatoirement quel type de balle il y a dans le pistolet.

                        if (choiceBall == 1) { // Si la balle dans le pistolet est un balle pleine.

                            round = 2;

                            attente(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            fullBalls--;

                            bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            cursor(25, 28);
                            printf("Boom !");

                            cursor(33, 75);
                            printf("-1");

                            sleep(2);

                            playerLife--;

                        }

                        else if (choiceBall == 2) { // Si la balle dans le pistolet est un balle vide.

                            round = 1;

                            attente(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            emptyBalls--;

                            bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            cursor(25, 8);
                            printf("Tu peux rejouer, tu as tire une balle vide !");

                            sleep(2);
                        }

                    }

                    else if (shot == 2) { // Si le joueur decide de ce tire sur le dealer.

                        choiceBall = balls(emptyBalls, fullBalls);

                        if (choiceBall == 1) { // Si la balle dans le pistolet est un balle pleine.

                            round = 2;

                            attente(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            fullBalls--;

                            bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            cursor(11, 28);
                            printf("Boom !");

                            cursor(3, 75);
                            printf("-1");

                            sleep(2);

                            dealerLife--;

                        }

                        else if (choiceBall == 2) { // Si la balle dans le pistolet est un balle vide.

                            round = 2;

                            attente(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            emptyBalls--;

                            bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            cursor(25, 8);

                            printf("Tu as tire une balle vide sur le dealer!");

                            sleep(2);

                        }

                    }

                }

            }

            if (dealerLife > 0 && playerLife > 0){  // Verifie si le dealer et le joueur sont encore en vie

                while (round == 2) { // Tour du dealer.

                    if (emptyBalls == 0 && fullBalls == 0) { // Verifie si il y a encore des balles et recharge si ce n'est pas le cas.

                        fullBalls = rand() % (nbBalls - 1) + 1;
                        emptyBalls = nbBalls - fullBalls;

                        bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                        cursor(11, 25);
                        printf("Rechargement...");

                        cursor(25, 25);
                        printf("Rechargement...");

                        sleep(2);

                    }

                    bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                    cursor(11, 13);
                    printf("Le dealer est entrain de jouer");

                    i = 0;

                    while (i <= 2) { // Animation d'attente pendant que le dealer joue.

                        printf(".");

                        sleep(1);

                        i++;

                    }

                    clear();

                    shot = dealer(emptyBalls, fullBalls); // Recupere le choix du dealer pour savoir sur qui il veut tire

                    if (shot == 1) { // Si le dealer decide de ce tire dessus.

                        bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                        cursor(11, 12);
                        printf("Le dealer a choisie de se tire dessus !");

                        sleep(2);

                        choiceBall = balls(emptyBalls, fullBalls); // Choisi aleatoirement quel type de balle il y a dans le pistolet.

                        if (choiceBall == 1) { // Si la balle dans le pistolet est un balle pleine.

                            fullBalls--;

                            round = 1;

                            bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            cursor(11, 28);
                            printf("Boom !");

                            cursor(3, 75);
                            printf("-1");

                            sleep(2);

                            dealerLife--;

                        }

                        else if (choiceBall == 2) { // Si la balle dans le pistolet est un balle vide.

                            emptyBalls--;

                            round = 2;

                        }

                    }

                    else if (shot == 2) { // Si le dealer decide de ce tire sur le joueur.

                        bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                        cursor(11, 12);
                        printf("Le dealer a choisie de vous tire dessus !");

                        sleep(2);

                        choiceBall = balls(emptyBalls, fullBalls); // Choisi aleatoirement quel type de balle il y a dans le pistolet.

                        if (choiceBall == 1) { // Si la balle dans le pistolet est un balle pleine.

                            fullBalls--;

                            round = 1;

                            bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            cursor(25, 28);
                            printf("Boom !");

                            cursor(33, 75);
                            printf("-1");

                            sleep(2);

                            playerLife--;

                        }

                        else if (choiceBall == 2) { // Si la balle dans le pistolet est un balle vide.

                            emptyBalls--;

                            round = 1;

                            bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);

                            cursor(11, 6);
                            printf("Le dealer a tire une balle a blanc, il peut rejouer !");

                            sleep(2);

                        }

                    }

                }

            }

        }

        if(playerLife <= 0){ // Verifie si le joueur est mort.

            clear();

            printf("######################################\n");
            printf("#                                    #\n");
            printf("#  #     #  ######  #####   #######  #\n");
            printf("#  ##   ##  #    #  #    #     #     #\n");
            printf("#  # # # #  #    #  #    #     #     #\n");
            printf("#  #  #  #  #    #  #####      #     #\n");
            printf("#  #     #  #    #  #    #     #     #\n");
            printf("#  #     #  #    #  #    #     #     #\n");
            printf("#  #     #  ######  #    #     #     #\n");
            printf("#                                    #\n");
            printf("######################################\n");

            sleep(3);

            clear();

            while(leave != 99){  // Demande au joueur si il veut rejouer ou quitter le jeu.

                printf("###########################\n");
                printf("#                         #\n");
                printf("#      [1] Rejouer        #\n");
                printf("#                         #\n");
                printf("#      [2] Quitter        #\n");
                printf("#                         #\n");
                printf("###########################\n");

                scanf("%i",&leave);

                clear();

                if (leave == 1){

                leave = 99;

                }

                else if(leave == 2){ // Donne le code de sauvgarde si le joueur quitte

                    printf("####################################\n");
                    printf("#                                  #\n");
                    printf("#  Deconnexion du jeu en cours...  #\n");
                    printf("#                                  #\n");
                    printf("####################################\n");

                    sleep(5);

                    clear();

                    return leave;

                }

                else{}

            }

        }

    }

    if(dealerLife == 0){ // Verifie si le joueur a gagner.

        clear();

        printf("##############################################\n");
        printf("#                                            #\n");
        printf("#  #####   #####      #     #     #  ######  #\n");
        printf("#  #    #  #    #    # #    #     #  #    #  #\n");
        printf("#  #    #  #    #    # #     #   #   #    #  #\n");
        printf("#  #####   #####    #   #    #   #   #    #  #\n");
        printf("#  #    #  #    #   #####     # #    #    #  #\n");
        printf("#  #    #  #    #  #     #    # #    #    #  #\n");
        printf("#  #####   #    #  #     #     #     ######  #\n");
        printf("#                                            #\n");
        printf("##############################################\n");

        sleep(3);

        clear();

        printf("######################################\n");
        printf("#                                    #\n");
        printf("#  Code de sauvegarde de partie : 2  #\n");
        printf("#                                    #\n");
        printf("######################################\n");

        sleep(5);

        clear();

        return 0;

    }



}

// --- [ Niveau 2 ] --- //

int level2(char name[50]) {

    // --- [ Variables ] --- //

    int i = 0;
    int leave;
    int shot = 0;
    int round = 1;
    int tirage = 0;

    // --- [ Variables balles ] --- //

    int choiceBall = 0;
    int nbBalls = 6;
    int emptyBalls = 0;
    int fullBalls = 0;

    // --- [ Variables vie ] --- //

    int playerLife;
    int dealerLife;

    // --- [ Nombre de bonus ] --- //

    int useBonus = 0;
    int choiceBonus = 0;
    int nbBonus = 4;

    int nbChain = 0;
    int nbUnloading = 0;
    int nbAddingLife = 0;
    int nbLookBall = 0;
    int nbSawing = 0;
    int nbShield = 0;

    int chain = 0;
    int sawing = 0;
    int shield = 0;

    // --- [ Nombre de bonus ] --- //


    int dealerUseBonus = 0;
    int dealerChoiceBonus = 0;
    int dealerNbBonus = 0;

    int dealerNbChain = 0;
    int dealerNbUnloading = 0;
    int dealerNbAddingLife = 0;
    int dealerNbLookBall = 0;
    int dealerNbSawing = 0;
    int dealerNbShield = 0;

    int dealerChain = 0;
    int dealerSawing = 0;
    int dealerShield = 0;



    // --- [ Programme ] --- //

    printf("Et si on complexifie les choses ?");

    sleep(3);

    clear();

    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#                                   CHANGEMENTS NIVEAU                                         #\n");
    printf("#                                                                                              #\n");
    printf("#                               DEBUTANT -> INTERMEDIAIRE                                      #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                              #                                                               #\n");
    printf("#      CHARGEUR DE BALLES      #                        AJOUT DE BONUS                         #\n");
    printf("#                              #                                                               #\n");
    printf("#        4 ==> 6 Balles        #                                                               #\n");
    printf("#                              #                                                               #\n");
    printf("#------------------------------#   MENOTTE : EMPECHE LE DEALEUR DE JOUER PENDANT UN TOUR       #\n");
    printf("#                              #                                                               #\n");
    printf("#     JOUEUR       DEALEUR     #   DECHARGEMENT : RETIRE LA BALLE DANS LE PISTOLET             #\n");
    printf("#                              #                                                               #\n");
    printf("#    4 COEURS      6 COEURS    #   CIGARETTE : AJOUTE 1 POINT DE VIE AU JOUEUR                 #\n");
    printf("#                              #                                                               #\n");
    printf("#------------------------------#   LOUPE : REGARDE LA BALLE DANS LE PISTOLET                   #\n");
    printf("#                              #                                                               #\n");
    printf("#          CHANGEMENT          #   SCIE : DOUBLE LES DEGATS DE LA BALLE                        #\n");
    printf("#                              #                                                               #\n");
    printf("#    BALLE ===> INVISIBLE      #   BOUClIER : PROTECTION DE TOUTE BALLE PENDANT UN TOUR        #\n");
    printf("#                              #                                                               #\n");
    printf("################################################################################################\n");

    sleep(15);

    clear();

    while (dealerLife > 0) {

        playerLife = 4;
        dealerLife = 6;

        emptyBalls = 0;
        fullBalls = 0;

        clear();
        display2();
        sleep(1);

        while (dealerLife > 0 && playerLife > 0) { // Quitte la partie si le joureur ou le dealer sont mort.

            round = 1;
            nbBonus = 4;

            if (playerLife > 0){ // Verifie si le dealer et le joueur sont encore en vie

                while (round == 1) { // Tour du joueur.

                    if (emptyBalls == 0 && fullBalls == 0) { // Verifie si il y a encore des balles et recharge si ce n'est pas le cas.

                        fullBalls = rand() % (nbBalls - 1) + 1;
                        emptyBalls = nbBalls - fullBalls;

                        bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);
                        displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                        cursor(11, 25);
                        printf("Rechargement...");

                        cursor(25, 25);
                        printf("Rechargement...");

                        sleep(2);

                        i = 0;

                        while(i < 4){

                            tirage = rand() % 5;

                            if(tirage == 0){

                                nbChain = nbChain + 1;

                            }

                             else if(tirage == 1){

                                nbUnloading = nbUnloading + 1;

                             }

                             else if(tirage == 2){

                                nbAddingLife = nbAddingLife + 1;

                             }

                             else if(tirage == 3){

                                nbLookBall = nbLookBall + 1;

                             }

                             else if(tirage == 4){

                                nbSawing = nbSawing + 1;

                             }

                             else if(tirage == 5){

                                nbShield = nbShield + 1;

                             }

                            i++;

                        }

                        sleep(1);

                        i = 0;

                        while(i < 4){

                            tirage = rand() % 5;

                            if(tirage == 0){

                                dealerNbChain = dealerNbChain + 1;

                            }

                             else if(tirage == 1){

                                dealerNbUnloading = dealerNbUnloading + 1;

                             }

                             else if(tirage == 2){

                                dealerNbAddingLife = dealerNbAddingLife + 1;

                             }

                             else if(tirage == 3){

                                dealerNbLookBall = dealerNbLookBall + 1;

                             }

                             else if(tirage == 4){

                                dealerNbSawing = dealerNbSawing + 1;

                             }

                             else if(tirage == 5){

                                dealerNbShield = dealerNbShield + 1;

                             }

                            i++;

                        }

                        bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);
                        displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                        cursor(11, 20);
                        printf("Tirage de bonus en cours...");

                        cursor(25, 20);
                        printf("Tirage de bonus en cours...");

                        sleep(2);

                    }

                    choiceBall = balls(emptyBalls, fullBalls); // Choisi aleatoirement quel type de balle il y a dans le pistolet.

                    if(nbBonus > 0){ // Permet au joueur d'utiliser ses bonus

                        scanf("%*[^\n]%*c");

                        useBonus = 0;

                        bloodshot(name, playerLife, dealerLife, 99, 99);
                        displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                        cursor(37, 4);
                        printf("Voulez-vous utiliser un bonus");

                        cursor(38, 4);
                        printf("[1] Oui");

                        cursor(39, 4);
                        printf("[2] Non");

                        cursor(40, 4);
                        scanf("%i", &useBonus); // Recupere le choix d'utilisation des bonus

                        while(useBonus != 1 && useBonus != 2){ // Verifie si le joueur entre bien un caractere valide.

                            scanf("%*[^\n]%*c");

                            cursor(11, 25);
                            printf("Choix invalide");

                            cursor(25, 25);
                            printf("Choix invalide");

                            sleep(1);

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            cursor(37, 4);
                            printf("Voulez-vous utilise un bonus");

                            cursor(38, 4);
                            printf("[1] Oui");

                            cursor(39, 4);
                            printf("[2] Non");

                            cursor(40, 4);
                            scanf("%i", &useBonus);

                            }

                            if(useBonus == 1){ // Permet de choisir quel bonus le joueur veut utiliser.

                                leave = 0;

                                while(nbBonus > 0 && leave != 1){ // Verifie si le joueur peut les utiliser

                                    choiceBonus = 0;

                                    bloodshot(name, playerLife, dealerLife, 99, 99);
                                    displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                                    cursor(37, 4);
                                    printf("Quel bonus voulez-vous utiliser un bonus");

                                    cursor(38, 4);
                                    printf("[1] Menotte");

                                    cursor(39, 4);
                                    printf("[2] Balles");

                                    cursor(40, 4);
                                    printf("[3] Cigarette");

                                    cursor(41, 4);
                                    printf("[4] Loupe");

                                    cursor(42, 4);
                                    printf("[5] Scie");

                                    cursor(43, 4);
                                    printf("[6] Bouclier");

                                    cursor(44, 4);
                                    printf("[7] Retour");

                                    cursor(45, 4);
                                    scanf("%i", &choiceBonus);

                                    if(choiceBonus == 1){ // Si le joueur a choisi d'utiliser les menottes

                                        if(nbChain > 0){

                                            nbBonus = nbBonus - 1;
                                            nbChain = nbChain - 1;

                                            chain = 1;

                                            cursor(25, 13);
                                            printf("Tu viens de menotter le dealer !");

                                            sleep(3);

                                        }

                                        else{

                                            cursor(25, 17);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 2){ // Si le joueur a choisi d'utiliser le dechargement.

                                        if(nbUnloading > 0){

                                            nbBonus = nbBonus - 1;

                                            nbUnloading = nbUnloading - 1;

                                            if(choiceBall == 1){

                                                fullBalls = fullBalls - 1;

                                                cursor(25, 20);
                                                printf("Tu retire un balle pleine!");

                                                sleep(3);

                                            }

                                            else{

                                                emptyBalls = emptyBalls - 1;

                                                cursor(25, 13);
                                                printf("Tu viens de retirer un balle vide !");

                                                sleep(3);

                                            }


                                        }

                                        else{

                                            cursor(25, 17);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 3){ // Si le joueur a choisi d'utiliser les cigarette.


                                        if(nbAddingLife > 0){

                                            nbBonus = nbBonus - 1;

                                            nbAddingLife = nbAddingLife - 1;


                                            cursor(25, 17);
                                            printf("Tu viens de gangner un vie !");

                                            cursor(33, 75);
                                            printf("+1");

                                            sleep(3);

                                            playerLife = playerLife + 1;


                                        }

                                        else{

                                            cursor(25, 17);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 4){ // Si le joueur a choisi d'utiliser la loupe.

                                        if(nbLookBall > 0){

                                            nbBonus = nbBonus - 1;
                                            nbLookBall = nbLookBall - 1;

                                            if(choiceBall == 1){

                                                fullBalls = fullBalls - 1;

                                                cursor(25, 17);
                                                printf("(Prochaine balle : plein)");

                                                sleep(3);

                                            }

                                            else{

                                                emptyBalls = emptyBalls - 1;

                                                cursor(25, 17);
                                                printf("(Prochaine balle : vide)");

                                                sleep(3);

                                            }


                                        }

                                        else{

                                            cursor(25, 20);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 5){ // Si le joueur a choisi d'utiliser la scie.

                                        if(nbSawing > 0){

                                            nbBonus = nbBonus - 1;

                                            nbSawing = nbSawing - 1;

                                            sawing = 1;

                                            cursor(25, 18);
                                            printf("Le canon a ete scier !");

                                            sleep(3);

                                        }

                                        else{

                                            cursor(25, 20);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 6){ // Si le joueur a choisi d'utiliser le bouclier.

                                        if(nbShield > 0){

                                            nbBonus = nbBonus - 1;

                                            nbShield = nbShield - 1;


                                            cursor(25, 17);
                                            printf("Tu viens d'activer un bouclier !");

                                            sleep(3);

                                            shield = 1;

                                        }

                                        else{

                                            cursor(25, 20);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 7){ // Si le joueur ne veut plus utiliser de bonus.

                                        leave = 1;

                                    }

                                    else{

                                        scanf("%*[^\n]%*c");

                                        cursor(11, 25);
                                        printf("Choix invalide");

                                        cursor(25, 25);
                                        printf("Choix invalide");

                                        sleep(1);

                                        clear();


                                    }

                                }

                            }

                        }

                    scanf("%*[^\n]%*c");

                    shot = 0;

                    bloodshot(name, playerLife, dealerLife, 99, 99);
                    displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                    cursor(37, 4);
                    printf("Sur qui voulez-vous tirer ?");

                    cursor(38, 4);
                    printf("[1] %s", name);

                    cursor(39, 4);
                    printf("[2] Dealer");

                    cursor(40, 4);
                    scanf("%i", &shot);

                    while(shot != 1 && shot != 2){

                        scanf("%*[^\n]%*c");

                        shot = 0;

                        cursor(11, 25);
                        printf("Choix invalide");

                        cursor(25, 25);
                        printf("Choix invalide");

                        sleep(1);

                        bloodshot(name, playerLife, dealerLife, 99, 99);
                        displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);
                        cursor(37, 4);
                        printf("Sur qui voulez-vous tirer ?");

                        cursor(38, 4);
                        printf("[1] %s", name);

                        cursor(39, 4);
                        printf("[2] Dealer");

                        cursor(40, 4);
                        scanf("%i", &shot);

                    }

                    if (shot == 1) { // Joueur tire sur Joueur

                        if (choiceBall == 1) { // Ball pleine

                            round = 2;

                            attente(name, playerLife, dealerLife, 99, 99);

                            fullBalls--;

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            if(shield == 1){

                                cursor(25, 5);

                                printf("Vous avez recu un balle vide ! Bouclier casser ! ");

                                cursor(25, 28);
                                printf("Boom !");

                                sleep(1);

                            }

                            else if(shield == 0){

                                if(sawing == 1){

                                    sawing = 0;

                                    cursor(25, 28);
                                    printf("Boom !");

                                    cursor(33, 75);
                                    printf("-2");

                                    sleep(2);

                                    playerLife = playerLife - 2;

                                }

                                else if(sawing == 0){

                                    cursor(25, 28);
                                    printf("Boom !");

                                    cursor(33, 75);
                                    printf("-1");

                                    sleep(2);

                                    playerLife--;

                                }

                            }

                        }

                        else if (choiceBall == 2) { // Ball a blanc

                            round = 1;

                            attente(name, playerLife, dealerLife, 99, 99);

                            emptyBalls--;

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            cursor(25, 8);
                            printf("Tu peux rejouer, tu as tire une balle vide !");

                            sleep(2);

                        }

                    }

                    else if (shot == 2) { // Joueur tire sur dealer

                        choiceBall = balls(emptyBalls, fullBalls);

                        if (choiceBall == 1) { // Ball pleine

                            round = 2;

                            attente(name, playerLife, dealerLife, 99, 99);

                            fullBalls--;

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            if(shield == 1){

                                cursor(25, 5);
                                printf("Vous avez recu un balle plein ! Bouclier ! ");

                                cursor(25, 28);
                                printf("Boom !");

                                sleep(1);

                            }

                            else if(shield == 0){

                                if(sawing == 1){

                                    sawing = 0;

                                    cursor(11, 28);
                                    printf("Boom !");

                                    cursor(3, 75);
                                    printf("-2");

                                    sleep(2);

                                    dealerLife = dealerLife - 2;

                                }

                                else if(sawing == 0){

                                    cursor(11, 28);
                                    printf("Boom !");

                                    cursor(3, 75);
                                    printf("-1");

                                    sleep(2);

                                    dealerLife--;

                                }

                            }

                        }

                        else if (choiceBall == 2) { // Ball a blanc

                            round = 2;

                            attente(name, playerLife, dealerLife, 99, 99);

                            emptyBalls--;

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            cursor(25, 8);

                            printf("Tu as tire une balle vide sur le dealer!");

                            sleep(2);

                        }

                    }

                }

            }

            if (dealerLife > 0){

                if(chain == 1){

                    chain = 0;

                    cursor(11, 13);

                    printf("Le dealeur est menotte !");

                    sleep(1);

                }


                else if(chain == 0){

                    while (round == 2) { // Tour du dealer !

                        if (emptyBalls == 0 && fullBalls == 0) { // verifie si il y a encore des balles

                            fullBalls = rand() % (nbBalls - 1) + 1;
                            emptyBalls = nbBalls - fullBalls;

                            bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            cursor(11, 25);
                            printf("Rechargement...");

                            cursor(25, 25);
                            printf("Rechargement...");

                            sleep(2);

                        }

                        bloodshot(name, playerLife, dealerLife, 99, 99);
                        displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                        cursor(11, 13);
                        printf("Le dealer est entrain de jouer");

                        i = 0;

                        while (i <= 2) {

                            printf(".");

                            sleep(1);

                            i++;

                        }

                        clear();

                        shot = dealer(emptyBalls, fullBalls);

                        if (shot == 1) { // Dealer tire sur Dealer

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);
                            cursor(11, 12);
                            printf("Le dealer a choisie de se tire dessus !");

                            sleep(2);

                            choiceBall = balls(emptyBalls, fullBalls);

                            if (choiceBall == 1) { // Ball pleine

                                fullBalls--;

                                round = 1;

                                bloodshot(name, playerLife, dealerLife, 99, 99);
                                displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);
                                cursor(11, 28);
                                printf("Boom !");

                                cursor(3, 75);
                                printf("-1");

                                sleep(2);

                                dealerLife--;

                            }

                            else if (choiceBall == 2) { // Ball a blanc

                                emptyBalls--;

                                round = 2;

                            }

                        }

                        else if (shot == 2) { // Dealer tire sur joueur

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            cursor(11, 12);
                            printf("Le dealer a choisie de vous tire dessus !");

                            sleep(2);

                            choiceBall = balls(emptyBalls, fullBalls);

                            if (choiceBall == 1) { // Ball pleine

                                fullBalls--;

                                round = 1;

                                bloodshot(name, playerLife, dealerLife, 99, 99);
                                displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                                cursor(25, 28);
                                printf("Boom !");

                                cursor(33, 75);
                                printf("-1");

                                sleep(2);

                                playerLife--;

                            }

                            else if (choiceBall == 2) { // Ball a blanc

                                emptyBalls--;

                                round = 1;

                                bloodshot(name, playerLife, dealerLife, 99, 99);
                                displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                                cursor(11, 8);
                                printf("Le dealer a tire une balle a blanc, il peut rejouer !");

                                sleep(2);

                            }

                        }

                    }


                }

            }

        }

        if(playerLife <= 0){ // Verifie si le joueur a perdu

            clear();

            printf("######################################\n");
            printf("#                                    #\n");
            printf("#  #     #  ######  #####   #######  #\n");
            printf("#  ##   ##  #    #  #    #     #     #\n");
            printf("#  # # # #  #    #  #    #     #     #\n");
            printf("#  #  #  #  #    #  #####      #     #\n");
            printf("#  #     #  #    #  #    #     #     #\n");
            printf("#  #     #  #    #  #    #     #     #\n");
            printf("#  #     #  ######  #    #     #     #\n");
            printf("#                                    #\n");
            printf("######################################\n");

            sleep(3);

            clear();

            while(leave != 99){

                printf("###########################\n");
                printf("#                         #\n");
                printf("#      [1] Rejouer        #\n");
                printf("#                         #\n");
                printf("#      [2] Quitter        #\n");
                printf("#                         #\n");
                printf("###########################\n");

                scanf("%i",&leave);

                clear();

                if(leave == 1){

                    leave = 99;

                }

                else if(leave == 2){

                    printf("####################################\n");
                    printf("#                                  #\n");
                    printf("#  Deconnexion du jeu en cours...  #\n");
                    printf("#                                  #\n");
                    printf("####################################\n");

                    sleep(5);

                    clear();

                    return leave;

                }

                else{}

            }

        }

    }

    if(dealerLife == 0){

        clear();

        printf("##############################################\n");
        printf("#                                            #\n");
        printf("#  #####   #####      #     #     #  ######  #\n");
        printf("#  #    #  #    #    # #    #     #  #    #  #\n");
        printf("#  #    #  #    #    # #     #   #   #    #  #\n");
        printf("#  #####   #####    #   #    #   #   #    #  #\n");
        printf("#  #    #  #    #   #####     # #    #    #  #\n");
        printf("#  #    #  #    #  #     #    # #    #    #  #\n");
        printf("#  #####   #    #  #     #     #     ######  #\n");
        printf("#                                            #\n");
        printf("##############################################\n");

        sleep(3);

        clear();

        printf("######################################\n");
        printf("#                                    #\n");
        printf("#  Code de sauvegarde de partie : 3  #\n");
        printf("#                                    #\n");
        printf("######################################\n");

        sleep(5);

        clear();

        return 0;

    }



}int level3(char name[50]) {

    // --- [ Variables ] --- //

    int i = 0;
    int leave;
    int shot = 0;
    int round = 1;
    int tirage = 0;

    // --- [ Variables balles ] --- //

    int choiceBall = 0;
    int nbBalls = 8;
    int emptyBalls = 0;
    int fullBalls = 0;

    // --- [ Variables vie ] --- //

    int playerLife;
    int dealerLife;

    // --- [ Nombre de bonus ] --- //

    int useBonus = 0;
    int choiceBonus = 0;
    int nbBonus = 1;

    int nbChain = 0;
    int nbUnloading = 0;
    int nbAddingLife = 0;
    int nbLookBall = 0;
    int nbSawing = 0;
    int nbShield = 0;

    int chain = 0;
    int sawing = 0;
    int shield = 0;

    // --- [ Nombre de bonus ] --- //


    int dealerUseBonus = 0;
    int dealerChoiceBonus = 0;
    int dealerNbBonus = 0;

    int dealerNbChain = 0;
    int dealerNbUnloading = 0;
    int dealerNbAddingLife = 0;
    int dealerNbLookBall = 0;
    int dealerNbSawing = 0;
    int dealerNbShield = 0;

    int dealerChain = 0;
    int dealerSawing = 0;
    int dealerShield = 0;



    // --- [ Programme ] --- //

    while (dealerLife > 0) {

        printf("Et si on complexifie les choses ?");

        sleep(3);

        clear();

        printf("################################################################################################\n");
        printf("#                                                                                              #\n");
        printf("#                                   CHANGEMENTS NIVEAU                                         #\n");
        printf("#                                                                                              #\n");
        printf("#                              INTERMEDIAIRE -> IMPOSSIBLE                                     #\n");
        printf("#                                                                                              #\n");
        printf("################################################################################################\n");
        printf("#                              #                                                               #\n");
        printf("#      CHARGEUR DE BALLES      #                        AJOUT DE BONUS                         #\n");
        printf("#                              #                                                               #\n");
        printf("#        6 ==> 8 Balles        #                                                               #\n");
        printf("#                              #                                                               #\n");
        printf("#------------------------------#   MENOTTE : EMPECHE LE DEALEUR DE JOUER PENDANT UN TOUR       #\n");
        printf("#                              #                                                               #\n");
        printf("#     JOUEUR       DEALEUR     #   DECHARGEMENT : RETIRE LA BALLE DANS LE PISTOLET             #\n");
        printf("#                              #                                                               #\n");
        printf("#    2 COEURS      6 COEURS    #   CIGARETTE : AJOUTE 1 POINT DE VIE AU JOUEUR                 #\n");
        printf("#                              #                                                               #\n");
        printf("#------------------------------#   LOUPE : REGARDE LA BALLE DANS LE PISTOLET                   #\n");
        printf("#                              #                                                               #\n");
        printf("#          CHANGEMENT          #   SCIE : DOUBLE LES DEGATS DE LA BALLE                        #\n");
        printf("#                              #                                                               #\n");
        printf("#    BALLE ===> INVISIBLE      #   BOUClIER : PROTECTION DE TOUTE BALLE PENDANT UN TOUR        #\n");
        printf("#                              #                                                               #\n");
        printf("################################################################################################\n");

        sleep(15);

        clear();

        playerLife = 2;
        dealerLife = 6;

        emptyBalls = 0;
        fullBalls = 0;

        clear();

        display3();

        sleep(1);

        while (dealerLife > 0 && playerLife > 0) { // Quitte la partie si le joureur ou le dealer sont mort.

            round = 1;
            nbBonus = 4;

            if (playerLife > 0){ // Verifie si le dealer et le joueur sont encore en vie

                while (round == 1) { // Tour du joueur.

                    if (emptyBalls == 0 && fullBalls == 0) { // Verifie si il y a encore des balles et recharge si ce n'est pas le cas.

                        fullBalls = rand() % (nbBalls - 1) + 1;
                        emptyBalls = nbBalls - fullBalls;

                        bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);
                        displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                        cursor(11, 25);
                        printf("Rechargement...");

                        cursor(25, 25);
                        printf("Rechargement...");

                        sleep(2);

                        i = 0;

                        while(i < 4){

                            tirage = rand() % 5;

                            if(tirage == 0){

                                nbChain = nbChain + 1;

                            }

                             else if(tirage == 1){

                                nbUnloading = nbUnloading + 1;

                             }

                             else if(tirage == 2){

                                nbAddingLife = nbAddingLife + 1;

                             }

                             else if(tirage == 3){

                                nbLookBall = nbLookBall + 1;

                             }

                             else if(tirage == 4){

                                nbSawing = nbSawing + 1;

                             }

                             else if(tirage == 5){

                                nbShield = nbShield + 1;

                             }

                            i++;

                        }

                        sleep(1);

                        i = 0;

                        while(i < 4){

                            tirage = rand() % 5;

                            if(tirage == 0){

                                dealerNbChain = dealerNbChain + 1;

                            }

                             else if(tirage == 1){

                                dealerNbUnloading = dealerNbUnloading + 1;

                             }

                             else if(tirage == 2){

                                dealerNbAddingLife = dealerNbAddingLife + 1;

                             }

                             else if(tirage == 3){

                                dealerNbLookBall = dealerNbLookBall + 1;

                             }

                             else if(tirage == 4){

                                dealerNbSawing = dealerNbSawing + 1;

                             }

                             else if(tirage == 5){

                                dealerNbShield = dealerNbShield + 1;

                             }

                            i++;

                        }

                        bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);
                        displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                        cursor(11, 20);
                        printf("Tirage de bonus en cours...");

                        cursor(25, 20);
                        printf("Tirage de bonus en cours...");

                        sleep(2);

                    }

                    choiceBall = balls(emptyBalls, fullBalls); // Choisi aleatoirement quel type de balle il y a dans le pistolet.

                    if(nbBonus > 0){ // Permet au joueur d'utiliser ses bonus

                        scanf("%*[^\n]%*c");

                        useBonus = 0;

                        bloodshot(name, playerLife, dealerLife, 99, 99);
                        displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                        cursor(37, 4);
                        printf("Voulez-vous utiliser un bonus");

                        cursor(38, 4);
                        printf("[1] Oui");

                        cursor(39, 4);
                        printf("[2] Non");

                        cursor(40, 4);
                        scanf("%i", &useBonus); // Recupere le choix d'utilisation des bonus

                        while(useBonus != 1 && useBonus != 2){ // Verifie si le joueur entre bien un caractere valide.

                            scanf("%*[^\n]%*c");

                            cursor(11, 25);
                            printf("Choix invalide");

                            cursor(25, 25);
                            printf("Choix invalide");

                            sleep(1);

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            cursor(37, 4);
                            printf("Voulez-vous utilise un bonus");

                            cursor(38, 4);
                            printf("[1] Oui");

                            cursor(39, 4);
                            printf("[2] Non");

                            cursor(40, 4);
                            scanf("%i", &useBonus);

                            }

                            if(useBonus == 1){ // Permet de choisir quel bonus le joueur veut utiliser.

                                leave = 0;

                                while(nbBonus > 0 && leave != 1){ // Verifie si le joueur peut les utiliser

                                    choiceBonus = 0;

                                    bloodshot(name, playerLife, dealerLife, 99, 99);
                                    displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                                    cursor(37, 4);
                                    printf("Quel bonus voulez-vous utiliser un bonus");

                                    cursor(38, 4);
                                    printf("[1] Menotte");

                                    cursor(39, 4);
                                    printf("[2] Balles");

                                    cursor(40, 4);
                                    printf("[3] Cigarette");

                                    cursor(41, 4);
                                    printf("[4] Loupe");

                                    cursor(42, 4);
                                    printf("[5] Scie");

                                    cursor(43, 4);
                                    printf("[6] Bouclier");

                                    cursor(44, 4);
                                    printf("[7] Retour");

                                    cursor(45, 4);
                                    scanf("%i", &choiceBonus);

                                    if(choiceBonus == 1){ // Si le joueur a choisi d'utiliser les menottes

                                        if(nbChain > 0){

                                            nbBonus = nbBonus - 1;
                                            nbChain = nbChain - 1;

                                            chain = 1;

                                            cursor(25, 13);
                                            printf("Tu viens de menotter le dealer !");

                                            sleep(3);

                                        }

                                        else{

                                            cursor(25, 17);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 2){ // Si le joueur a choisi d'utiliser le dechargement.

                                        if(nbUnloading > 0){

                                            nbBonus = nbBonus - 1;

                                            nbUnloading = nbUnloading - 1;

                                            if(choiceBall == 1){

                                                fullBalls = fullBalls - 1;

                                                cursor(25, 20);
                                                printf("Tu retire un balle pleine!");

                                                sleep(3);

                                            }

                                            else{

                                                emptyBalls = emptyBalls - 1;

                                                cursor(25, 13);
                                                printf("Tu viens de retirer un balle vide !");

                                                sleep(3);

                                            }


                                        }

                                        else{

                                            cursor(25, 17);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 3){ // Si le joueur a choisi d'utiliser les cigarette.


                                        if(nbAddingLife > 0){

                                            nbBonus = nbBonus - 1;

                                            nbAddingLife = nbAddingLife - 1;


                                            cursor(25, 17);
                                            printf("Tu viens de gangner un vie !");

                                            cursor(33, 75);
                                            printf("+1");

                                            sleep(3);

                                            playerLife = playerLife + 1;


                                        }

                                        else{

                                            cursor(25, 17);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 4){ // Si le joueur a choisi d'utiliser la loupe.

                                        if(nbLookBall > 0){

                                            nbBonus = nbBonus - 1;
                                            nbLookBall = nbLookBall - 1;

                                            if(choiceBall == 1){

                                                fullBalls = fullBalls - 1;

                                                cursor(25, 17);
                                                printf("(Prochaine balle : plein)");

                                                sleep(3);

                                            }

                                            else{

                                                emptyBalls = emptyBalls - 1;

                                                cursor(25, 17);
                                                printf("(Prochaine balle : vide)");

                                                sleep(3);

                                            }


                                        }

                                        else{

                                            cursor(25, 20);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 5){ // Si le joueur a choisi d'utiliser la scie.

                                        if(nbSawing > 0){

                                            nbBonus = nbBonus - 1;

                                            nbSawing = nbSawing - 1;

                                            sawing = 1;

                                            cursor(25, 18);
                                            printf("Le canon a ete scier !");

                                            sleep(3);

                                        }

                                        else{

                                            cursor(25, 20);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 6){ // Si le joueur a choisi d'utiliser le bouclier.

                                        if(nbShield > 0){

                                            nbBonus = nbBonus - 1;

                                            nbShield = nbShield - 1;


                                            cursor(25, 17);
                                            printf("Tu viens d'activer un bouclier !");

                                            sleep(3);

                                            shield = 1;

                                        }

                                        else{

                                            cursor(25, 20);
                                            printf("Tu ne possede pas ca !");

                                            sleep(3);

                                        }

                                    }

                                    else if(choiceBonus == 7){ // Si le joueur ne veut plus utiliser de bonus.

                                        leave = 1;

                                    }

                                    else{

                                        scanf("%*[^\n]%*c");

                                        cursor(11, 25);
                                        printf("Choix invalide");

                                        cursor(25, 25);
                                        printf("Choix invalide");

                                        sleep(1);

                                        clear();


                                    }

                                }

                            }

                        }

                    scanf("%*[^\n]%*c");

                    shot = 0;

                    bloodshot(name, playerLife, dealerLife, 99, 99);
                    displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                    cursor(37, 4);
                    printf("Sur qui voulez-vous tirer ?");

                    cursor(38, 4);
                    printf("[1] %s", name);

                    cursor(39, 4);
                    printf("[2] Dealer");

                    cursor(40, 4);
                    scanf("%i", &shot);

                    while(shot != 1 && shot != 2){

                        scanf("%*[^\n]%*c");

                        shot = 0;

                        cursor(11, 25);
                        printf("Choix invalide");

                        cursor(25, 25);
                        printf("Choix invalide");

                        sleep(1);

                        bloodshot(name, playerLife, dealerLife, 99, 99);
                        displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);
                        cursor(37, 4);
                        printf("Sur qui voulez-vous tirer ?");

                        cursor(38, 4);
                        printf("[1] %s", name);

                        cursor(39, 4);
                        printf("[2] Dealer");

                        cursor(40, 4);
                        scanf("%i", &shot);

                    }

                    if (shot == 1) { // Joueur tire sur Joueur

                        if (choiceBall == 1) { // Ball pleine

                            round = 2;

                            attente(name, playerLife, dealerLife, 99, 99);

                            fullBalls--;

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            if(shield == 1){

                                cursor(25, 5);

                                printf("Vous avez recu un balle vide ! Bouclier casser ! ");

                                cursor(25, 28);
                                printf("Boom !");

                                sleep(1);

                            }

                            else if(shield == 0){

                                if(sawing == 1){

                                    sawing = 0;

                                    cursor(25, 28);
                                    printf("Boom !");

                                    cursor(33, 75);
                                    printf("-2");

                                    sleep(2);

                                    playerLife = playerLife - 2;

                                }

                                else if(sawing == 0){

                                    cursor(25, 28);
                                    printf("Boom !");

                                    cursor(33, 75);
                                    printf("-1");

                                    sleep(2);

                                    playerLife--;

                                }

                            }

                        }

                        else if (choiceBall == 2) { // Ball a blanc

                            round = 1;

                            attente(name, playerLife, dealerLife, 99, 99);

                            emptyBalls--;

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            cursor(25, 8);
                            printf("Tu peux rejouer, tu as tire une balle vide !");

                            sleep(2);

                        }

                    }

                    else if (shot == 2) { // Joueur tire sur dealer

                        choiceBall = balls(emptyBalls, fullBalls);

                        if (choiceBall == 1) { // Ball pleine

                            round = 2;

                            attente(name, playerLife, dealerLife, 99, 99);

                            fullBalls--;

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            if(shield == 1){

                                cursor(25, 5);
                                printf("Vous avez recu un balle plein ! Bouclier ! ");

                                cursor(25, 28);
                                printf("Boom !");

                                sleep(1);

                            }

                            else if(shield == 0){

                                if(sawing == 1){

                                    sawing = 0;

                                    cursor(11, 28);
                                    printf("Boom !");

                                    cursor(3, 75);
                                    printf("-2");

                                    sleep(2);

                                    dealerLife = dealerLife - 2;

                                }

                                else if(sawing == 0){

                                    cursor(11, 28);
                                    printf("Boom !");

                                    cursor(3, 75);
                                    printf("-1");

                                    sleep(2);

                                    dealerLife--;

                                }

                            }

                        }

                        else if (choiceBall == 2) { // Ball a blanc

                            round = 2;

                            attente(name, playerLife, dealerLife, 99, 99);

                            emptyBalls--;

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            cursor(25, 8);

                            printf("Tu as tire une balle vide sur le dealer!");

                            sleep(2);

                        }

                    }

                }

            }

            if (dealerLife > 0){

                if(chain == 1){

                    chain = 0;

                    cursor(11, 13);

                    printf("Le dealeur est menotte !");

                    sleep(1);

                }


                else if(chain == 0){

                    while (round == 2) { // Tour du dealer !

                        if (emptyBalls == 0 && fullBalls == 0) { // verifie si il y a encore des balles

                            fullBalls = rand() % (nbBalls - 1) + 1;
                            emptyBalls = nbBalls - fullBalls;

                            bloodshot(name, playerLife, dealerLife, emptyBalls, fullBalls);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            cursor(11, 25);
                            printf("Rechargement...");

                            cursor(25, 25);
                            printf("Rechargement...");

                            sleep(2);

                        }

                        bloodshot(name, playerLife, dealerLife, 99, 99);
                        displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                        cursor(11, 13);
                        printf("Le dealer est entrain de jouer");

                        i = 0;

                        while (i <= 2) {

                            printf(".");

                            sleep(1);

                            i++;

                        }

                        clear();

                        shot = dealer(emptyBalls, fullBalls);

                        if (shot == 1) { // Dealer tire sur Dealer

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);
                            cursor(11, 12);
                            printf("Le dealer a choisie de se tire dessus !");

                            sleep(2);

                            choiceBall = balls(emptyBalls, fullBalls);

                            if (choiceBall == 1) { // Ball pleine

                                fullBalls--;

                                round = 1;

                                bloodshot(name, playerLife, dealerLife, 99, 99);
                                displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);
                                cursor(11, 28);
                                printf("Boom !");

                                cursor(3, 75);
                                printf("-1");

                                sleep(2);

                                dealerLife--;

                            }

                            else if (choiceBall == 2) { // Ball a blanc

                                emptyBalls--;

                                round = 2;

                            }

                        }

                        else if (shot == 2) { // Dealer tire sur joueur

                            bloodshot(name, playerLife, dealerLife, 99, 99);
                            displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                            cursor(11, 12);
                            printf("Le dealer a choisie de vous tire dessus !");

                            sleep(2);

                            choiceBall = balls(emptyBalls, fullBalls);

                            if (choiceBall == 1) { // Ball pleine

                                fullBalls--;

                                round = 1;

                                bloodshot(name, playerLife, dealerLife, 99, 99);
                                displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                                cursor(25, 28);
                                printf("Boom !");

                                cursor(33, 75);
                                printf("-1");

                                sleep(2);

                                playerLife--;

                            }

                            else if (choiceBall == 2) { // Ball a blanc

                                emptyBalls--;

                                round = 1;

                                bloodshot(name, playerLife, dealerLife, 99, 99);
                                displayBonus(nbChain, nbUnloading, nbAddingLife, nbLookBall, nbSawing, nbShield, dealerNbChain, dealerNbUnloading, dealerNbAddingLife, dealerNbLookBall, dealerNbSawing, dealerNbShield);

                                cursor(11, 8);
                                printf("Le dealer a tire une balle a blanc, il peut rejouer !");

                                sleep(2);

                            }

                        }

                    }


                }

            }

        }

        if(playerLife <= 0){ // Verifie si le joueur a perdu

            clear();

                printf("######################################\n");
                printf("#                                    #\n");
                printf("#  #     #  ######  #####   #######  #\n");
                printf("#  ##   ##  #    #  #    #     #     #\n");
                printf("#  # # # #  #    #  #    #     #     #\n");
                printf("#  #  #  #  #    #  #####      #     #\n");
                printf("#  #     #  #    #  #    #     #     #\n");
                printf("#  #     #  #    #  #    #     #     #\n");
                printf("#  #     #  ######  #    #     #     #\n");
                printf("#                                    #\n");
                printf("######################################\n");

            sleep(2);

            clear();

            while(leave != 99){

                printf("###########################\n");
                printf("#                         #\n");
                printf("#      [1] Rejouer        #\n");
                printf("#                         #\n");
                printf("#      [2] Quitter        #\n");
                printf("#                         #\n");
                printf("###########################\n");

                scanf("%i",&leave);

                clear();

                if(leave == 1){

                    leave = 99;

                }

                else if(leave == 2){

                    printf("####################################\n");
                    printf("#                                  #\n");
                    printf("#  Deconnexion du jeu en cours...  #\n");
                    printf("#                                  #\n");
                    printf("####################################\n");

                    sleep(5);

                    clear();

                    return leave;

                }

                else{}

            }

        }

    }

    if(dealerLife == 0){

        clear();

        printf("##############################################\n");
        printf("#                                            #\n");
        printf("#  #####   #####      #     #     #  ######  #\n");
        printf("#  #    #  #    #    # #    #     #  #    #  #\n");
        printf("#  #    #  #    #    # #     #   #   #    #  #\n");
        printf("#  #####   #####    #   #    #   #   #    #  #\n");
        printf("#  #    #  #    #   #####     # #    #    #  #\n");
        printf("#  #    #  #    #  #     #    # #    #    #  #\n");
        printf("#  #####   #    #  #     #     #     ######  #\n");
        printf("#                                            #\n");
        printf("##############################################\n");

        sleep(3);

        clear();

        printf("######################################\n");
        printf("#                                    #\n");
        printf("#  Code de sauvegarde de partie : 3  #\n");
        printf("#                                    #\n");
        printf("######################################\n");

        sleep(5);

        clear();

        return 0;

    }



}

// ---------------------------------------------- [ Main ] ---------------------------------------------- //

void main(void) {

    srand(time(NULL));  // Initialisation de la graine pour la generation de nombres aleatoires

    clear();

    // --- [ Variables ] --- //

    char name[50];
    int stop = 0;
    int rounds = 1;
    int level = 1;
    int navigation;
    int leave;

    // --- [ Programme ] --- //

    config();

    navigation = menu();

    while (stop != 1){

        // --- [ BloodShot ] --- //

        if (navigation == 1) {

            if (level == 1){

                contrat(name);

                level = 1;

                leave = level1(name);

                clear();

                if(leave == 2){

                   navigation = menu();

                }

                else{

                    level = 2;

                }
            }

            else if(level == 2) {

                level = 1;

                leave = level2(name);

                clear();

                if(leave == 2){

                   navigation = menu();

                }

                else{

                    level = 3;

                }

            }

            else if(level == 3) {

                level = 1;

                leave = level3(name);

                clear();

                if(leave == 2){

                   navigation = menu();

                }

                else{

                    level = 3;

                }

            }

        }

        // --- [ Histoire ] --- //

        else if (navigation == 2) {

            printf("##############################################################################################################\n");
            printf("#                                                                                                            #\n");
            printf("#  Dans un monde post-apocalyptique ou la survie est un jeu de hasard, Alex prend le risque ultime en        #\n");
            printf("#                                                                                                            #\n");
            printf("#  participant a Buckshot Roulette. Face a un mysterieux dealeur, il defie le destin avec un revolver charge #\n");
            printf("#                                                                                                            #\n");
            printf("#  de desespoir. Chaque coup de feu rapproche Alex de la fortune tant convoitee, mais aussi de l'abime de    #\n");
            printf("#                                                                                                            #\n");
            printf("#  la mort. Dans un moment de tension palpable, il triomphe en abattant le dealeur pour remporter le prix    #\n");
            printf("#                                                                                                            #\n");
            printf("#  tant attendu. Mais meme avec la richesse en main, les cicatrices du jeu restent gravees dans son ame,     #\n");
            printf("#                                                                                                            #\n");
            printf("#  rappelant que dans ce monde impitoyable, la securite a un prix bien plus eleve que celui affiche.         #\n");
            printf("#                                                                                                            #\n");
            printf("##############################################################################################################\n");

            sleep(35);

            clear();

            navigation = menu();

        }

        // --- [ Sauvegarde ] --- //

        else if (navigation == 3) {

            int save;

            printf("###############################\n");
            printf("#                             #\n");
            printf("#                             #\n");
            printf("#  code :                     #\n");
            printf("#                             #\n");
            printf("#                             #\n");
            printf("###############################\n");

            cursor(4, 11);            scanf("%i",&save);

            clear();

            if(save >= 1 && save <= 3) {

                if(save != 1){

                    contrat(name);

                }

                navigation = 1;

                level = save;

            }

            else {

                printf("Choix invalide\n");

                sleep(2);

                clear();

                navigation = menu();

            }

        }

        // --- [ Arrets ] --- //

        else if (navigation == 4) {

            stop = 1;

        }

        // --- [ Erreurs ] --- //

        else {

            scanf("%*[^\n]%*c");

            printf("Choix invalide\n");

            sleep(1);

            clear();

            navigation = menu();

        }

    }

    return 0;
}
