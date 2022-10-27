#include "func_trans.h"
/*
 * Projet : Takuzu réalisé par Marc ROUGAGNOU et Gaël RAIMBAULT
 * Ce fichier contient l'ensemble des fonctions utiles au projet.
 * On a donc les fonctions d'une grille 4x4 comme 8x8.
 */

int transform_4x4(char cas[]) { // transforme A1 en 0 et D4 en 33 (fonctionne) / paramètre : cas une case sous forme de char / retourne l'entier associé à la case
    return 10 * (cas[0] - 65) + cas[1] - 49;
}

void solution_4x4(int tak_solu[4][4]) { //banque de solutions (fonctionne) / paramètre: tak_solu la grille solution / ne retourne rien, car cela touche directement au tableau
    int tak1[4][4] = {0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0};
    int tak2[4][4] = {1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1};
    int tak3[4][4] = {0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0};
    int tak4[4][4] = {1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1};
    int tak5[4][4] = {1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0};
    int nb = rand() % 5; // choix de la grille solution
    if (nb == 0) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                tak_solu[i][j] = tak1[i][j];
            }
        }
    }
    if (nb == 1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                tak_solu[i][j] = tak2[i][j];
            }
        }
    }
    if (nb == 2) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                tak_solu[i][j] = tak3[i][j];
            }
        }
    }
    if (nb == 3) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                tak_solu[i][j] = tak4[i][j];
            }
        }
    }
    if (nb == 4) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                tak_solu[i][j] = tak5[i][j];
            }
        }
    }
}

void mask_4x4(int mask[4][4]) { //chaque case à 1 chance sur 4 (de 0 à 3) d'être montré (fonctionne) / paramètre: mask le mask / ne retourne rien, car les changements se font directement dessus
    int nb;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            nb = rand() % 4;
            if (nb == 1) {
                mask[i][j] = 1; // choix de si la case est affichée ou non
            } else {
                mask[i][j] = 0;
            }
        }
    }
}

void tak_play_4x4(int tak_jeu[4][4], int mask[4][4], int tak_solu[4][4]) { // génère la grille de jeu (fonctionne) /paramètre : tak_jeu la grille de jeu, mask le mask et tak_solu la grille solution / ne retourne rien, car tout se change directement dans la fonction
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mask[i][j] == 1) {
                tak_jeu[i][j] = tak_solu[i][j]; // initialisation de la grille de jeu par rapport au mask
            } else {
                tak_jeu[i][j] = -1;
            }
        }
    }
}

void print_tak_4x4(int T[4][4]) {  // affiche une grille de jeu (fonctionne) / paramètre: T une grille / ne retourne rien, car ce sont des printf
    printf("    A   B   C   D\n");
    for (int i = 0; i < 4; i++) {
        printf("  _________________\n");
        printf("%d |", i + 1);
        for (int j = 0; j < 4; j++) {
            if (T[i][j] == -1) {
                printf("   |");
            } else {
                printf(" %d |", T[i][j]);
            }
        }
        printf("\n");
    }
    printf("  _________________\n");
}

int verif_row_4x4(int T[4][4], int cas) { //vérifie lignes identiques  (fonctionne) /paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas % 10;
    for (int i = 0; i < 4; i++) {
        if (i != coup)
            if (T[i][0] != -1 && T[i][1] != -1 && T[i][2] != -1 && T[i][3] != -1 && T[coup][0] != -1 &&
                T[coup][1] != -1 && T[coup][2] != -1 && T[coup][3] != -1) // condition de-ci 2 lignes sont identiques
                if (T[i][0] == T[coup][0] && T[i][1] == T[coup][1] && T[i][2] == T[coup][2] && T[i][3] == T[coup][3])
                    return 1;
    }
    return 0;
}

int verif_col_4x4(int T[4][4], int cas) { //vérifie colonnes identiques  (fonctionne)/ paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas / 10;
    for (int i = 0; i < 4; i++) {
        if (T[0][i] != -1 && T[1][i] != -1 && T[2][i] != -1 && T[3][i] != -1 && T[0][coup] != -1 && T[1][coup] != -1 &&
            T[2][coup] != -1 && T[3][coup] != -1)// condition de-ci 2 colonnes sont identiques
            if (i != coup)
                if (T[0][i] == T[0][coup] && T[1][i] == T[1][coup] && T[2][i] == T[2][coup] && T[3][i] == T[3][coup])
                    return 1;
    }
    return 0;
}

int row_3_4x4(int T[4][4], int cas) { // Vérifie s'il y a autant de 1 et 0 en ligne (fonctionne) / paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas % 10;
    int un = 0, zero = 0;
    for (int i = 0; i < 4; i++) {
        if (T[coup][i] == 1) {
            un += 1;
        } if (T[coup][i] == 0) {
            zero += 1;
        }
    }
    if (un > 2 || zero > 2) { // analyse du nombre de 1 et de 0 dans la grille
        return 1;
    }
    return 0;
}

