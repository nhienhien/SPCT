#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0;
int t = 0;
vector<int> dataIn;

// int N = 4;
// int t = 5;
// vector<int> dataIn = {0, 3, 1, 2, 2};
int resValue[100000][100000];
int line = 0;

int result[100];
void input() {
    cin >> N;
    cin >> t;
    int value = 0;
    dataIn.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> value;
        dataIn.push_back(value);
    }
}

void assignValue(int n) {
    line++;
    for (int i = 1; i <= n; i++) {
        resValue[line][i] = result[i];
    }
}

void gen(int i, int n) {
    for (int j = 0; j <= 1; j++) {
        result[i] = j;
        if (i < n) gen(i+1, n);
        else assignValue(n);
    }
}
int sum[10000] = {};
int solve() {
    int maxBook = 0;
    for (int i = 1; i <= line; i++) {
        int numbook = 0;
        for (int j = 1; j <= N; j++) {
            // cout << "dataIn[j] = " <<  dataIn[j] << " === resValue[i][j] = " << resValue[i][j] << endl;
            if (resValue[i][j] == 1) {
                numbook++;
                sum[i] += dataIn[j]*resValue[i][j];
            }
            
        }
        // cout << sum[i] << endl;
        if (sum[i] <= t) {
            maxBook = max(maxBook, numbook);
        }
    }
    return maxBook;
}

int main() {
    input();
    int max = 0;
    int length = 0;
    gen(1, N);
    // for (int i = 1; i <= line; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << resValue[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << line << endl;
    cout << solve();
    return 0;
}