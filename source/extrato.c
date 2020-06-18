#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../include/extrato.h"

void Extrato(FILE* file){
  char buf[BUFSIZ];

  puts("Extrato Bancario");
  while(fgets(buf, BUFSIZ, file) != NULL) 
  {
      printf("%s", buf) ;
  }
  puts("=================================");

  fclose(file);
}