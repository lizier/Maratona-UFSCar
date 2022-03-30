#include <iostream>
#include <map>

using namespace std;

int main () {
    map<string,unsigned long long int> mapaPalavrasChave; //mapa que contem o dicionario do pontos de feno
    map<string,unsigned long long int>::iterator it; //iterador para mapa
    int qtdPalavrasChave, qtdDescricao;
    unsigned long long int salario = 0;
    cin >> qtdPalavrasChave;
    cin >> qtdDescricao;
    for (int i = 0; i < qtdPalavrasChave; i++) { //le as entradas e insere as palavras-chave no mapa
        pair<string,unsigned long long int> palavraChave; 
        cin >> palavraChave.first;
        cin >> palavraChave.second;
        mapaPalavrasChave.insert(palavraChave);

    }
    int flag = 0;
    while (flag < qtdDescricao) { //procura no texto as palavras chave e adiciona os valores em "salario"
        string palavraDescricao;
        cin >> palavraDescricao;
        if (palavraDescricao == ".") {
            flag++;
            cout << salario << "\n";
            salario = 0;
            continue;
        }
        it = mapaPalavrasChave.find(palavraDescricao); 
        if (it != mapaPalavrasChave.end()) //apenas se a palavra for encontrada, adiciona o valor associado no salario
            salario += it->second;        
    }
}