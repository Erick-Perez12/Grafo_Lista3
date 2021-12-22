#include <iostream>
using namespace std;

#define FILA 8
#define COL 8

int detIsla(int M[][COL], int fila, int col, bool visited[][COL]) {
    return (fila >= 0) && (fila < FILA) && (col >= 0) && (col < COL) && (M[fila][col] && !visited[fila][col]);
}

void DFS(int M[][COL], int fila, int col, bool visited[][COL]) {
    static int filaNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    visited[fila][col] = true;
    for (int k = 0; k < 8; ++k)
        if (detIsla(M, fila + filaNbr[k], col + colNbr[k], visited)) 
            DFS(M, fila + filaNbr[k], col + colNbr[k], visited);
}

int Islas(int M[][COL]) {
    bool visited[FILA][COL];
    memset(visited, 0, sizeof(visited));
    int count = 0;
    for (int i = 0; i < FILA; ++i)
        for (int j = 0; j < COL; ++j)
            if (M[i][j] && !visited[i][j]) {
                DFS(M, i, j, visited);
                ++count;
            }

    return count;
}

void print(int M[][COL]) {
    for (int i = 0; i < FILA; i++) {
        for (int j = 0; j < COL; j++) {
            cout <<" " << M[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int I[][COL] = { { 0, 1, 1, 0, 0, 1, 0, 1 },
                     { 0, 1, 0, 0, 0, 0, 0, 1 },
                     { 0, 0, 0, 1, 1, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 1, 0 },
                     { 1, 1, 0, 0, 0, 0, 1, 1 },
                     { 1, 0, 1, 0, 0, 0, 1, 0 },
                     { 1, 0, 0, 0, 0, 0, 0, 1 },
                     { 0, 1, 1, 0, 0, 0, 0, 0 }
    };
    cout << "MAPA" << endl;
    print(I);
    cout << "Numero de islas es: " << Islas(I);
    return 0;
}