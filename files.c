#include "files.h"

int guardar(char* nome, ESTADO *e){
    int i, j;

    FILE *f = fopen(nome , "w");

    if (f == NULL)
        return -1;

    for (i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(i==0 && j==7) fprintf(f,"2");
            else if(i==7 && j==0) fprintf(f,"1");
            else if(isBranca(i,j,e)) fprintf(f,"*");
            else if (isPreta(i,j,e)) fprintf (f,"#");
            else fprintf(f,". ");
        } fprintf(f, "\n");
    }

    fclose(f);

    return 0;
}