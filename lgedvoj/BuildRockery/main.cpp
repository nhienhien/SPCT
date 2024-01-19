#include<iostream>
#include<vector>

using namespace std;
const int row[4] = {0, 1, 0, -1};
const int column[4] = {1, 0, -1, 0};
// int N = 3;
// int inputArr[20][20] = {{6, 3, 6},
//                         {3, 6, 2},
//                         {7, 3, 8}};
int N = 0;
int inputArr[20][20];
bool checkArr[20][20];
int visited[20][20] = {0};
int maxValue = 8;
void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inputArr[i][j];
            maxValue = max(maxValue, inputArr[i][j]);
        }
    }
}
void resetBoolArr() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            checkArr[i][j] = false;
            visited[i][j] = 0;
        }
    }
}

void UpdateBoolArr(int value) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (inputArr[i][j] > value) {
                checkArr[i][j] = true;
            }
            // cout << checkArr[i][j] << " ";
        }
        // cout << endl;
    }
}

void findIs(int x, int y, int numIs) {
    visited[x][y] = numIs;
    for (int i = 0; i < 4; i++) {
        int newx = x + row[i];
        int newy = y + column[i];
        if (newx < 0 || newx >= N || newy < 0 || newy >= N) {
            continue;
        }

        if (checkArr[newx][newy] == true && visited[newx][newy] == 0) {
            findIs(newx, newy, numIs);
        }
    }
}

int numberIs() {
    int numIs = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (checkArr[i][j] == true && visited[i][j] == 0) {
                numIs++;
                findIs(i, j, numIs);
                // for (int i = 0; i < N; i++) {
                //     for (int j = 0; j < N; j++) {
                //         cout << visited[i][j] << " ";
                //     }
                //     cout << endl;
                // }
            } 
        }
    }
    return numIs;
}

int solve() {
    vector<int> resultArr;
    int minIs = 0;
    int maxValueIs = 0;
    for (int i = 1; i < maxValue; i++) {
        // cout << "===" << i << "===" << endl;
        resetBoolArr();
        UpdateBoolArr(i);
        int numIs = numberIs();
        resultArr.push_back(numIs);
        // cout << numIs << " " << maxValueIs << endl;
        if (numIs > maxValueIs) {
            minIs = i;
            maxValueIs = numIs;
        }
    }
    // cout << endl;

    return minIs;
}

int main() {
    input();
    resetBoolArr();
    cout << solve();
    return 0;
}