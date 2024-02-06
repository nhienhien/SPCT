#include <iostream>
#include <queue>
using namespace std;

int M = 0;
int N = 0;
int inputArr[100][100];
bool inputConvert[100][100];
bool visited[100][100];

void input() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inputArr[i][j];
        }
    }
}

void ConvertInput(int k) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            if (inputArr[i][j] > k) {
                inputConvert[i][j] = 1;
            } else inputConvert[i][j] = 0;
        }
    }

    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << inputConvert[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

bool isValid(int i, int j) {
    if (i < 0 || i >= M || j < 0 || j >= N) return false;
    return true;
}
void DFS(int i, int j) {
    if (isValid(i, j) && visited[i][j] == 0 && inputConvert[i][j] == 1) {
        visited[i][j] = true;
        DFS(i+1, j);
        DFS(i, j+1);
        DFS(i-1, j);
        DFS(i, j-1);
    }
}

int main() {
    input();
    int level = 0;
    
    while (1) {
        int num = 0;
        ConvertInput(level);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (inputConvert[i][j] == 1 && visited[i][j] == 0) {
                    DFS(i, j);
                    num++;
                    // cout << "num = " << num << endl;
                }
            }
        }
        if (num == 0) {cout << -1; return 0;}
        if (num == 1) level++;
        else {
            cout << level;
            return 0;
        }
    }
    return 0;

}