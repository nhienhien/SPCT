#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
char inputArr[100][100] = {};
vector<vector<int>> result;
bool visited[100][100];
int r[4] = {-1, 0, 1, 0};
int c[4] = {0, 1, 0, -1};

void input() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> inputArr[i][j];
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
void UpdatePosVisited(int x, int y, char color, int& num) {
    int newx {0};
    int newy {0};
    num++;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        newx = x + r[i];
        newy = y + c[i];

        if (x < 0 || x > N-1 || y < 0 || y > M-1) {
            continue;
        }

        if (inputArr[newx][newy] == color && visited[newx][newy] == false) {
            UpdatePosVisited(newx, newy, color, num);
        }
    }
}
int numBlock = 0;
int numElementBlock = 0;
char color[3] = {'R', 'G', 'B'};

void solve(char color) {
    numBlock = 0;
    numElementBlock = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (inputArr[i][j] == color && visited[i][j] == false) {
                UpdatePosVisited(i, j, color, numElementBlock);
                numBlock++;
                // for (int i = 0; i < N; i++) {
                //     for (int j = 0; j < M; j++) {
                //         cout << visited[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << "=====" << endl;
            }
        }
    }
    // cout << color << " " << numBlock << " " << numElementBlock << endl;
    vector<int> subResult = {numBlock, numElementBlock};
    result.push_back(subResult);
    
}
int main() {
    input();
    init();
    int maxf = 0;
    int maxs = 0;
    for (int i = 0; i < 3; i++) {
        solve(color[i]);
        maxf = max(maxf, result[i][0]);
    }
    for (int i = 0; i < 3; i++) {
        if (result[i][0] == maxf) {
            maxs = max(maxs, result[i][1]);
        }
    }

    for (int i = 0; i < 3; i++) {
        if (result[i][0] == maxf && result[i][1] == maxs) {
            cout << color[i];
            break;
        }
    }
    return 0;
}