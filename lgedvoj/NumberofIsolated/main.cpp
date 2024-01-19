#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int row[4] = {0, 1, 0, -1};
const int column[4] = {1, 0, -1, 0};
int N = 0;
int M = 0;
int inputVal[100][100] = {};
int visited[100][100] = {};
// int N = 8;
// int M = 5;
// int inputVal[100][100] =   {{1,1,1,1,1,1,1,0},
//                             {1,0,0,0,0,1,1,0},
//                             {1,0,1,0,1,1,1,0},
//                             {1,0,0,0,0,1,0,1},
//                             {1,1,1,1,1,1,1,0}};
// int visited[100][100] = {};

int numIs = 0;
bool checkIs = true; 
int result = 0;

void input(){
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inputVal[i][j];
        }
    }
}

void init() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}
bool isIs = true;
void FindIs(int x, int y, int num) {
    visited[x][y] = num;
    for (int i = 0; i < 4; i++) {
        int nearX = x + column[i];
        int nearY = y + row[i];
        
        if (nearX < 0 || nearX > M-1 || nearY < 0 || nearY > N-1) {
            isIs = false;
            continue;
        }
        if (inputVal[nearX][nearY] == 0 && visited[nearX][nearY] == 0) {
            // if (nearX == 0 || nearX == N-1 || nearY == 0 || nearY == M-1) {
            //     isIs = false;
            //     continue;
            // }
            FindIs(nearX, nearY, num);
        }
    }
}

void outIs() {
    cout << "===========" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << result << endl;
}

void solve() {
    for (int i = 1; i < M-1; i++) {
        for (int j = 1; j < N-1; j++) {
            if (inputVal[i][j] == 0 && visited[i][j] == 0) {
                numIs++;
                isIs = true;
                FindIs(i, j, numIs);
                if (isIs) result++;
                // outIs();
            }
        }
    }
}

int main() {
    input();
    init();
    // while (checkIs) {
    solve();
    cout << result;
    // }
}