int col_3_4x4(int T[4][4], int cas) { // Vérifie s'il y a autant de 1 et 0 en colonne (fonctionne) / paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas / 10;
    int un = 0, zero = 0;
    for (int i = 0; i < 4; i++) {
        if (T[i][coup] == 1) {
            un += 1;
        }
        if (T[i][coup] == 0) {
            zero += 1;
        }
    }
    if (un > 2 || zero > 2) { // analyse du nombre de 1 et de 0 dans la grille
        return 1;
    }
    return 0;
}

int verif_3_col_4x4(int T[4][4], int cas) {//vérifie 3 affilés sur la colonne (fonctionne) / paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas / 10;
    int cpt = 1, temp = T[0][coup], temp2 = 0;
    for (int i = 1; i < 4; i++) { // boucle de la colonne
        if (temp == 1) {
            temp2 = 0;
        } else {
            temp2 = 1;
        }
        if (T[i][coup] == temp) {
            cpt += 1;
        }
        if (T[i][coup] == temp2) {
            temp = T[i][coup];
            cpt = 1;
        }
        if (T[i][coup] == -1) {
            cpt = 0;
        }
        if (cpt == 3) // si cpt==3 alors 3 mêmes nombres sont mis d'affiler donc faux et on retourne 1
            return 1;
    }
    return 0;
}

int verif_3_row_4x4(int T[4][4], int cas) {// vérifie 3 affilés sur la ligne (fonctionne) / paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas % 10; //
    int cpt = 1, temp = T[coup][0], temp2 = 0;
    for (int i = 1; i < 8; i++) {
        if (temp == 1) {
            temp2 = 0;
        } else {
            temp2 = 1;
        }
        if (T[coup][i] == temp) {
            cpt += 1;
        }
        if (T[coup][i] == temp2) {
            temp = T[coup][i];
            cpt = 1;
        }
        if (T[coup][i] == -1) {
            cpt = 0;
        }
        if (cpt == 3)// si cpt==3 alors 3 mêmes nombres sont mis d'affiler donc faux et on retourne 1
            return 1;
    }
    return 0;
}

int move_valid_4x4(int T[4][4], int cas) { // permet de voir si le coup est valide (fonctionne) / paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    if (row_3_4x4(T, cas)) { // chaque condition pour placer un chiffre avec le message d'erreurs associé
        printf("Il y a plus d'un certain chiffre qu'un autre, verifier la ligne.\n");
        return 1;
    } if (col_3_4x4(T, cas)) {
        printf("Il y a plus d'un certain chiffre qu'un autre, verifier la colonne.\n");
        return 1;
    } if (verif_row_4x4(T, cas)) {
        printf("Deux lignes sont identique, verifier la ligne.\n");
        return 1;
    } if (verif_col_4x4(T, cas)) {
        printf("Deux colonnes sont identique, verifier la colonne.\n");
        return 1;
    } if (verif_3_row_4x4(T, cas)) {
        printf("3 chiffres similaires se suivent, verifier la ligne.\n");
        return 1;
    } if (verif_3_col_4x4(T, cas)) {
        printf("3 chiffres similaires se suivent, verifier la colonne.\n");
        return 1;
    }
    return 0;
}

int move_correct_4x4(int T[4][4], int cas, int tak_solu[4][4]) { // vérifie si c'est le coup est correct (fonctionne) / paramètre: T une grille, cas une case et tak_solu la grille solution associée / retourne 0 si cela marche et 1 sinon
    int col = cas / 10, lign = cas % 10;
    if (T[lign][col] == tak_solu[lign][col]) {
        return 0;
    }
    return 1;
}

void crt_mask_4x4(int mask[4][4]){ // l'utilisateur génère un mask (fonctionne) / paramètre: mask une grille de mask / ne retourne rien, car on change le mask dans la fonction
    int continuer=1; //savoir s'il veut découvrir d'autres cases
    char cas_char[3];
    int cas_int;
    printf("Voici le mask actuel:\n");
    do{
        print_tak_4x4(mask);
        printf("Rentrer la case a decouvrir:\n");
        do {
            printf("Saisir colonne puis ligne :\n");
            scanf("%s", cas_char);
            cas_int = transform_4x4(cas_char);
        } while (((cas_char[0] < 65) || (cas_char[0] > 68)) || ((cas_char[1] < 49) || (cas_char[1] > 52)));
        mask[cas_int%10][cas_int/10]=1; // modification de la grille de mask
        do{
            printf("Voulez-vous continuer ?\n1 - Oui\n2 - Non\n");
            scanf("%d",&continuer);
        }while (continuer != 1 && continuer != 2);
    }while(continuer==1);
}

