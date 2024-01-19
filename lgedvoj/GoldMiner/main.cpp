#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int row[4] = {0, 1, 0, -1};
const int column[4] = {1, 0, -1, 0};
int N = 6;
int M = 8;
char inputVal[50][50] ={{'G',',',',','G',',',',',',','4'},
                        {',','3',',',',','G','1',',',','},
                        {'G',',',',','G',',',',',',',','},
                        {',','G',',',',',',',',','2',','},
                        {',',',',',','G',',',',',',',','},
                        {',','G',',',',',',','1',',',','}};
bool visited[50][50] = {};

void input() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> inputVal[i][j];
        }
    }
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
}

void updateDinamite_1s(int x, int y, int num) {
    for (int i = x-num; i <= x+num; i++) {
        for (int j = y-num; j <= j+num; j++) {
            visited[i][j] = true;
        }
    }
}

bool CheckCompelete() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (inputVal[i][j] == 'G' && visited[i][j] == false) {
                return 0;
            }
        }
    }
    return true;
}

void UpdatePos(int x, int y) {
    visited[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int nexti = x + row[k];
        int nextj = y + column[k];
        if (nexti < 0 || nexti > N-1 || nextj < 0 || nexti > M-1) {
            continue;
        }
        UpdatePos(nexti, nextj);
    }
}

int second = 0;
void updateDinamite(int x, int y) {
    updateDinamite_1s(x, y, 1);
    if (CheckCompelete() == false) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                UpdatePos
            }
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (inputVal[i][j] == ',') {
                updateDinamite(i, j);
            }
        }
    }
}

int main() {
    init();
    while (CheckCompelete() == false) {
        solve();
    }

    return 0;
}