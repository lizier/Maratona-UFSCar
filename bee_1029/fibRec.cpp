#include <iostream>
#include <vector>

using namespace std;

long long int qtdChamadas;
long long int fib(int numFib);


int main() {
    int qtdTestes;
    cin >> qtdTestes;
    for (int i = 0; i < qtdTestes; i++) {
        qtdChamadas = -1;
        int numFib;
        cin >> numFib;
        long long int valFib = fib(numFib);
        cout << "fib(" << numFib << ") = " << qtdChamadas << " calls = " << valFib << "\n";
    }
    return 0;
}

long long int fib(int numFib) {
    qtdChamadas++;
    if (numFib == 1) {
        return 1;
    }
    else if (numFib == 0) {
        return 0;
    }
    else {
        return fib(numFib - 1) + fib(numFib - 2);
    }
}

