#include "2048.h"

int main(){
    int tabuleiro[4][4];
    int escolha;
    int fimdepartida;
    srand(time(NULL));
    inicializa_tabuleiro(tabuleiro);

    do{
        escolha = menu_principal(); 
        
        switch (escolha){
            case 1:
                do
                   fimdepartida = jogar(tabuleiro);
                while(fimdepartida);
                break;
            case 2:
                configurar();
                break;
            case 3:
                printf("Até mais\n");
                exit (1);
                break;
            default:
                printf("Escolha uma opção possível\n");
                break;
        }
    }while(escolha != 3);


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
    int esta_cheio_;
    char movimento;

    esta_cheio_ = esta_cheio(MatJogo);
    
    if (esta_cheio_)
    {
        printf("Que pena, você nao conseguiu\n");
        getchar();
        return 0;
    }

    novonumero = random_2_4();
    do{
        calcula_random_index(randomindex);
    }while(tiver_algo_na_posicao(MatJogo, randomindex));
    
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
            printf("%d ", MatJogo[i][j]);
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
            break;
        case 'd': case 'D':
            move_direita(MatJogo);
            break;
        case 'a': case 'A':
            move_esquerda(MatJogo);
            break;
        case 's': case 'S':
            move_baixo(MatJogo);
            break;
    }
}

void move_cima(int MatJogo[][4]){
    int i, j, searcher;
    int movi = 0;
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
                        movi = 1;
                    }
                    else
                        movi = 0;
                }
            }  
            if (MatJogo[i][j] == MatJogo[i+1][j])   
            {
                MatJogo[i][j] += MatJogo[i+1][j];
                MatJogo[i+1][j] = 0;
            }
            if (movi)
            {
                if (MatJogo[i][j] == MatJogo[i-1][j])   
                {
                    MatJogo[i-1][j] += MatJogo[i][j];
                    MatJogo[i][j] = 0;
                } 
            }      
        }
    }
}

void move_baixo(int MatJogo[][4]){
    int i, j, searcher;
    int movi = 0;
    for (j = 0; j < 4; ++j)
    {
        for (i = 3; i >= 0; --i)
        {
            if (MatJogo[i][j]==0)
            {
                for (searcher = i; searcher >= 0; --searcher)
                {
                    if (MatJogo[searcher][j] > 0){
                        MatJogo[i][j] = MatJogo[searcher][j];
                        MatJogo[searcher][j] = 0;
                        movi = 1;
                    }
                    else
                        movi = 0;
                }
            }  
            if (MatJogo[i][j] == MatJogo[i-1][j])   
            {
                MatJogo[i][j] += MatJogo[i-1][j];
                MatJogo[i-1][j] = 0;
            }
            if (movi)
            {
                if (MatJogo[i][j] == MatJogo[i+1][j])   
                {
                    MatJogo[i+1][j] += MatJogo[i][j];
                    MatJogo[i][j] = 0;
                } 
            }      
        }
    }
}
void move_direita(int MatJogo[][4]){
    int i, j, searcher;
    int movi = 0;
    for (i = 0; i < 4; ++i)
    {
        for (j = 3; j >= 0; --j)
        {
            if (MatJogo[i][j]==0)
            {
                for (searcher = j; searcher >= 0; --searcher)
                {
                    if (MatJogo[i][searcher] > 0){
                        MatJogo[i][j] = MatJogo[i][searcher];
                        MatJogo[i][searcher] = 0;
                        movi = 1;
                    }
                    else
                        movi = 0;
                }
            }      
            if (MatJogo[i][j] == MatJogo[i][j-1])   
            {
                MatJogo[i][j] += MatJogo[i][j-1];
                MatJogo[i][j-1] = 0;
            }  
            if (movi)
            {
                if (MatJogo[i][j] == MatJogo[i][j+1])   
                {
                    MatJogo[i][j+1] += MatJogo[i][j];
                    MatJogo[i][j] = 0;
                } 
            }   
        }
    }
}

void move_esquerda(int MatJogo[][4]){
    int i, j, searcher;
    int movi = 0;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (MatJogo[i][j]==0)
            {
                for (searcher = j; searcher < 4; ++searcher)
                {
                    if (MatJogo[i][searcher] > 0){
                        MatJogo[i][j] = MatJogo[i][searcher];
                        MatJogo[i][searcher] = 0;
                        movi = 1;
                    }
                    else 
                        movi = 0;
                }
            }      
            if (MatJogo[i][j] == MatJogo[i][j+1])   
            {
                MatJogo[i][j] += MatJogo[i][j+1];
                MatJogo[i][j+1] = 0;
            }   
            if (movi)
            {
                if (MatJogo[i][j] == MatJogo[i][j-1])   
                {
                    MatJogo[i][j-1] += MatJogo[i][j];
                    MatJogo[i][j] = 0;
                }   
            }     
        }
    }
}
void calcula_random_index(int* coordenada){
    coordenada[0] = rand() % 4;
    coordenada[1] = rand() % 4;
}

int esta_cheio(int MatJogo[][4]){
    int i, j;
    
    for ( i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if(MatJogo[i][j]==0)
                return 0;
        }
    }
    return 1;
}
int tiver_algo_na_posicao(int MatJogo[][4], int* randomindex){
    if (MatJogo[randomindex[0]][randomindex[1]] != 0)
        return 1;
    else return 0;
}