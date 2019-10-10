#include <stdio.h> 
#include <stdlib.h> // For exit() 


int main() 
{ 
    FILE *fptr;
    FILE *file2; 
  
    char v[1000000], c; 
    int cont=1, index=0;
  
    fptr = fopen("projeto.txt", "r"); 
    file2 = fopen("Projeto_Temp.txt", "w");
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(fptr); 
    while (1) 
    { 
      if(c == '\n')cont++;
      else if(cont == 2){
        c = ' ';
      }


      printf ("%c", c); 
      c = fgetc(fptr); 

      
      v[index++] = c;
      

      if(c == EOF){
        break;
      }

    } 
  
  printf("\nCont: %d\n", cont);

  printf("Vetor: %s\n", v);
    fclose(fptr); 
    return 0; 
}
