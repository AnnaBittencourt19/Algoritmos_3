#include <iostream>
#include <cmath>
using namespace std;

struct Gladiador {
    string nome;
    int forca;
    int habilidade;
    int idade;
};

int combate(Gladiador g1, Gladiador g2) {
    int vida1 = 100;
    int vida2 = 100;

    while (vida1 > 0 && vida2 > 0) {
        int dano1 = g1.forca + pow(2, g1.habilidade);
        vida2 -= dano1;
        if (vida2 <= 0) return 1;

        int dano2 = g2.forca + pow(2, g2.habilidade);
        vida1 -= dano2;
        if (vida1 <= 0) return 2;
    }
    return 0;
}

int main() {
    Gladiador gladiadores[5];

    for (int i = 0; i < 5; i++) {
        cout << "Nome do gladiador " << i << ": ";
        cin >> gladiadores[i].nome;

        cout << "Forca (0-10): ";
        cin >> gladiadores[i].forca;

        cout << "Habilidade (0-10): ";
        cin >> gladiadores[i].habilidade;

        cout << "Idade: ";
        cin >> gladiadores[i].idade;

        cout << endl;
    }

    while (true) {
        int g1, g2;
        cout << "Escolha os gladiadores (índices 0-4) ou -1 para sair: ";
        cin >> g1;
        if (g1 == -1) break;
        cin >> g2;

        int vencedor = combate(gladiadores[g1], gladiadores[g2]);

        if (vencedor == 1) {
            cout << gladiadores[g1].nome << " ganhou a batalha contra "
                 << gladiadores[g2].nome << endl;
        } else {
            cout << gladiadores[g2].nome << " ganhou a batalha contra "
                 << gladiadores[g1].nome << endl;
        }
    }

    return 0;
}
