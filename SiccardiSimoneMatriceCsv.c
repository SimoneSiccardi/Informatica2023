#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

int generaMatrice(int mat[DIM][DIM]){
  int dim;

  do{
    printf("inserire la dimensione della matrice: ");
    scanf("%d", &dim);
    
  }while(dim < 0 || dim > DIM);

  for(int i = 0; i < dim; i++){
    
    for(int j = 0; j < dim; j++){
      mat[i][j] = (rand() % 30) + 1;
    }
  }

  return dim;
}

FILE* apriFile(FILE* fp){
 fp = fopen("matrice.csv", "w");

  if(fp == NULL)
  {
    printf("\nerrore nell'apertura del file");
  }

  return fp;
}

void scriviSuFile(FILE* fp, int mat[][DIM], int dim){
  for(int i = 0; i < dim; i++){
    fprintf(fp, "\n");
    
    for(int j = 0; j < dim; j++){
      
      if(j == dim - 1){
        fprintf(fp, "%d", mat[i][j]);
      }
      else
      {
        fprintf(fp, "%d, ", mat[i][j]);
      }
    }
  }
}

int main(void) {
  
  int mat[DIM][DIM], scelta, dim;;
  FILE *fp;

  srand(time(NULL));

  do{
    printf("inserire il numero dell'opzione(1, 2): ");
    scanf("%d", &scelta);
    
    switch(scelta){
      case 1: 
        dim = generaMatrice(mat);
      break;
      case 2:
        apriFile(fp);
        scriviSuFile(fp, mat, dim);
      break; 
    } 
  }while(scelta != 0);
  
  
}