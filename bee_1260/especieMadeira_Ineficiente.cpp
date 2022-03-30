#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<pair<string,unsigned long int>>::iterator encontraArvore(vector<pair<string,unsigned long int>> *contagemArvores,string nomeArvore) {
    for (auto i =  contagemArvores->begin(); i != contagemArvores->end() ; i++ ) {
        if (i->first == nomeArvore) {
            return i;
        }
    }
    return contagemArvores->end();
}

int main () {
    string nomeArvore;
    unsigned int casosTeste;
    unsigned long int qtdArvores = 0;
    vector<pair<string,unsigned long int>>::iterator it;
    cin >> casosTeste;
    getline(cin,nomeArvore);
    getline(cin,nomeArvore);
    cout << fixed << setprecision(4);
    for (int i = 0; i < casosTeste; i++) {
        vector<pair<string,unsigned long int>> contagemArvores;
        qtdArvores = 0;
        while(true) {
            getline(cin,nomeArvore);
            if (nomeArvore == "")
                break;
            it = encontraArvore(&contagemArvores,nomeArvore);
            if (it == contagemArvores.end())
                contagemArvores.push_back({nomeArvore,1});
            else 
                (it->second)++;
            qtdArvores++;
        }
        sort(contagemArvores.begin(),contagemArvores.end());
        for (auto j = contagemArvores.begin(); j != contagemArvores.end(); j++) {
            cout << j->first << " ";
            cout << (double)(j->second/(double)qtdArvores)*100;
            cout << "\n";
        }
        cout << "\n";
    }
}