#include <iostream>

using namespace std;
// Solução por : rafaelbarbeta
int main () {
    unsigned int tamEstrada;
    string estrada;
    char status; //Recebe o ponto de referência atual, R , D ou Z. Inicializa com um numero indeterminado
    unsigned int minDistancia; //mínima distância. Inicializa com o maior valor possível
    unsigned int contD; //contador para calcular distância
    int i;
    while (1) {
        cin >> tamEstrada;
        if (!tamEstrada)
            break;
        cin >> estrada;

        //Inicializações
        i = 0;
        contD = 0;
        minDistancia = tamEstrada;
        //Procura o primeiro "estabelecimento" para adicionar na variável status
        while (estrada[i] != 'D' && estrada[i] != 'Z' && estrada[i] != 'R') i++; 
        status = estrada[i];
        
        for (int j = i; j < tamEstrada; j++) {
            if (estrada[j] == '.') {
                contD++;
                continue;
            }
            else if (estrada[j] == 'Z') {
                minDistancia = 0;
                break;
            }
            else if (estrada[j] == status) {
                contD = 0;
            }
            else {
                if (++contD < minDistancia)
                    minDistancia = contD;
                contD = 0;
                status = estrada[j];
            }
        }
        cout << minDistancia << "\n";
    }
}