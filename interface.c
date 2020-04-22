#include "interface.h"

int temEspaco(char* line) {
    int i, r=0;

    for(i=0; line[i]!='\0' && r==0; i++)
        if(line[i] == ' ')
            r=1;

    return r;
}

void printa(ESTADO* e){
    int l,c;
    printf("\n  a b c d e f g h\n");
    for (l=0; l<8; l++){
        printf("%d ", 8-l);
        for(c=0; c<8; c++){
            if(e->tab[l][c]==BRANCA) printf("* ");
            else if (e->tab[l][c]==PRETA) printf ("# ");
            else {
                if(l==0 && c==7)
                    printf("2 ");
                else if(l==7 && c==0)
                    printf("1 ");
                else
                    printf(". ");
            }
        } putchar('\n');
    }
}

void menu() {
    printf("\nSelecione a sua opcao:\n");
    printf("coordenada | Efetuar uma jogada, se valida\n");
    printf("ler        | Ler jogo\n");
    printf("gr         | Guardar jogo\n");
    printf("imprime    | Imprime tabuleiro\n");
    printf("movs       | Imprimir movimentos do jogo\n");
    printf("pos        | Visualizar uma posicao anterior\n");
    printf("jog        | Sugestão de jogada\n");
    printf("q          | Sair do jogo\n");
}

int novoJogo() {
    int r=-1;
    char *arr = malloc(sizeof(char) * 10), *aux;

    while(r == -1) {
        printf("\nQuer jogar novamente? Y/N\n");
        fgets(arr, 10, stdin);
        aux = strtok(arr, "\n");

        if(strcmp(aux,"Y")==0)
            r=1;

        else if(strcmp(aux,"N")==0)
            r=0;

        else
            printf("Comando inválido!\n");
    }

    return r;
}

void ganhar(int jogadorAtual){
    printf("\nParabéns jogador %d !! Ganhou o jogo!\n", jogadorAtual);
}

void movimentos( ESTADO *e){
    int i;
    if(getJogadorAtual(e) == 2){
        printf("01: ");
        for(i=0; i<=getNumJogadas(e) ; i++){
            printf ("%s%d ", ('a' + getColuna(jogadaJog1(e, i))), getLinha(jogadaJog1(e, i)));
        }
        putchar("\n");
        printf("02: ");
        for(i=0; i<getNumJogadas(e); i++){
            printf("%s%d ", ('a' + getColuna(jogadaJog2(e,i))) , getLinha(jogadaJog2()));
        }
        putchar("\n");
    }
    else {
        printf("01: ");
        for(i=0; i<getNumJogadas(e) ; i++){
            printf ("%s%d ", ('a' + getColuna(jogadaJog1(e, i))), getLinha(jogadaJog1(e, i)));
        }
        putchar("\n");
        printf("02: ");
        for(i=0; i<getNumJogadas(e); i++){
            printf("%s%d ", ('a' + getColuna(jogadaJog2(e,i))) , getLinha(jogadaJog2()));
        }
        putchar("\n");
    }

}
void interpretador (ESTADO *e){
    int res;
    char* arr = NULL;
    char* aux = NULL;

    COORDENADA *c = malloc(sizeof(COORDENADA));
    arr = malloc(64 *sizeof(char));
    int r=1;

    gameStart(e);
    printa(e);

    while(r) {
        menu();
        printf("Introduza o comando:\n");
        fgets(arr, 64, stdin);

        if(temEspaco(arr))
            aux = strtok(arr, " ");
        else
            aux = strtok(arr, "\n");

        if (strcmp(aux, "coordenada") == 0) {
            aux = strtok(NULL, " ");
            setColuna((aux[0] - 'a'), c);
            aux = strtok(NULL, "\n");
            setLinha(('8' - aux[0]), c);

            res = jogar(e, c);

            if (res == 1)
                printf("Jogada inválida.\n");

            else
                printa(e);

        } else if (strcmp(aux, "ler") == 0) {

        } else if (strcmp(aux, "gr") == 0) {
            aux = strtok(NULL, "\n");

            res = guardar(aux, e);

            if (res == -1)
                printf("Erro ao gravar no ficheiro %s.\n", aux);

            else
                printf("Ficheiro %s gravado com sucesso.\n", aux);

        } else if (strcmp(aux, "movs") == 0) {
            movimentos(e);

        } else if (strcmp(aux, "pos") == 0) {

        } else if (strcmp(aux, "jog") == 0) {

        } else if (strcmp(aux, "q") == 0) {
            r = 0;

            printf("Terminou o jogo.\n");
        } else printf("Comando inválido.\n");

        if((res = ganhou(e)) != 0) {
            ganhar(res);

            if(novoJogo() == 0)
                r=0;

            else {
                gameStart(e);
                printa(e);
            }
        }
    }
}