int placement_4x4(int T[4][4], int T_solut[4][4]) { // permet de jouer et placer (fonctionne) / paramètre : T une grille de jeu et T_solut sa grille solution / retourne 0 si cela marche et 1 ou 2 sinon
    int cas_int, val, col;
    char cas_char[3];
    do {
        printf("Saisir colonne puis ligne :\n");
        scanf("%s", cas_char);
        cas_int = transform_4x4(cas_char);
    } while (((cas_char[0] < 65) || (cas_char[0] > 68)) || ((cas_char[1] < 49) || (cas_char[1] > 52))); // saisie sécurisée
    col = cas_int / 10;
    do {
        printf("Saisir 1 ou 0 :\n");
        scanf("%d", &val);
    } while (val != 1 && val != 0);// saisie sécurisée
    T[cas_int % 10][col] = val;
    if (move_correct_4x4(T, cas_int, T_solut) == 1) {
        printf("Coup valide mais incorrect\n");
        T[cas_int % 10][cas_int / 10] = -1;
        print_tak_4x4(T);
        return 2;
    if (move_valid_4x4(T, cas_int)) {
        printf("Coup invalide\n");
        T[cas_int % 10][cas_int / 10] = -1;
        print_tak_4x4(T);
        return 1;
    }

}
    print_tak_4x4(T);
    printf("Coup correct ! ");
    return 0;
}

int full_tak_4x4(int tak[4][4]) { // permet de voir si grille est remplie (fonctionne) / paramètre: tak une grille / retourne 0 si cela marche et 1 sinon
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (tak[i][j] == -1) // si pas de nombre sur la case alors la condition n'est pas rempli
                return 1;
    return 0;
}



/* Passage au 8X8 partie 1 */
/* les fonctions auront le même nom, mais avec 8x8 à la place */

int transform_8x8(char cas[]) {// transforme A1 en 0 et D4 en 33 (fonctionne) / paramètre : une case sous forme de char / retourne l'entier associé à la case
    return 10 * (cas[0] - 65) + cas[1] - 49;
}

void solution_8x8(int tak_solu[8][8]) { //banque de solutions (fonctionne) / paramètre: tak_solu la grille solution / ne retourne rien, car cela touche directement au tableau
    int tak1[8][8] = {
            {1, 0, 1, 1, 0, 1, 0, 0},
            {1, 0, 1, 0, 1, 0, 0, 1},
            {0, 1, 0, 1, 1, 0, 1, 0},
            {0, 1, 0, 1, 0, 1, 1, 0},
            {1, 0, 1, 0, 0, 1, 0, 1},
            {0, 1, 0, 0, 1, 0, 1, 1},
            {0, 0, 1, 1, 0, 1, 1, 0},
            {1, 1, 0, 0, 1, 0, 0, 1}};
    int tak2[8][8] = {
            {0, 0, 1, 0, 1, 0, 1, 1},
            {1, 0, 0, 1, 0, 1, 0, 1},
            {0, 1, 0, 1, 1, 0, 1, 0},
            {0, 1, 1, 0, 0, 1, 1, 0},
            {1, 0, 1, 0, 0, 1, 0, 1},
            {1, 0, 0, 1, 1, 0, 0, 1},
            {0, 1, 1, 0, 1, 0, 1, 0},
            {1, 1, 0, 1, 0, 1, 0, 0}};

    int tak3[8][8] = {
            {1, 0, 0, 1, 0, 1, 0, 1},
            {0, 0, 1, 1, 0, 0, 1, 1},
            {1, 1, 0, 0, 1, 1, 0, 0},
            {1, 1, 0, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 1, 0, 1, 1},
            {0, 0, 1, 1, 0, 1, 0, 1},
            {1, 1, 0, 0, 1, 0, 1, 0},
            {0, 1, 1, 0, 1, 0, 1, 0}};
    int nb = rand() % 3; // choix de la grille solution
    if (nb == 0) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                tak_solu[i][j] = tak1[i][j];
            }
        }
    }
    if (nb == 1) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                tak_solu[i][j] = tak2[i][j];
            }
        }
    }
    if (nb == 2) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                tak_solu[i][j] = tak3[i][j];
            }
        }
    }
}

void mask_8x8(int mask[8][8]) {//chaque case à 1 chance sur 4 (de 0 à 3) d'être montré (fonctionne) / paramètre: mask une grille mask / ne retourne rien, car les changements se font directement dessus
    int nb;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            nb = rand() % 4; // pourcentage de chance d'être affiché
            if (nb == 1) {
                mask[i][j] = 1;
            } else {
                mask[i][j] = 0;
            }
        }
    }
}

