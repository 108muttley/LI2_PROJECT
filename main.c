#include "dados.h"
#include "interface.h"

int main() {
    ESTADO* e= inicializaEstado();

    interpretador(e);

    return 0;
}
