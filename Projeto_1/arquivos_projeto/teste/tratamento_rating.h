#ifndef TRATAMENTO_RATING_H
#define TRATAMENTO_RATING_H

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

#endif
