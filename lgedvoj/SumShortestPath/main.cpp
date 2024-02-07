#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int M = 0;
int N = 0;
char inputArr[100][100];
bool visited[100][100];
bool inputConvert[100][100];
int result[100][100];
vector<vector<int>> posPoint;

typedef struct {
    int x;
    int y;
} POS;
int c[4] = {-1, 0, 1, 0};
int r[4] = {0, 1, 0, -1};

void init() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            result[i][j] = 1000;
        }
    }
}
void output() {
    cout << "======" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
}
void input() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inputArr[i][j];
            if (inputArr[i][j] >= '1' && inputArr[i][j] <= '9') {
                posPoint.push_back({i, j, false});
                inputConvert[i][j] = true;
            }
            if (inputArr[i][j] == '-') {
                inputConvert[i][j] = true;
            }
        }
    }
}

bool validPos(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) {
        return false;
    }
    return true;
}

void BFS(int i, int j) {
    queue<POS> q;
    q.push({i, j});
    visited[i][j] = true;
    result[i][j] = 1;
    while (!q.empty()) {
        POS value = q.front();
        q.pop();
        int x = value.x;
        int y = value.y;
        for (int k = 0; k < 4; k++) {
            int newx = x + c[k];
            int newy = y + r[k];
            if (validPos(newx, newy) && visited[newx][newy] == false && inputConvert[newx][newy] == true) {
                visited[newx][newy] = true;
                result[newx][newy] = min(result[x][y] + 1, result[newx][newy]);
                q.push({newx, newy});
            }
        }
    }
    output();
}

int sumPath(int x, int y) {
    int sum = 0;
    for (int i = 0; i < (int)posPoint.size(); i++) {
        if (posPoint[i][2] == true) {
            continue;
        } else if (posPoint[i][0] == x && posPoint[i][1] == y) {
            continue;
        } else if (result[posPoint[i][0]][posPoint[i][1]] == 1000) {
            continue;
        } else {
            sum += result[posPoint[i][0]][posPoint[i][1]];
        }
    }
    return sum;
}

int main() {
    input();
    int rs = 0;
    for (int i = 0; i < (int)posPoint.size(); i++) {
        init();
        cout << "i = " << i << endl;
        BFS(posPoint[i][0], posPoint[i][1]);
        posPoint[i][2] = true;
        rs += sumPath(posPoint[i][0], posPoint[i][1]);
        cout << "RS = " << rs << endl;
    }
    cout << rs;
    return 0;
}