#include "2048.h"

int main(){
    int tabuleiro[4][4];
    int escolha;
    int fimdepartida;
    srand(time(NULL));
    inicializa_tabuleiro(tabuleiro);

    escolha = menu_principal(); 
    
    switch (escolha){
        case 1:
            do
               fimdepartida = jogar(tabuleiro);
            while(fimdepartida);
        case 2:
            configurar();
        case 3:
            exit (1);
        default:
            printf("Escolha uma opção possível\n");
    }


    return 0;
}

void inicializa_tabuleiro(int Mat[][4]){
    int i, j;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            Mat[i][j] = 0;
        }
    }
    //preenchimento ok
}

int menu_principal(){
    int escolha;

    system("clear");
    printf("Olá, bem vindo ao 2048!\n");
    printf("Escolha uma das opções abaixo\n");
    printf("1- jogar\n");
    printf("2- configurar\n");
    printf("3- Sair\n");
    scanf("%d", &escolha);
    getchar();
    return escolha;
    //scanf ok!
}

int jogar(int MatJogo[][4]){
    int novonumero;
    int randomindex[2];
    char movimento;

    novonumero = random_2_4();
    do{
        calcula_random_index(randomindex);
    }while(!esta_cheio(MatJogo) && tiver_algo_na_posicao(MatJogo, randomindex));
    
    MatJogo[randomindex[0]][randomindex[1]] = novonumero;
    
    printa_matriz(MatJogo);

    movimento = ler_movimento();
    mover(movimento, MatJogo);

    return 1;
}

void printa_matriz(int MatJogo[][4]){
    int i, j;

    system("clear");

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            printf("%d ", MatJogo[i][j]);
        }
        printf("\n");
    }
    //ok!
}

void configurar(){

}

int random_2_4(){
    int vetor_2_4[8] = {2,2,2,2,4,2,2,2};
    int randomindex;

    randomindex = rand() % 8;
    return vetor_2_4[randomindex];
    //ok;
}

char ler_movimento(){
    char movimento_escolhido;
    printf("Digite o movimento desejado\n");
    printf("São permitidos \"A,S,W,D\"\n");
    printf(">> ");
    scanf("%c", &movimento_escolhido);
    getchar();
    return movimento_escolhido;
    //ok;
}

void mover(char movimento_escolhido, int MatJogo[][4]){

    switch(movimento_escolhido){
        case 'w': case 'W':
            move_cima(MatJogo);
    }
}

void move_cima(int MatJogo[][4]){
    int i, j, searcher;

    for (j = 0; j < 4; ++j)
    {
        for (i = 0; i < 4; ++i)
        {
            if (MatJogo[i][j]==0)
            {
                for (searcher = i; searcher < 4; ++searcher)
                {
                    if (MatJogo[searcher][j] > 0){
                        MatJogo[i][j] = MatJogo[searcher][j];
                        MatJogo[searcher][j] = 0;
                    }
                }
                printf("To na posição (i,j) (%d, %d)\n", i,j);
            }      
            if (MatJogo[i][j] == MatJogo[i+1][j])   
            {
                MatJogo[i][j] += MatJogo[i+1][j];
                MatJogo[i+1][j] = 0;
            }        
        }
    }
}

void calcula_random_index(int* coordenada){
    coordenada[0] = rand() % 4;
    coordenada[1] = rand() % 4;
}

int esta_cheio(int MatJogo[][4]){
    int i, j, esta_cheio=1;
    
    for ( i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if(MatJogo[i][j]==0)
                esta_cheio = 0;
        }
    }
    return esta_cheio;
}
int tiver_algo_na_posicao(int MatJogo[][4], int* randomindex){
    if (MatJogo[randomindex[0]][randomindex[1]] != 0)
        return 1;
    else return 0;
}