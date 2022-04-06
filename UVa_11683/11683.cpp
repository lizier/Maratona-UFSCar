// UVa 11683, Laser Sculpture, Lucas Katib

#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, C;
    stack<int> p;
    while(cin >> A >> C && A && C) {
        while(!p.empty()) {
            p.pop();
        }
        int resposta = 0;

        int x;
        for (int i = 0; i < C; i++) {
            cin >> x;
            if (!p.empty() && p.top() < x) {
                resposta += (x - p.top());
                while(!p.empty() && p.top() <= x) {
                    p.pop();
                }
            }
            p.push(x);
        }
        resposta += (A - p.top());
        cout << resposta << "\n";
    }
    return 0;
}
