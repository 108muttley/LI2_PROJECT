#include "logicadoprograma.h"

int isCoordenadaVal (COORDENADA *ci , COORDENADA *cf){
    int colI = getColuna(ci), colF = getColuna(cf), linhaI = getLinha(ci), linhaF = getLinha(cf);
    if((linhaI == linhaF && (colF == colI + 1 || colF == colI - 1))||
       (colI == colF && (linhaF == linhaI + 1 || linhaF == linhaI - 1))||
       (linhaF == linhaI + 1 && (colF == colI - 1 || colF == colI + 1))||
       (linhaF == linhaI - 1 && (colF == colI - 1 || colF == colI + 1)))
        return 1;
    else return 0;
}


int jogadaValida(ESTADO *e, COORDENADA *c){
    COORDENADA *c2 = malloc(sizeof(COORDENADA));
    int r = -1;
    ultimaPosicao(e,c2);
    if((getLinha(c) <0|| getLinha(c)>7) || (getColuna(c)<0 || getColuna(c)>7 ))
        r = 0;

    else if( isEmpty(c,e) && isCoordenadaVal(c2 , c))
        r = 1;

    else
        r = 0;

    return r;
}

int jogar(ESTADO *e , COORDENADA *c) {
    COORDENADA *c2 = malloc(sizeof(COORDENADA));
    ultimaPosicao(e,c2);

    if (jogadaValida(e, c) == 0)
        return 1;

    else {
        setPreta(e , c2);
        setBranca(e , c);
        if (getJogadorAtual(e) == 1){
            intJogada1(e, c);
        }
        else
            intJogada2(e,c);
        atualizaJogador(e);
        atualizaUltJogada(e , c);
        return 0;
    }
}

int ganhou (ESTADO *e){
    COORDENADA* c1 = inicializaCoordenada();
    int line = getUltimaLinha(e), col = getUltimaColuna(e);
    int i = line-1, j = col-1;

    if (line == 0 && col == 7)
        return 2;

    else if((line == 7 && col==0))
        return 1;

    else {
        if(col==0)
            j = 0;

        if(line==0)
            i = 0;

        for( ; j<col+2 && j<8 ; j++){
            for( ; i<line+2 && i<8 ; i++){
                setLinha(i, c1);
                setColuna(j, c1);
                if(isEmpty(c1 , e))
                    return 0;
            }
        }
    }

    if(getJogadorAtual(e)==1)
        return 2;

    else
        return 1;
}