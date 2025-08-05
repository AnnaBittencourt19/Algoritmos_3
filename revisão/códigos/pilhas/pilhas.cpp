#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
const int M = 43;
struct Item {
    int codigo;
    string nome;
    int preco;
};
void inserirHash(Item* tabela[], Item* novo) {
    int hash = novo->codigo % M;
    int i = 0;

    while (tabela[(hash + i) % M] != nullptr) {
        i++;
    }
    tabela[(hash + i) % M] = novo;
}
Item* buscarHash(Item* tabela[], int codigo) {
    int hash = codigo % M;
    int i = 0;

    while (i < M) {
        int pos = (hash + i) % M;
        if (tabela[pos] == nullptr) return nullptr;
        if (tabela[pos]->codigo == codigo) return tabela[pos];
        i++;
    }
    return nullptr;
}
int main() {
    int n;
    cin >> n;
    Item* tabela[M];
    for (int i = 0; i < M; i++) tabela[i] = nullptr;
    for (int i = 0; i < n; i++) {
        Item* novo = new Item;
        cin >> novo->codigo >> novo->nome >> novo->preco;
        inserirHash(tabela, novo);
    }
    queue<int> filaVendas;
    int codigo;
    while (cin >> codigo && codigo != -1) {
        filaVendas.push(codigo);
    }
    stack<int> pilhaCompras;
    while (cin >> codigo && codigo != -1) {
        pilhaCompras.push(codigo);
    }
    int V, C;
    cin >> V >> C;
    int totalVendas = 0;
    int totalCompras = 0;
    for (int i = 0; i < V && !filaVendas.empty(); i++) {
        int cod = filaVendas.front();
        filaVendas.pop();
        Item* item = buscarHash(tabela, cod);
        if (item != nullptr) totalVendas += item->preco;
    }
    for (int i = 0; i < C && !pilhaCompras.empty(); i++) {
        int cod = pilhaCompras.top();
        pilhaCompras.pop();
        Item* item = buscarHash(tabela, cod);
        if (item != nullptr) totalCompras += item->preco;
    }
    int lucro = totalVendas - totalCompras;
    cout << lucro << " moeda(s)." << endl;

    return 0;
}
