#include <iostream>

using namespace std;

pair <long int, long int> A; //x e y da atual interseccao atual (ponto A) do ponto Superior Esquerdo
pair <long int, long int> B; //x e y da atual interseccao atual (ponto B) do ponto Inferior Direito


pair <long int, long int> U; //x e y do proximo quadrilatero testado do ponto Superior Esquerdo
pair <long int, long int> V; //x e y do proximo quadrilatero testado do ponto Inferior Direito

bool interSecABUV() { // Realiza o calculo de interseccao
    // Verifica se ha alguma interseccao entre os quadrilateros
    if  ( ! ((U.first <= B.first && U.second >= B.second) &&
             (V.first >= A.first && V.second <= A.second))
        )
            return 0;  
    
    pair <long int, long int> AI; //AI = ponto A interseccao
    pair <long int, long int> BI; //BI = ponto b interseccao

    // escolha dos novos pontos de interseccao
    // Ponto A
    // escolha de X do novo ponto A
    if ( A.first <= U.first && U.first <= B.first )
        AI.first = U.first;
    else
        AI.first = A.first;
    // escolha de Y do novo ponto A
    if ( B.second <= U.second && U.second <= A.second )
        AI.second = U.second;
    else
        AI.second = A.second;
    // Ponto B
    // escolha de X do novo ponto B
    if ( A.first <= V.first && V.first <= B.first )
        BI.first = V.first;
    else
        BI.first = B.first;
    // escolha de Y do novo ponto B
    if ( B.second <= V.second && V.second <= A.second )
        BI.second = V.second;
    else
        BI.second = B.second;
    
    //transfere o resultado para o pair A e B, e retorna 1 "sucesso"
    A = AI;
    B = BI;
    return 1;
} 


int main () {    
    unsigned int qtdTestes = 1;
    long int testeNum = 1;
    while (1) {
        cin >> qtdTestes;
        if (!qtdTestes)
            break;
        cin >> A.first >> A.second;
        cin >> B.first >> B.second;
    
        bool temIntersec = 1; //assume-se que existe alguma interseccao
        for (int i = 0; i < qtdTestes - 1; i++) {
            bool intersecEncontrada = 1;
            cin >> U.first >> U.second;
            cin >> V.first >> V.second;
            intersecEncontrada  = interSecABUV(); // caso o valor retornado por interSec seja 0, nao ha interseccao
            if (!intersecEncontrada) 
                temIntersec = 0;
        }
        cout << "Teste " << testeNum << "\n"; // Esse "1" precisa ser mudado depois
        if (temIntersec) { //executa apenas se ha interseccao
            cout << A.first << " " << A.second << " ";
            cout << B.first << " " << B.second << "\n";
        }
        else {
            cout << "nenhum\n";
        }
        cout << "\n";
        testeNum++;
    }
}
