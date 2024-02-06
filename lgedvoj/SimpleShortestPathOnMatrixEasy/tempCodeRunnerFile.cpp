#include <iostream>
#include <vector>

using namespace std;

int M = 0;
int N = 0;
char inputArr[100][100];
bool inputConvert[100][100];
bool visited[100][100];
int result[100][100];

vector<int> startPos;
vector<int> endPos;

void input() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inputArr[i][j];
            result[i][j] = 10000;
        }
    }
}

void output() {
    cout << "======" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout <<result[i][j] << " ";
        }
        cout << endl;
    }
}

void inputConvertFunc() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (inputArr[i][j] == '+') {
                inputConvert[i][j] = false;
            } else {
                inputConvert[i][j] = true;
                if (inputArr[i][j] == 'S') {
                    startPos.push_back(i);
                    startPos.push_back(j);
                } else if (inputArr[i][j] == 'D') {
                    endPos.push_back(i);
                    endPos.push_back(j);
                }
            }
        }
    }
}

bool validPos(int i, int j) {
    if (i < 0 || i >= M || j < 0 || j >= N) {
        return false;
    }
    return true;
}

void DFS(int i, int j, int value) {
    
    if (validPos(i,j) && inputConvert[i][j] && visited[i][j] == false) {
        result[i][j] = min(result[i][j], value);
        // output();
        visited[i][j] = true;
        DFS(i+1, j, value + 1);
        DFS(i, j+1, value + 1);
        DFS(i-1, j, value + 1);
        DFS(i, j-1, value + 1);
    }
}

int main() {
    input();
    inputConvertFunc();
    // output();
    DFS(startPos[0], startPos[1], 0);
    cout << result[endPos[0]][endPos[1]];
    return 0;
}