void tak_play_8x8(int tak_jeu[8][8], int mask[8][8], int tak_solu[8][8]) { // génère la grille de jeu (fonctionne) /paramètre : tak_jeu la grille de jeu, mask une grille mask et tak_solu la grille solution / ne retourne rien, car tout se change directement dans la fonction
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (mask[i][j] == 1) {
                tak_jeu[i][j] = tak_solu[i][j];
            } else {
                tak_jeu[i][j] = -1;
            }
        }
    }
}

void print_tak_8x8(int T[8][8]) { // affiche une grille de jeu (fonctionne) / paramètre: T une grille / ne retourne rien, car ce sont des printf
    printf("    A   B   C   D   E   F   G   H\n");
    for (int i = 0; i < 8; i++) {
        printf("  __________________________________\n");
        printf("%d |", i + 1);
        for (int j = 0; j < 8; j++) {
            if (T[i][j] == -1) {
                printf("   |");
            } else {
                printf(" %d |", T[i][j]);
            }
        }
        printf("\n");
    }
    printf("  __________________________________\n");
}

int verif_row_8x8(int T[8][8], int cas) { //vérifie lignes identiques  (fonctionne) /paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas % 10;
    for (int i = 0; i < 8; i++) {
        if (i != coup)
            if (T[i][0] != -1 && T[i][1] != -1 && T[i][2] != -1 && T[i][3] != -1 && T[i][4] != -1 && T[i][5] != -1 &&
                T[i][6] != -1 && T[i][7] != -1 &&
                T[coup][0] != -1 && T[coup][1] != -1 && T[coup][2] != -1 && T[coup][3] != -1 && T[coup][4] != -1 &&
                T[coup][5] != -1 && T[coup][6] != -1 && T[coup][7] != -1) // différentes conditions pour la réalisation de la demande
                if (T[i][0] == T[coup][0] && T[i][1] == T[coup][1] && T[i][2] == T[coup][2] && T[i][3] == T[coup][3] &&
                    T[i][4] == T[coup][4] && T[i][5] == T[coup][5] && T[i][6] == T[coup][6] && T[i][7] == T[coup][7])
                    return 1;
    }
    return 0;
}

int verif_col_8x8(int T[8][8], int cas) { //vérifie colonnes identiques  (fonctionne)/ paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas / 10;
    for (int i = 0; i < 4; i++) {
        if (T[0][i] != -1 && T[1][i] != -1 && T[2][i] != -1 && T[3][i] != -1 && T[4][i] != -1 && T[5][i] != -1 &&
            T[6][i] != -1 && T[7][i] != -1 &&
            T[0][coup] != -1 && T[1][coup] != -1 && T[2][coup] != -1 && T[3][coup] != -1 && T[4][coup] != -1 &&
            T[5][coup] != -1 && T[6][coup] != -1 && T[7][coup] != -1)// différentes conditions pour la réalisation de la demande
            if (i != coup)
                if (T[0][i] == T[0][coup] && T[1][i] == T[1][coup] && T[2][i] == T[2][coup] && T[3][i] == T[3][coup] &&
                    T[4][i] == T[4][coup] && T[5][i] == T[5][coup] && T[6][i] == T[6][coup] && T[7][i] == T[7][coup])
                    return 1;
    }
    return 0;
}

int row_3_8x8(int T[8][8], int cas) { // Vérifie s'il y a autant de 1 et 0 en ligne (fonctionne) / paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas % 10;//return 1 quand faux
    int un = 0, zero = 0;
    for (int i = 0; i < 8; i++) {
        if (T[coup][i] == 1) {
            un += 1;
        } if (T[coup][i] == 0) {
            zero += 1;
        }
    }
    if (un > 4 || zero > 4) { // vérification du nombre de 1 et de 0
        return 1;
    }
    return 0;
}

int col_3_8x8(int T[8][8], int cas) { // Vérifie s'il y a autant de 1 et 0 en colonne (fonctionne) / paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas / 10; // Retourne 1 quand faux
    int un = 0, zero = 0;
    for (int i = 0; i < 8; i++) {
        if (T[i][coup] == 1) {
            un += 1;
        } if (T[i][coup] == 0) {
            zero += 1;
        }
    }
    if (un > 4 || zero > 4) {// vérification du nombre de 1 et de 0
        return 1;
    }
    return 0;
}

