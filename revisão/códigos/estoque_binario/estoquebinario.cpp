#include <iostream>
using namespace std;
struct Produto {
    int codigo;
    string nome;
    int quantidade;
};
int main() {
    int n;
    cout << "Quantos produtos voce quer cadastrar? ";
    cin >> n;
    Produto produtos[n];
    cout << "\nDigite os dados em ordem crescente (codigo nome quantidade):\n";
    for (int i = 0; i < n; i++) {
        cout << "Produto " << i + 1 << ": ";
        cin >> produtos[i].codigo >> produtos[i].nome >> produtos[i].quantidade;
    }
    int codigoBusca;
    cout << "\nDigite o codigo do produto que deseja buscar: ";
    cin >> codigoBusca;
    int inicio = 0;
    int fim = n - 1;
    bool encontrado = false;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (produtos[meio].codigo == codigoBusca) {
            cout << produtos[meio].nome << " em estoque!" << endl;
            encontrado = true;
            break;
        }
        else if (produtos[meio].codigo > codigoBusca) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }
    if (!encontrado) {
        cout << "Nao existem produtos com esse codigo em estoque!" << endl;
    }
    return 0;
}
