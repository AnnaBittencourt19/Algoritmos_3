#include <iostream>
#include <algorithm> // sort
using namespace std;

// 1) Definindo a struct
struct Inseto {
    string nome;
    double tamanho;
};

// 2) Função de comparação para a ordenação
bool compara(Inseto a, Inseto b) {
    return a.tamanho < b.tamanho; // ordena do menor para o maior
}

int main() {
    int n;
    cin >> n; // 3) Lê a quantidade de insetos

    Inseto insetos[n]; // cria um vetor de insetos

    // 4) Lendo os dados de cada inseto
    for (int i = 0; i < n; i++) {
        cin.ignore(); // para garantir que não sobrou \n na entrada
        getline(cin, insetos[i].nome); // lê o nome (pode ter espaços)
        cin >> insetos[i].tamanho;     // lê o tamanho
    }

    // 5) Ordenando usando sort + função de comparação
    sort(insetos, insetos + n, compara);

    // 6) Imprimindo apenas os nomes na ordem
    for (int i = 0; i < n; i++) {
        cout << insetos[i].nome << endl;
    }

    return 0;
}