int verif_3_col_8x8(int T[8][8], int cas) {//vérifie 3 affilés sur la colonne (fonctionne) / paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas / 10;
    int cpt = 1, temp = T[0][coup], temp2 = 0;
    for (int i = 1; i < 8; i++) {
        if (temp == 1) {
            temp2 = 0;
        } else {
            temp2 = 1;
        }
        if (T[i][coup] == temp) {
            cpt += 1;
        }
        if (T[i][coup] == temp2) {
            temp = T[i][coup];
            cpt = 1;
        }
        if (T[i][coup] == -1) {
            cpt = 0;
        }
        if (cpt == 3)// vérification du nombre de 1 et de 0 d'affilée
            return 1;
    }
    return 0;
}

int verif_3_row_8x8(int T[8][8], int cas) {// vérifie 3 affilés sur la ligne (fonctionne) / paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    int coup = cas % 10; //
    int cpt = 1, temp = T[coup][0], temp2 = 0;
    for (int i = 1; i < 8; i++) {
        if (temp == 1) {
            temp2 = 0;
        } else {
            temp2 = 1;
        }
        if (T[coup][i] == temp) {
            cpt += 1;
        }
        if (T[coup][i] == temp2) {
            temp = T[coup][i];
            cpt = 1;
        }
        if (T[coup][i] == -1) {
            cpt = 0;
        }
        if (cpt == 3)// vérification du nombre de 1 et de 0 d'affilée
            return 1;
    }
    return 0;
}

int move_valid_8x8(int T[8][8], int cas) { // vérifie que le coup est valide (fonctionne) / paramètre : T une grille et cas une case / retourne 0 si cela marche et 1 sinon
    if (row_3_8x8(T, cas)) {// vérification des conditions et affichage du message d'erreur si nécessaire
        printf("Il y a plus d'un certain chiffre qu'un autre, verifier la ligne.\n");
        return 1;
    } if (col_3_8x8(T, cas)) {
        printf("Il y a plus d'un certain chiffre qu'un autre, verifier la colonne.\n");
        return 1;
    } if (verif_row_8x8(T, cas)) {
        printf("Deux lignes sont identique, verifier la ligne.\n");
        return 1;
    } if (verif_col_8x8(T, cas)) {
        printf("Deux colonnes sont identique, verifier la colonne.\n");
        return 1;
    } if (verif_3_row_8x8(T, cas)) {
        printf("3 chiffres similaires se suivent, verifier la ligne.\n");
        return 1;
    } if (verif_3_col_8x8(T, cas)) {
        printf("3 chiffres similaires se suivent, verifier la colonne.\n");
        return 1;
    }
    return 0;
}

int move_correct_8x8(int T[8][8], int cas, int tak_solu[8][8]) {// vérifie si c'est le coup est correct (fonctionne) / paramètre: T une grille, cas une case et tak_solu la grille solution associée / retourne 0 si cela marche et 1 sinon
    int col = cas / 10, lign = cas % 10;
    if (T[lign][col] == tak_solu[lign][col]) {
        return 0;
    }
    return 1;
}

void crt_mask_8x8(int mask[8][8]){ // l'utilisateur génère un mask (fonctionne) / paramètre: mask une grille mask / ne retourne rien, car on change le mask dans la fonction
    int continuer=1; //savoir s'il veut découvrir d'autres cases
    char cas_char[3];
    int cas_int;
    printf("Voici le mask actuel:\n");
    do{
        print_tak_8x8(mask);
        printf("Rentrer la case a decouvrir:\n");
        do {
            printf("Saisir colonne puis ligne :\n");
            scanf("%s", cas_char);
            cas_int = transform_8x8(cas_char);
        } while (((cas_char[0] < 65) || (cas_char[0] > 68)) || ((cas_char[1] < 49) || (cas_char[1] > 52))); // saisie sécurisée
        mask[cas_int%10][cas_int/10]=1; // mise à jour du mask
        do{
            printf("Voulez-vous continuer ?\n1 - Oui\n2 - Non\n");
            scanf("%d",&continuer);
        }while (continuer!=1 && continuer!=2);// saisie sécurisée
    }while(continuer==1);
}

int placement_8x8(int T[8][8], int T_solut[8][8]) { // permet de jouer et placer (fonctionne) / paramètre : T une grille de jeu et T_solu sa grille solution / retourne 0 si cela marche et 1 ou 2 sinon
    int cas_int, val, col;
    char cas_char[3];
    do {
        printf("Saisir colonne puis ligne :\n");
        scanf("%s", cas_char);
        cas_int = transform_8x8(cas_char);
    } while (((cas_char[0] < 65) || (cas_char[0] > 72)) || ((cas_char[1] < 49) || (cas_char[1] > 56)));// saisie sécurisée
    col = cas_int / 10;
    do {
        printf("Saisir 1 ou 0 :\n");
        scanf("%d", &val);
    } while (val != 1 && val != 0);
    T[cas_int % 10][col] = val; // modification dans la grille de jeu
    if (move_correct_8x8(T, cas_int, T_solut) == 1) {
        printf("Coup valide mais incorrect\n");
        T[cas_int % 10][cas_int / 10] = -1;
        print_tak_8x8(T);
        return 2;
    }
    if (move_valid_8x8(T, cas_int)) {
        printf("Coup invalide\n");
        T[cas_int % 10][cas_int / 10] = -1;
        print_tak_8x8(T);
        return 1;
    }
    print_tak_8x8(T);
    printf("Coup correct !!");
    return 0;
}

