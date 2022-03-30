// Gabriel Bellon de Carvalho.

#include <iostream>
#include <stack>

using namespace std;

int main() {
  int qtdVagoes, vagoes[1000], iVagoes;

  while(1) {
    scanf("%d", &qtdVagoes);

    if (qtdVagoes == 0)
      break;

    while(1) {
      for (int i = 0; i < qtdVagoes; i++) {
        scanf("%d", &vagoes[i]);

        if (vagoes[i] == 0)
          break;
      }

      if (vagoes[0] == 0)
        break;

      stack<int> estacao;
      iVagoes = 0;

      for (int i = 0; i < qtdVagoes; i++) {
        estacao.push(i + 1);

        while (estacao.size() > 0 && vagoes[iVagoes] == estacao.top()) {
          estacao.pop();
          iVagoes += 1;
        }
      }

      if (iVagoes == qtdVagoes)
        printf("Yes\n");
      else
        printf("No\n");
    }

    printf("\n");
  }

  return 0;
}