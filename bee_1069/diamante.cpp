#include <iostream>
#include <stack>

using namespace std;

int main () {
   int qtdTestes;
   cin >> qtdTestes;
   while ((getchar()) != '\n');
   for (int i = 0; i < qtdTestes; i++) {
       stack<char> diamante;
       int qtdDiamantes;
       qtdDiamantes = 0;
       string campoMineracao; //string que contem "os diamantes e areia da mina"
       getline(cin,campoMineracao);
       for (auto i = campoMineracao.begin(); i != campoMineracao.end(); i++) {
            if (*i == '<') { //adiciona na stack se for um sinal menor que
                diamante.push(*i);
            }
            else if (*i == '>' && !diamante.empty()) { //remove da stack se for um sinal maior que
                diamante.pop();
                qtdDiamantes++;
            }
       }
       cout << qtdDiamantes << "\n";
   }
}