int full_tak_8x8(int tak[8][8]) { // permet de voir si grille est remplie (fonctionne) / paramètre: tak une grille / retourne 0 si cela marche et 1 sinon
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (tak[i][j] == -1)
                return 1;
    return 0;
}

/* partie 3 */

/* partie 4x4 */

void wait_affiche_4x4(int T[4][4]){ // Attends que la personne rentre un caractère pour passer à la suite / paramètre : T une grille / ne retourne rien, car c'est une fonction d'affichage
    char null[10];
    printf("Rentre un caractere pour passer a l'etape suivante\n");
    scanf("%s", null);
    print_tak_4x4(T);
}

void row_auto_4x4(int T[4][4]){ // rempli les lignes automatiquement / paramètre : T une grille / ne retourne rien, car modifie directement le tableau
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (T[i][j] == -1) {
                if ((i - 2) < 0) {
                    if (T[i + 1][j] == T[i + 2][j] && T[i + 1][j] != -1) {
                        T[i][j] = -(T[i + 1][j] - 1); // condition 3 mêmes nombres d'affilés
                        wait_affiche_4x4(T);
                    }
                } else {
                    if (T[i - 1][j] == T[i - 2][j] && T[i - 1][j] != -1) {
                        T[i][j] = -(T[i - 1][j] - 1);// condition 3 mêmes nombres d'affilés
                        wait_affiche_4x4(T);
                        if (T[i + 1][j] == -1 && i + 1 < 4) {
                            T[i + 1][j] = T[i][j];
                            wait_affiche_4x4(T);
                        }
                    }
                }
                if ((i - 1) >= 0 && (i + 1) < 4) {
                    if (T[i - 1][j] == T[i + 1][j] && T[i + 1][j] != -1) {
                        T[i][j] = -(T[i + 1][j] - 1);// condition 3 mêmes nombres d'affilés
                        wait_affiche_4x4(T);
                        if (T[i - 2][j] == -1 && i - 2 >= 0) {
                            T[i - 2][j] = T[i][j];
                            wait_affiche_4x4(T);
                        }
                        if (T[i + 2][j] == -1 && i + 2 < 4) {
                            T[i + 2][j] = T[i][j];
                            wait_affiche_4x4(T);
                        }
                    }
                }
            }
            if (T[i][0] == T[i][3] && T[i][0] != -1 && (T[i][1] == -1 && T[i][1] == T[i][2])) {
                T[i][1] = T[i][2] = -(T[i][0] - 1);
                wait_affiche_4x4(T);
            }
        }
    }
}

void col_auto_4x4(int T[4][4]) { // rempli les colonnes automatiquement / paramètre : T une grille / ne retourne rien, car modifie directement les grilles
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (T[i][j] == -1) {
                if ((j - 2) < 0) {
                    if (T[i][j + 1] == T[i][j + 2] && T[i][j + 1] != -1) {
                        T[i][j] = -(T[i][j + 1] - 1);// condition 3 mêmes nombres d'affilés
                        wait_affiche_4x4(T);
                    }
                } else {
                    if (T[i][j - 1] == T[i][j - 2] && T[i][j - 1] != -1) {
                        T[i][j] = -(T[i][j - 1] - 1);// condition 3 mêmes nombres d'affilés
                        wait_affiche_4x4(T);
                        if (T[i][j + 1] == -1 && j + 1 < 4) {
                            T[i][j + 1] = T[i][j];
                            wait_affiche_4x4(T);
                        }
                    }
                }
                if ((j - 1) >= 0 && (j + 1) < 4) {
                    if (T[i][j - 1] == T[i][j + 1] && T[i][j + 1] != -1) {// condition 3 mêmes nombres d'affilés
                        T[i][j] = -(T[i][j + 1] - 1);
                        wait_affiche_4x4(T);
                        if (T[i][j - 2] == -1 && j - 2 >= 0) {
                            T[i][j - 2] = T[i][j];
                            wait_affiche_4x4(T);
                        }
                        if (T[i][j + 2] == -1 && j + 2 < 4) {
                            T[i][j + 2] = T[i][j];
                            wait_affiche_4x4(T);
                        }
                    }
                }
            }
            if (T[0][i] == T[3][i] && T[0][i] != -1 && (T[1][i] == -1 && T[1][i] == T[2][i])) {
                T[1][i] = T[2][i] = -(T[0][i] - 1);
                wait_affiche_4x4(T);
            }
        }
    }
}

