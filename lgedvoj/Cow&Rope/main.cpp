#include <iostream>
#include <queue>
using namespace std;

int N = 0;
int M = 0;
bool inputArr[250][250];
bool visited[250];

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            inputArr[i][j] = false;
        }
    }
}
void input() {
    cin >> N >> M;
    int value1;
    int value2;
    for (int i = 1; i <= M; i++) {
        cin >> value1;
        cin >> value2;
        inputArr[value1][value2] = true;
        inputArr[value2][value1] = true;
    }
}

void BFS(int S) {
    queue<int> q;
    q.push(S);
    visited[S] = true;
    while (!q.empty()) {
        int first = q.front();
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (inputArr[first][i] && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    init();
    input();
    BFS(1);
    bool check = false;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            cout << i << " ";
            check = true;
        }
    }
    if (check == false) cout << 0;
    return 0;
}