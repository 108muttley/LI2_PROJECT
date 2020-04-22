#include "dados.h"

void gameStart (ESTADO *e){
    int l , c;
    for(l=0; l<8; l++){
        for(c=0; c<8; c++){
            e->tab[l][c]= VAZIO;
        }
    }
    e->tab[3][4]= BRANCA;
    e->ultima_jogada.coluna = 4;
    e->ultima_jogada.linha= 3;
    e->num_jogadas=0;
    e->jogador_atual =1;

}

int getLinha (COORDENADA *c){
    return c->linha;
}

int getColuna (COORDENADA *c){
    return c->coluna;
}

int isEmpty (COORDENADA *c , ESTADO *e){
    if (e->tab[getLinha (c)] [getColuna(c)] == VAZIO) return 1;
    else return 0;
}

void setPreta(ESTADO *e , COORDENADA *c){
    e->tab[getLinha(c)][getColuna(c)] = PRETA;
}
void setBranca (ESTADO *e , COORDENADA *c){
    e->tab[getLinha(c)][getColuna(c)] = BRANCA;
}

void setColuna (int coluna, COORDENADA *c){
    c->coluna = coluna;
}

void setLinha(int linha , COORDENADA *c){
    c->linha = linha;
}

void ultimaPosicao (ESTADO *e, COORDENADA *c){
    *c = e->ultima_jogada;
}

void addNumJogadas (ESTADO *e){
    e->num_jogadas +=1;
}
void atualizaUltJogada (ESTADO *e, COORDENADA *c){
    e->ultima_jogada = *c;
}

void atualizaJogador (ESTADO *e){
    if (e->jogador_atual == 1) e->jogador_atual = 2;
    else e->jogador_atual = 1;
}

int getJogadorAtual (ESTADO *e){
    int r = e->jogador_atual;
    return r;
}

int getUltimaLinha (ESTADO *e) {
    return e->ultima_jogada.linha;
}

int getUltimaColuna (ESTADO *e) {
    return e->ultima_jogada.coluna;
}

int isBranca (int l,int c, ESTADO *e){
    if(e->tab[l][c] == BRANCA) return 1;
    else return 0;
}
int isPreta (int l, int c, ESTADO *e){
    if(e->tab[l][c]== PRETA) return 1;
    else return 0;
}
void intJogada1 (ESTADO *e, COORDENADA *c){
    e->jogadas[e->num_jogadas-1].jogador1 = c;
}
void intJogada2 (ESTADO *e, COORDENADA *c){
    e->jogadas[e->num_jogadas-1].jogador2 = c;
    addNumJogadas(e);
}
COORDENADA jogadaJog1 (ESTADO *e, int ind){
    return e->jogadas[ind].jogador1;
}

COORDENADA jogadaJog2 (ESTADO *e, int ind){
    return e->jogadas[ind].jogador2;
}

COORDENADA* inicializaCoordenada() {
    COORDENADA* new;

    new = malloc(sizeof(COORDENADA));

    return new;
}
int getNumJogadas ( ESTADO *e){
    return e->num_jogadas;
}
ESTADO* inicializaEstado() {
    ESTADO* new;

    new = malloc(sizeof(ESTADO));

    return new;
}