void hint_fill_4x4(int T[4][4], int T_solut[4][4]){ // découvre une case aléatoire / paramètre : T une grille de jeu et T_solut sa grille solution / ne retourne rien, car on modifie directement les tableaux
    if(full_tak_4x4(T)) {
        int cas_int, val, col;
        do {
            cas_int = (rand() % 5) * 10 + rand() % 5;
        } while (T[cas_int % 10][cas_int / 10] != -1);
        T[cas_int % 10][cas_int / 10] = T_solut[cas_int % 10][cas_int / 10]; // débloquer l'ordinateur simulation de l'aléatoire d'un humain
    }
}


int verif_modif_4x4(int temp[4][4], int T[4][4]){ // vérifie si le tableau temp à changer / paramètres : temp une grille et T une autre grille/ retourne 1 si le tableau a changé, 0 sinon
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(temp[i][j] != T[i][j])
                return 1;
    return 0;
}

void auto_tak_4x4(int T[4][4],int T_solut[4][4]) { // utilise les fonctions précédentes pour remplir le tab T / paramètre : T une grille de jeu et T_solut sa grille solution / ne retourne rien, car il y a une modification directe des grilles
    int temp[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][j] = T[i][j];
    while (full_tak_4x4(T) != 0) { // utilisation des fonctions précédentes
        do {
            for (int k = 0; k < 4; k++)
                for (int m = 0; m < 4; m++)
                    temp[k][m] = T[k][m];
            row_auto_4x4(T);
            col_auto_4x4(T);
        } while (verif_modif_4x4(temp, T));
        hint_fill_4x4(T, T_solut);
        wait_affiche_4x4(T);
    }
}

void auto_tak_4x4_final(int T[4][4],int T_solut[4][4]) { // utilise les fonctions précédentes pour remplir le tab T / paramètre : T une grille de jeu et T_solut la grille solution / ne retourne rien, car ce sont des vérifications et des affichages
    int temp[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            temp[i][j] = T[i][j];
    while (full_tak_4x4(T)) {// utilisation des fonctions précédentes
        do{
            for(int k = 0; k < 4; k++)
                for(int m = 0; m < 4; m++)
                    temp[k][m] = T[k][m];
            row_auto_4x4(T);
            col_auto_4x4(T);
        }while(verif_modif_4x4(temp, T));
        hint_fill_4x4(T,T_solut);
    }
    print_tak_4x4(T);
}

/* partie 8x8 */

void wait_affiche_8x8(int T[8][8]){ // Attends que la personne rentre un caractère pour passer à la suite / paramètre : T une grille / ne retourne rien, car c'est une fonction d'affichage
    char null[10];
    printf("Rentre un caractere pour passer a l'etape suivante");
    scanf("%s", null);
    print_tak_8x8(T);
}

void row_auto_8x8(int T[8][8]){ // rempli les lignes automatiquement / paramètre : T une grille / ne retourne rien, car modifie directement le tableau
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (T[i][j] == -1) {
                if ((i - 2) < 0) {
                    if (T[i + 1][j] == T[i + 2][j] && T[i + 1][j] != -1) {// condition 3 mêmes nombres d'affilés
                        T[i][j] = -(T[i + 1][j] - 1);
                        wait_affiche_8x8(T);
                    }
                } else {
                    if (T[i - 1][j] == T[i - 2][j] && T[i - 1][j] != -1) {// condition 3 mêmes nombres d'affilés
                        T[i][j] = -(T[i - 1][j] - 1);
                        wait_affiche_8x8(T);
                    }
                }
                if ((i - 1) >= 0 && (i + 1) < 8) {
                    if (T[i - 1][j] == T[i + 1][j] && T[i + 1][j] != -1) {
                        T[i][j] = -(T[i + 1][j] - 1);
                        wait_affiche_8x8(T);
                    }
                }
            }
        }
    }
}
void col_auto_8x8(int T[8][8]) { // rempli les colonnes automatiquement / paramètre : T une grille / ne retourne rien, car modifie directement les grilles
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (T[i][j] == -1) {
                if ((j - 2) < 0) {
                    if (T[i][j + 1] == T[i][j + 2] && T[i][j + 1] != -1) {// condition 3 mêmes nombres d'affilés
                        T[i][j] = -(T[i][j + 1] - 1);
                        wait_affiche_8x8(T);
                    }
                } else {
                    if (T[i][j - 1] == T[i][j - 2] && T[i][j - 1] != -1) {// condition 3 mêmes nombres d'affilés
                        T[i][j] = -(T[i][j - 1] - 1);
                        wait_affiche_8x8(T);
                    }
                }
                if ((j - 1) >= 0 && (j + 1) < 8) {
                    if (T[i][j - 1] == T[i][j + 1] && T[i][j + 1] != -1) {
                        T[i][j] = -(T[i][j + 1] - 1);
                        wait_affiche_8x8(T);
                    }
                }
            }
        }
    }
}

