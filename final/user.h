#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef USER_H_
#define USER_H_

struct Usuario retornaUsuario();
void criaUsuario(FILE *p, struct Usuario* u);
void atualizarUser(float r, struct Usuario* u, FILE* p_user);

#endif