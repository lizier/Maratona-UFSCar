#include <iostream>
#include <stack>

using namespace std;

void atualizarEst(stack<int> *hSaida,int hAtual,int *qtdAtualCarros,int *possivel);
void limpaStack(stack<int> *hSaida);
bool verificarSaidas(stack<int> *hSaida);

int main () {
    int qtdEntradas;
    int hAtual, nMaxVagas;
    int possivel;
    int qtdAtualCarros;
    stack<int> hSaida;

    while (1) {
        hAtual = 0;
        nMaxVagas = 0;
        qtdAtualCarros = 0;
        possivel = 1;
        cin >> qtdEntradas;
        cin >> nMaxVagas;
        if (!(qtdEntradas && nMaxVagas)) //fim das entradas
            break;
        for (int i = 0; i < qtdEntradas;i++) {
            int proxhSaida;
            cin >> hAtual;
            atualizarEst(&hSaida,hAtual,&qtdAtualCarros,&possivel);
            cin >> proxhSaida;
            hSaida.push(proxhSaida);
            qtdAtualCarros++;
            if (qtdAtualCarros > nMaxVagas) {
                possivel = 0;
            }
        }
        if (possivel)
            possivel = verificarSaidas(&hSaida);
        if (possivel)
            cout << "Sim\n";
        else
            cout << "Nao\n";
        limpaStack(&hSaida);
    }
}

void atualizarEst(stack<int> *hSaida,int hAtual,int *qtdAtualCarros,int *possivel) {
    while (!hSaida->empty()) {
        int topoHSaida = hSaida->top();
        int segundoVal;
        if (hAtual >= topoHSaida) { 
            hSaida->pop();
            *qtdAtualCarros -= 1;
            if (hSaida->empty())
                break;
            segundoVal = hSaida->top();
            if (segundoVal < topoHSaida){
                *possivel = 0;
                break;
            }
        }
        else {
            break;
        }
    }
}

void limpaStack(stack<int> *hSaida) {
    while (!hSaida->empty())
        hSaida->pop();
}

bool verificarSaidas(stack<int> *hSaida) {
    while (!hSaida->empty()) {
        int topoHSaida = hSaida->top();
        hSaida->pop();
        if (hSaida->empty())
            return 1;
        int proxTopoHSaida = hSaida->top();
        if (topoHSaida >= proxTopoHSaida)
            return 0;
        hSaida->pop();
    }
    return 1;
}