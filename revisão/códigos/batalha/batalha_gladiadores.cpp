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
    Gladiador gladiadores[10];
    int numGladiadores = 0;
    int opcao;

    while (true) {
        cout << "\n=== SISTEMA DE BATALHA ===\n";
        cout << "1. Cadastrar um gladiador\n";
        cout << "2. Fazer uma batalha\n";
        cout << "3. Sair do sistema\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            if (numGladiadores < 10) {
                cout << "\nNome do gladiador: ";
                cin >> gladiadores[numGladiadores].nome;
                cout << "Forca (0-10): ";
                cin >> gladiadores[numGladiadores].forca;
                cout << "Habilidade (0-10): ";
                cin >> gladiadores[numGladiadores].habilidade;
                cout << "Idade: ";
                cin >> gladiadores[numGladiadores].idade;
                numGladiadores++;
                cout << "Gladiador cadastrado com sucesso!\n";
            } else {
                cout << "Limite de gladiadores atingido!\n";
            }
        }
        else if (opcao == 2) {
            if (numGladiadores < 2) {
                cout << "\nE necessario ter pelo menos 2 gladiadores cadastrados!\n";
            } else {
                cout << "\nGladiadores disponiveis:\n";
                for (int i = 0; i < numGladiadores; i++) {
                    cout << i << ". " << gladiadores[i].nome << endl;
                }
                
                int g1, g2;
                cout << "Escolha o primeiro gladiador (0-" << numGladiadores-1 << "): ";
                cin >> g1;
                cout << "Escolha o segundo gladiador (0-" << numGladiadores-1 << "): ";
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
        }
        else if (opcao == 3) {
            cout << "Saindo do sistema...\n";
            break;
        }
        else {
            cout << "Opcao invalida!\n";
        }
    }

    return 0;
}
