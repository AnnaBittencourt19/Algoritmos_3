#include <iostream>
#include <algorithm>
using namespace std;
struct Inseto {
    string nome;
    double tamanho;
};
bool compara(Inseto a, Inseto b) {
    return a.tamanho < b.tamanho;
}
int main() {
    int n;
    cout << "Quantos insetos voce quer cadastrar? ";
    cin >> n;
    Inseto insetos[n];
    for (int i = 0; i < n; i++) {
        cout << "\nDigite o nome cientifico do inseto " << i + 1 << ": ";
        cin.ignore();
        getline(cin, insetos[i].nome);
        cout << "Digite o tamanho (em cm) do inseto " << i + 1 << ": ";
        cin >> insetos[i].tamanho;
    }
    sort(insetos, insetos + n, compara);
    for (int i = 0; i < n; i++) {
        cout << insetos[i].nome << endl;
    }
    return 0;
}
