#include <iostream>
using namespace std;

int N = 0;
int inputArr[20][20];
bool inputConvert[20][20];
bool visited[20][20];
void output() {
    cout << "==========" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << inputConvert[i][j] << " ";
        }
        cout << endl;
    }
}
void init() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            inputConvert[i][j] = false;
            visited[i][j] = false;
        }
    }
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inputArr[i][j];
        }
    }
}

bool inputConvertArr(int k) {
    bool status = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (inputArr[i][j] > k) {
                inputConvert[i][j] = true;
            } else {
                status = true;
            }
        }
    }
    return status;
}

bool validPos(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) {
        return false;
    }
    return true;
}

void DFS(int i, int j) {
    if (validPos(i, j) && inputConvert[i][j] && visited[i][j] == false) {
        visited[i][j] = true;
        DFS(i+1, j);
        DFS(i, j+1);
        DFS(i-1, j);
        DFS(i, j-1);
    }
}

int main() {
    input();
    init();
    int max = 0;
    int indexMax = 0;
    int level = 0;
    while(1) {
        int num = 0;
        init();
        bool check = inputConvertArr(level);
        // output();
        // cout << "level = " << level << " - status = " << check << endl;
        if (check == false) {
            level++;
            continue;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (inputConvert[i][j] && visited[i][j] == false) {
                    // cout << i << " - " << j << endl;
                    DFS(i, j);
                    num++;
                }
            }
        }
        if (num == 0) break;
        else if (num > max) {
            max = num;
            indexMax = level;
        }
        level++;
    }

    cout << indexMax;
    return 0;
}