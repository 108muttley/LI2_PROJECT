#ifndef PROJETO_INTERFACE_H
#define PROJETO_INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "files.h"
#include "dados.h"
#include "logicadoprograma.h"

void printa(ESTADO* e);
void menu();
void interpretador (ESTADO *e);
void ganhar (int jogadorAtual);
void jogInvalida ();

#endif
