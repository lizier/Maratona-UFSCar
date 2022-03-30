#include <iostream>
#include <stack>
using namespace std;

int main () {
    string expresion;
    //stack para guardar os abre parenteses
    stack<int> parenteses;
    while (1) {
        bool correto  = true;
        getline(cin,expresion);
        if (expresion.empty())
            break;
        for (int i = 0; i < expresion.length();i++) {
            if (expresion[i] == '(') {
                parenteses.push(1);
         }
            else if (expresion[i] == ')') {
                //a stack pode estar empty, indicando que há um fecha parenteses sem um que abre primeiro
                if (parenteses.empty() == true) {
                    correto = false;
                    break;
                }
             //se não estiver vazia, entao retiramos o ultimo abre parenteses da stack.
                parenteses.pop();
            }   
        }
        //obriogatoriamente a stack esta vazia para que a qtd de abre e fecha parenteses seja igual
        // e feita a limpeza da stack para a proxima iteracao
        if (parenteses.empty() != true) {
            //limpa a stack para a próxima iteração
            while (!(parenteses.empty()))
                parenteses.pop();
            correto = false;
        }

        if (correto == true)
            cout << "correct\n";
        else
            cout << "incorrect\n";
    }
    return 0;
}