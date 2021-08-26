#include <stdio.h>
#include <stdlib.h>
char review[12000];

//Função separa_review pega a ultima linha lida do arquivo .csv e separa somente o review
//armazenando o mesmo na variavel global review até que a função seja chamada novamente
//Todos as linhas do .csv tem a mesma formatação: "review",rating
//então temos que pegar todos os caracteres da posição i = 1 até a posição da quebra de linha
// ou do fim do vetor(\0) que é n-3
void separa_review(char v[]){
  int ultimo;
  for (int i = 0; v[i]!= '\0' && v[i]!= '\n'; i++)
    ultimo = i;
  ultimo-=3;
  for(int j = 0; j < ultimo; j++)
    review[j] = v[j+1];
  review[ultimo] = '\0';
}

//A função retorna_rating percorre a linha até o ultimo caractere da linha e o retorna
//Como visto antes o ultimo caractere de cada linha sera o rating
char retorna_rating(char v[]){
  int ultimo;
  for (int i = 0; v[i]!= '\0' && v[i]!= '\n'; i++)
    ultimo = i;
  return v[ultimo];
}


int main(){
  FILE *arq = fopen("tripadvisor_hotel_reviews.csv", "r");
  FILE *file1 = fopen("Nota1.txt", "w+");
  FILE *file2 = fopen("Nota2.txt", "w+");
  FILE *file3 = fopen("Nota3.txt", "w+");
  FILE *file4 = fopen("Nota4.txt", "w+");
  FILE *file5 = fopen("Nota5.txt", "w+");

  if (arq == NULL)
  {
    printf("Arquivo não encontrado!\n");
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