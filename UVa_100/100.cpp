//Anathna Telles Pereira
#include <iostream>
using namespace std;

int main(){
    int i, j, result;

    while (scanf("%d %d", &i, &j) != EOF) {
        int temp;
        int tempi = i;
        int tempj = j;
        
        if(i>j){// troca os valores caso i > j
            temp = i;
            i = j;
            j = temp;
        }

        int cicloAtual;
        int maiorCiclo = 0;

        while(i<=j){ // loop por todo o intervalo dado
            int n=i;
            cicloAtual = 1;

            while (n!=1)// calcula o tamanho do ciclo relativo ao atual n
            {
                if(n%2 == 1) n=3*n+1;
                else n = n/2;

                cicloAtual++;
            }

            if(cicloAtual > maiorCiclo)
                maiorCiclo = cicloAtual; // caso ciclo atual for o maior, atualiza o maiorCiclo
            
            i++;
        }

        printf("%d %d %d\n", tempi, tempj, maiorCiclo);
    }
    return 0;
}