void hint_fill_8x8(int T[8][8], int T_solut[8][8]){ // découvre une case aléatoire / paramètres : T une grille de jeu et T_solu sa grille solution / ne retourne rien, car on modifie directement les tableaux
    if(full_tak_8x8(T)) {
        int cas_int, val, col;
        do {
            cas_int = (rand() % 9) * 10 + rand() % 9;
        } while (T[cas_int % 10][cas_int / 10] != -1);
        T[cas_int % 10][cas_int / 10] = T_solut[cas_int % 10][cas_int / 10];

    }
}

int verif_modif_8x8(int temp[8][8], int T[8][8]){ // vérifie si le tableau temp à changer / paramètres : temp une grille et T une autre grille / retourne 1 si faux et 0 si c'est bon
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(temp[i][j] != T[i][j])
                return 1;
    return 0;
}

void auto_tak_8x8(int T[8][8],int T_solut[8][8]) { // utilise les fonctions précédentes pour remplir le tab T / paramètres : T une grille de jeu et T_solut sa grille solution / ne retourne rien, car il y a des modifications directes des grilles
    int temp[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            temp[i][j] = T[i][j];
    while (full_tak_8x8(T)) {//utilisation des fonctions précédentes
        do {
            for (int k = 0; k < 8; k++)
                for (int m = 0; m < 8; m++)
                    temp[k][m] = T[k][m];
            row_auto_8x8(T);
            col_auto_8x8(T);
        } while (verif_modif_8x8(temp, T));
        hint_fill_8x8(T, T_solut);
        wait_affiche_8x8(T);
    }
}

void auto_tak_8x8_final(int T[8][8],int T_solut[8][8]) { // utilise les fonctions précédentes pour remplir le tab T / paramètre : T une grille de jeu et T_solut sa grille solution / ne retourne rien, car ce sont des vérifications et des affichages
    int temp[8][8];
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            temp[i][j] = T[i][j];
    while (full_tak_8x8(T)) {//utilisation des fonctions précédentes
        do{
            for(int k = 0; k < 8; k++)
                for(int m = 0; m < 8; m++)
                    temp[k][m] = T[k][m];
            row_auto_8x8(T);
            col_auto_8x8(T);
        }while(verif_modif_8x8(temp, T));
        hint_fill_8x8(T,T_solut);
    }
    print_tak_8x8(T);
}

/*
 * Partie 3 4x4
 */


int tab(int tab[4],int nb){//permet de savoir si un élément est dans un tableau / paramètres : tab un tableau et nb un entier (recherché) / retourne 1 si l'élément est dans le tableau, 0 sinon
    for (int i=0;i<4;i++){
        if (nb==tab[i])
            return 1;
    }
    return 0;
}


void full_row_4x4(int row[4],int tak[4][4],int pos){// remplie une ligne avec un code binaire / paramètres : le code binaire puis la grille ensuite la ligne de la grille / ne retourne rien, car changements en interne
    for (int i =0;i<4;i++){
        tak[pos][i]=row[i];
    }
}

int verif_auto_col_4x4(int T[4][4]){// vérifie si la colonne contient ou non 3 mêmes chiffres / paramètres : T une grille / retourne 0 si c'est bon 0 sinon
    for(int i = 0; i < 4; i++){
        int cpt0 = 0, cpt1 = 0;
        for(int j = 0; j < 4; j++){
            if(T[j][i] == 0)
                cpt0 += 1;
            if(T[j][i] == 1){
                cpt1 += 1;
            }
            if(cpt0 > 2 || cpt1 > 2) {
                return 1;
            }
        }
    }
    return 0;
}

void crt_solut_4x4(int tak[4][4]){// permet de générer une grille solution par l'ordinateur / paramètres : tak une grille / ne retourne rien, car tous les changements se font dans la fonction
    int bank[6][4]= {{0, 0, 1, 1}, {0, 1, 0, 1}, {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};//nombres possibles pour les lignes
    int temp[4]={-1,-1,-1,-1};
    int nb;
    for (int h=0;h<4;h++){
        do{
            do{
                nb=rand()%6;
            }while(tab(temp,nb)==1);
            temp[h]=nb;
            full_row_4x4(bank[nb],tak,h);
        }while(verif_auto_col_4x4(tak));
    }
    print_tak_4x4(tak);
}