#include <iostream>
#include <queue>
using namespace std;

int M = 0;
int N = 0;
int inputArr[100][100];
int visited1[100][100];
int visited2[100][100];

void output1() {
    // cout << "1==========" << endl;
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << visited1[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
}

void output2() {
    // cout << "2==========" << endl;
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << visited2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
}
void init() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            visited1[i][j] = true;
            visited2[i][j] = false;
        }
    }
}

void input() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inputArr[i][j];
        }
    }
}

bool validPos(int i, int j) {
    if (i < 0 || i >= M || j < 0 || j >= N) {
        return false;
    }
    return true;
}

void BFS1(int i, int j, int k) {
    if (validPos(i, j) && inputArr[i][j] <= k && visited1[i][j] == true) {
        visited1[i][j] = false;
        BFS1(i+1, j, k);
        BFS1(i, j+1, k);
        BFS1(i-1, j, k);
        BFS1(i, j-1, k);
    }
}

void BFS2(int i, int j, int k) {
    if (validPos(i, j) && visited1[i][j] == true && visited2[i][j] == false) {
        visited2[i][j] = true;
        BFS2(i+1, j, k);
        BFS2(i, j+1, k);
        BFS2(i-1, j, k);
        BFS2(i, j-1, k);
    }
}
bool floodFillOut(int k) {
    bool result = false;
    // cout << "k = " << k << endl;
    for (int i = 0; i < M; i++) {
        if (inputArr[0][i] <= k && visited1[0][i]) {
            BFS1(0, i, k);
            output1();
            result = true;
        }
        
        if (inputArr[M-1][i] <= k && visited1[M-1][i]) {
            BFS1(M-1, i, k);
            output1();
            result = true;
        }
        
        if (inputArr[i][0] <= k && visited1[i][0]) {
            BFS1(i, 0, k);
            output1();
            result = true;
        }
        
        if (inputArr[i][N-1] <= k && visited1[i][N-1]) {
            BFS1(i, N-1, k);
            output1();
            result = true;
        }
        
    }
    return result;
}

int main() {
    input();
    init();
    int level = 0;
    
    while(1) {
        init();
        int num = 0;
        bool check = floodFillOut(level);
        if (check == false) {
            level++;
            continue;
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (visited2[i][j] == false && visited1[i][j] == true) {
                    // cout << "i = " <<i<<" - j = "<<j<<endl;
                    BFS2(i, j, level);
                    output2();
                    num++;
                }
            }
        }
        if (num == 0) {
            cout << -1; 
            return 0;
        }
        if (num == 1) level++;
        else {
            cout << level;
            // cout << " " << num;
            return 0;
        }
    }
    return 0;
}