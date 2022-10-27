#include <stdio.h>
#include "stdlib.h"
#include <time.h>
#include <unistd.h>

#ifndef TRANSVERSE_FUNC_TRANS_H
#define TRANSVERSE_FUNC_TRANS_H
/*
 * Projet : Takuzu réalisé par Marc ROUGAGNOU et Gaël RAIMBAULT
 * Ce fichier est le fichier .h du fichier des fonctions, c'est donc là où on a les prototypes des fonctions.
 */

/* partie 4x4 */
void print_tak_4x4(int T[4][4]);//fonctionne
int transform_4x4(char cas[]);//fonctionne
int placement_4x4(int T[4][4], int T_solut[4][4]);//fonctionne
void solution_4x4(int T[4][4]); // fonctionne
void mask_4x4(int mask[4][4]); // fonctionne
void tak_play_4x4(int tak_jeu[4][4], int mask[4][4], int tak_solu[4][4]);//fonctionne
int full_tak_4x4(int tak[4][4]);//fonctionne
void auto_tak_4x4(int T[4][4], int T_solut[4][4]);//fonctionne
void auto_tak_4x4_final(int T[4][4],int T_solut[4][4]);//fonctionne
void crt_mask_4x4(int mask[4][4]);//fonctionne
void crt_solut_4x4(int tak[4][4]);

/* partie 8x8 */
void print_tak_8x8(int T[8][8]); // fonctionne
int transform_8x8(char cas[]); // fonctionne
int placement_8x8(int T[8][8], int T_solut[8][8]); // fonctionne
void solution_8x8(int T[8][8]); // fonctionne
void mask_8x8(int mask[8][8]); // fonctionne
void tak_play_8x8(int tak_jeu[8][8], int mask[8][8], int tak_solu[8][8]); // fonctionne
int full_tak_8x8(int tak[8][8]); // fonctionne
void auto_tak_8x8(int T[8][8],int T_solut[8][8]);//fonctionne
void auto_tak_8x8_final(int T[8][8],int T_solut[8][8]);//fonctionne
void crt_mask_8x8(int mask[8][8]);//fonctionne

#endif //TRANSVERSE_FUNC_TRANS_H