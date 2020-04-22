#ifndef PROJETO_DADOS_H
#define PROJETO_DADOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

void gameStart (ESTADO *e);
int getLinha (COORDENADA *c);
int getColuna (COORDENADA *c);
int isEmpty (COORDENADA *c , ESTADO *e);
void setPreta (ESTADO *e , COORDENADA *c);
void setBranca (ESTADO *e , COORDENADA *c);
int isCoordenadaVal (COORDENADA *ci , COORDENADA *cf);
void ultimaPosicao (ESTADO *e , COORDENADA *c);
void addNumJogadas (ESTADO *e);
void atualizaUltJogada (ESTADO *e , COORDENADA *c);
void atualizaJogador (ESTADO *e);
int getJogadorAtual (ESTADO *e);
int getUltimaLinha (ESTADO *e);
int getUltimaColuna (ESTADO *e);
void setColuna (int coluna, COORDENADA *c);
void setLinha (int linha, COORDENADA *c);
int isBranca (int l,int c, ESTADO *e);
int isPreta (int l,int c, ESTADO *e);
COORDENADA* inicializaCoordenada();
ESTADO* inicializaEstado();
void intJogada1 (ESTADO *e, COORDENADA *c);
void intJogada2 (ESTADO *e, COORDENADA *c);
int getNumJogadas ( ESTADO *e);
COORDENADA jogadaJog1 (ESTADO *e, int ind);
COORDENADA jogadaJog2 (ESTADO *e, int ind);
#endif //PROJETO_DADOS_H