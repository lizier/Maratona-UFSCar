// Gabriel Bellon de Carvalho.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char numeros[201];
} Ttelefone;

Ttelefone telefones[100000];

int compara(const void *a, const void *b) {
  Ttelefone telA = * ((Ttelefone*) a);
  Ttelefone telB = * ((Ttelefone*) b);
  
	int comparacao = strcmp(telA.numeros, telB.numeros);

	if (comparacao == 0)
		return 0; // a = b.
	else if (comparacao < 0)
		return 1; // a < b.
	else
		return -1; // a > b.
}

int main() {
  int qtdTelefones, economia;

  while(1) {
    if (scanf("%d", &qtdTelefones) == EOF)
      break;

    economia = 0;

    for (int i = 0; i < qtdTelefones; i++)
      scanf("%s", telefones[i].numeros);

    qsort(telefones, qtdTelefones, sizeof(Ttelefone), compara);
    
    for (int j = 0; j < qtdTelefones - 1; j++) {
      for (int k = 0; telefones[j].numeros[k] != '\0'; k++) {
        if (telefones[j].numeros[k] == telefones[j + 1].numeros[k])
          economia += 1;
        else
          break;
      }
    }

    printf("%d\n", economia);
  }

  return 0;
}