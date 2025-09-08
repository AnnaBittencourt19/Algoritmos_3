#include <iostream>
using namespace std;

const int N = 4;

char board[N][N];   // tabuleiro
bool col[N];        // colunas ocupadas
bool posDiag[2*N];  // diagonais ↘ (índice r+c)
bool negDiag[2*N];  // diagonais ↙ (índice r-c + (N-1))

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------" << endl;
}

void backtrack(int r) {
    if (r == N) {          // base: colocou N rainhas
        printBoard();
        return;
    }

    for (int c = 0; c < N; c++) {
        if (col[c] || posDiag[r+c] || negDiag[r-c+N-1])
            continue;      // posição (r,c) não é segura

        // marca
        col[c] = true;
        posDiag[r+c] = true;
        negDiag[r-c+N-1] = true;
        board[r][c] = 'Q';

        backtrack(r+1);    // tenta próxima linha

        // desmarca (volta atrás)
        col[c] = false;
        posDiag[r+c] = false;
        negDiag[r-c+N-1] = false;
        board[r][c] = '.';
    }
}

int main() {
    // tabuleiro vazio
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = '.';

    // marcadores zerados
    for (int i = 0; i < N; i++) col[i] = false;
    for (int i = 0; i < 2*N; i++) posDiag[i] = negDiag[i] = false;

    backtrack(0); // começa da linha 0
    return 0;
}
