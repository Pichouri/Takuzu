#include "func_trans.h"
/*
 * Projet : Takuzu réalisé par Marc ROUGAGNOU et Gaël RAIMBAULT
 * Ce fichier est le "main" cela veut dire que c'est le fichier principal.
 * C'est là où le programme commence et se termine
 */
int main() {
    srand(time(NULL));
    int mode;
    do {
        printf("\nMenu principale :\n");
        printf("1 - Resoudre une grille\n2 - Resoudre automatiquement une grille\n3 - Generer une grille\n4 - Creer son mask et jouer dessus\n0 - Quitter\n");
        scanf("%d", &mode);
        switch (mode) {//choix de la catégorie
            case 1: {
                int size;
                printf("\nMenu Resoudre une grille :\n");
                printf("Choisissez la taille du Takuzu :\n1 - 4x4\n2 - 8x8\n");
                scanf("%d", &size);
                switch (size) {//choix de la catégorie
                    case 1: {
                        int vie = 3, tak[4][4], mask[4][4], tak_solu[4][4]; // I
                        solution_4x4(tak_solu);
                        mask_4x4(mask);
                        tak_play_4x4(tak, mask, tak_solu);
                        print_tak_4x4(tak);
                        while (vie != 0 && full_tak_4x4(tak) != 0) {
                            if (placement_4x4(tak, tak_solu) == 1)
                                --vie;
                            printf("Il vous reste %d vies\n", vie);
                        }
                        break;
                    }
                    case 2: {
                        int vie = 3, tak[8][8], mask[8][8], tak_solu[8][8];
                        solution_8x8(tak_solu);
                        mask_8x8(mask);
                        tak_play_8x8(tak, mask, tak_solu);
                        print_tak_8x8(tak);
                        while (vie != 0 && full_tak_8x8(tak) != 0) {
                            if (placement_8x8(tak, tak_solu) == 1)
                                --vie;
                            printf("Il vous reste %d vies\n", vie);
                        }
                        break;
                    }
                }
                break;
            }
            case 2: {
                int size;
                printf("\nMenu Resoudre une grille automatiquement:\n");
                printf("Choisissez la taille du Takuzu :\n1 - 4x4\n2 - 8x8\n");
                scanf("%d", &size);
                switch (size) {//choix de la catégorie
                    case 1: {
                        int tak[4][4], mask[4][4], tak_solu[4][4];
                        solution_4x4(tak_solu);
                        mask_4x4(mask);
                        tak_play_4x4(tak, mask, tak_solu);
                        print_tak_4x4(tak);
                        auto_tak_4x4(tak, tak_solu);
                        break;
                    }
                    case 2: {
                        int tak[8][8], mask[8][8], tak_solu[8][8];
                        solution_8x8(tak_solu);
                        mask_8x8(mask);
                        tak_play_8x8(tak, mask, tak_solu);
                        print_tak_8x8(tak);
                        auto_tak_8x8(tak, tak_solu);
                        break;
                    }
                }
                break;
            }
            case 3: {
                int size;
                printf("\nMenu Generer une grille:\n");
                printf("Choisissez la taille du Takuzu :\n1 - 4x4\n");
                scanf("%d", &size);
                switch (size) {//choix de la catégorie
                    case 1: {
                        int tak[4][4];
                        for (int i =0;i<4;i++){
                            for (int j=0;j<4;j++){
                                tak[i][j]=-1;
                            }
                        }
                        crt_solut_4x4(tak);
                        break;
                    }
                }
                break;
            }
            case 4: {
                int size;
                printf("\nMenu Generer un mask:\n");
                printf("Choisissez la taille du Takuzu :\n1 - 4x4\n2 - 8x8\n");
                scanf("%d", &size);
                switch (size) {//choix de la catégorie
                    case 1:{
                        int vie = 3, tak[4][4], mask[4][4]={0}, tak_solu[4][4];
                        solution_4x4(tak_solu);
                        crt_mask_4x4(mask);
                        tak_play_4x4(tak, mask, tak_solu);
                        print_tak_4x4(tak);
                        while (vie != 0 && full_tak_4x4(tak) != 0) {
                            if (placement_4x4(tak, tak_solu) == 1)
                                --vie;
                            printf("Il vous reste %d vies\n", vie);
                        }
                        break;
                    }
                    case 2:{
                        int vie = 3, tak[8][8], mask[8][8]={0}, tak_solu[8][8];
                        solution_8x8(tak_solu);
                        crt_mask_8x8(mask);
                        tak_play_8x8(tak, mask, tak_solu);
                        print_tak_8x8(tak);
                        while (vie != 0 && full_tak_8x8(tak) != 0) {
                            if (placement_8x8(tak, tak_solu) == 1)
                                --vie;
                            printf("Il vous reste %d vies\n", vie);
                        }
                        break;
                    }
                }
                break;
            }
        }
    } while (mode != 0);
    return 0;
}