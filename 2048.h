#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mover(char, int MatJogo[][4]);
void configurar();
void inicializa_tabuleiro(int Mat[][4]);
void printa_matriz(int MatJogo[][4]);
int jogar(int MatJogo[][4]);
int menu_principal();
int random_2_4();
char ler_movimento();
void move_cima(int MatJogo[][4]);
int tiver_algo_na_posicao(int MatJogo[][4], int*);
int esta_cheio(int MatJogo[][4]);
void calcula_random_index(int*);
void move_esquerda(int MatJogo[][4]);
void move_direita(int MatJogo[][4]);
void move_baixo(int MatJogo[][4]);
