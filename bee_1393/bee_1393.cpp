// Gabriel Bellon de Carvalho.

#include <iostream>

int main() {
  int qtdLajotas, caminhos[41];

  while(1) {
    scanf("%d", &qtdLajotas);

    if (qtdLajotas == 0)
      break;

    for (int i = 0; i <= qtdLajotas; i++) {
      if (i == 0 || i == 1)
        caminhos[i] = 1;
      else
        caminhos[i] = caminhos[i - 1] + caminhos[i - 2];
    }
    
    printf("%d\n", caminhos[qtdLajotas]);
  }
  
  return 0;
}