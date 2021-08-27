#include <stdio.h>
#include <stdlib.h>
#include "tratamento_rating.h"

int main(){
  FILE *arq = fopen("tripadvisor_hotel_reviews.csv", "r");
  FILE *file1 = fopen("Nota1.txt", "w+");
  FILE *file2 = fopen("Nota2.txt", "w+");
  FILE *file3 = fopen("Nota3.txt", "w+");
  FILE *file4 = fopen("Nota4.txt", "w+");
  FILE *file5 = fopen("Nota5.txt", "w+");

  if (arq == NULL)
  {
    printf("Arquivo tripadvisor_hotel_reviews.csv não encontrado!\n");
    return 0;
  }

  char linha[12000], rating;
  int i = 0;

  while (fgets(linha, sizeof(linha), arq))
  {
    if(i!=0)
    separa_review(linha);
    rating = retorna_rating(linha);
    printf("Linha: %d\n", i);
 
    //vetor review esta incluso na biblioteca tratamento_rating.h

    if(rating == '1')
      fputs(review, file1);
    if(rating == '2')
      fputs(review, file2);
    if(rating == '3')
      fputs(review, file3);
    if(rating == '4')
      fputs(review, file4);
    if(rating == '5')
      fputs(review, file5);
    
    i++;
  }

  fclose(arq);
  fclose(file1);
  fclose(file2);
  fclose(file3);
  fclose(file4);
  fclose(file5);
  return 0;
}