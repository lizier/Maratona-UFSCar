// Gabriel Bellon de Carvalho.

#include <iostream>

using namespace std;

#define MAX 24

void swap(int vetor[], int i1, int i2) {
  int aux;

  aux = vetor[i1];
  vetor[i1] = vetor[i2];
  vetor[i2] = aux;
}

int main() {
  int qtdCompetidores, oLargada[MAX], oChegada[MAX], qtdPass;

  while (1) {
    if (scanf("%d", &qtdCompetidores) == EOF)
      break;

    qtdPass = 0;

    for (int i = 0; i < qtdCompetidores; i++)
      scanf("%d", &oLargada[i]);

    for (int i = 0; i < qtdCompetidores; i++)
      scanf("%d", &oChegada[i]);

    for (int i = 0; i < qtdCompetidores; i++) {
      for (int j = 0; j < qtdCompetidores; j++) {
        if (oLargada[i] == oChegada[j] && j < i) {

          qtdPass += i - j;
          
          for (int k = 0; k < i - j; k++)
            swap(oLargada, i - k, i - 1 - k);

          i = 0;
            
          break;
        }
      }
    }
    
    printf("%d\n", qtdPass);
  }
  
  return 0;
}