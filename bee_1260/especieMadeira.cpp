#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main () {
    unsigned int casosDeTeste;
    unsigned long long int j;
    string tipoArvore;
    cout << fixed << setprecision(4);
    cin >> casosDeTeste;
    getline(cin,tipoArvore);
    getline(cin,tipoArvore);
    for (int i = 0; i < casosDeTeste; i++) {
        j = 0;
        vector <string> arvores(1000000); //cria um vector que contem todas as arvores dadas na entrada
        while (true) {
            getline(cin,tipoArvore);
            if (tipoArvore == "")
                break;
            arvores[j] = tipoArvore;
            j++;
        }
        bool diferente = false;
        unsigned long long int qtdTipoArvore  = 0; 
        sort(arvores.begin(),(arvores.begin() + j)); //funcao da biblioteca algorithm. Sem argumentos, ordena na ordem alfabetica
        for (int k = 0; k <= j; k++) { //conta quantas arvores com aquele mesmo nome tem no vector arvores
            string arvoreAtual;
            arvoreAtual = arvores[k];
            if (diferente) {
                cout << arvores[k-1] << " ";
                cout << (qtdTipoArvore/(double)j)*100;
                cout << "\n";
                diferente = false;
                qtdTipoArvore = 0;
            }
            qtdTipoArvore++;
            if (arvores[k] != arvores[k+1])
                diferente = true;
        }
        if (i != casosDeTeste - 1)
            cout << "\n";
    }
}