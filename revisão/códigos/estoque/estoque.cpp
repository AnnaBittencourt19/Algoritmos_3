#include <iostream>
using namespace std;
struct Produto {
    string nome;
    int quantidade;
};
int main() {
    int n;
    cout << "Quantos produtos voce quer cadastrar? ";
    cin >> n;
    Produto produtos[n];
    for (int i = 0; i < n; i++) {
        cout << "\nDigite o nome do produto " << i + 1 << ": ";
        cin >> produtos[i].nome;

        cout << "Digite a quantidade em estoque do produto " << i + 1 << ": ";
        cin >> produtos[i].quantidade;
    }
    string nomeBusca;
    cout << "\nDigite o nome do produto que deseja buscar: ";
    cin >> nomeBusca;
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (produtos[i].nome == nomeBusca) {
            cout << produtos[i].nome << " em estoque!" << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Nao existe " << nomeBusca << " em estoque!" << endl;
    }
    return 0;
}
