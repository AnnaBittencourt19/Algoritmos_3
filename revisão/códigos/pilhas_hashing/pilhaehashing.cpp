#include <iostream>
#include <stack>
using namespace std;
int main() {
    int M, N;
    cout << "Digite o tamanho da tabela hash (M): ";
    cin >> M;
    cout << "Digite a quantidade de elementos (N): ";
    cin >> N;
    stack<int> pilha;
    cout << "Digite os " << N << " elementos: ";
    for (int i = 0; i < N; i++) {
        int valor;
        cin >> valor;
        pilha.push(valor);
    }
    int tabela[M];
    for (int i = 0; i < M; i++) {
        tabela[i] = -1;
    }
    while (!pilha.empty()) {
        int k = pilha.top();
        pilha.pop();
        int h1 = k % M;
        int h2 = 1 + (k % (M - 1));
        int pos = h1;
        int i = 0;
        while (tabela[pos] != -1) {
            i++;
            pos = (h1 + i * h2) % M;
        }
        tabela[pos] = k;
    }
    cout << "\nTabela hash final:\n";
    for (int i = 0; i < M; i++) {
        cout << tabela[i] << " ";
    }
    cout << endl;
    return 0;
}
