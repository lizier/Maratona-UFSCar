// Gabriel Bellon de Carvalho.

#include <iostream>

using namespace std;

int main() {
  int nAbas, abas[1001] = {0}, qtdPastas, pasta;
  char possivel = 'S';

  scanf("%d %d", &nAbas, &qtdPastas);

  for (int i = 0; i < qtdPastas; i++) {
    scanf("%d", &pasta);

    abas[pasta] += 1;
  }

  for (int i = 1; i < nAbas; i++) {
    if (i == 1) {
      if (abas[i] < abas[nAbas] || abas[i] > abas[nAbas] + 1) {
        possivel = 'N';
        break;
      }
    }
    else if (abas[i] < abas[i + 1] || abas[i] > abas[i - 1] + 1) {
      possivel = 'N';
      break;
    }
  }

  printf("%c\n", possivel);

  return 0;
}