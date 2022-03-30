#include <iostream>
#include <vector>

using namespace std;
 
 int main () {
     unsigned int testes, maior = 0;
     cin >> testes;
     vector<int> casos(testes);
     for (unsigned long int i = 0; i < testes; i++) {
         //lê todas as entradas e armazena os valores no vector casos.
         //Ao mesmo tempo, procura-se o qual é o maior valor para as proximas etapas
        cin >> casos[i];
        if (casos[i] > maior)
            maior = casos[i];
     }
     // basta alocar a um vector com tamanho igual ao maior termo da serie e guardar os resultados nele
     vector<unsigned long long int> fib(maior+1); 
     fib[0] = 0;
     fib[1] = 1;
     //Implementa-se um loop que "constroi" o vetor ao longo da execução do código
     for (unsigned long int i = 2; i < (maior+1); i++) 
         fib[i] = fib[i-1] + fib[i-2];
     //os indices do vetor fib sao iguais aos valores dos termos da sequencia
     for (unsigned long int i = 0; i < testes; i++) {
         printf("Fib(%u) = %llu\n",casos[i],fib[casos[i]]);
     }
     cout << "\n";
 }
