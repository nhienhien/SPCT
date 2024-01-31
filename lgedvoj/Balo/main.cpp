#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int N = 3;
// int W = 8;
// vector<vector<int>> dataIn = {{3, 30},{4, 50},{5, 60}};

int N = 0;
int W = 0;
vector<vector<int>> dataIn;

int line = 0;

void input() {
    cin >> N;
    cin >> W;
    vector<int> value (2,0);
    for (int i = 0; i < N; i++) {
        cin >> value[0];
        cin >> value[1];
        dataIn.push_back(value);
    }
}
bool myfunction1 (vector<int> i,vector<int> j) { return (i[0] > j[0]); }
bool myfunction2 (vector<int> i,vector<int> j) { return (i[1] > j[1]); }
bool myfunction3 (vector<int> i,vector<int> j) { return ((float)i[0]/i[1] < (float)j[0]/j[1]); }
void out() {
    cout << "=====" << endl;
    int size = dataIn.size();
    for (int i = 0; i < size; i++) {
        cout << dataIn[i][0] << " " << dataIn[i][1] << endl;
    }
}
int result() {
    int size = dataIn.size();
    int sumN = 0;
    int sumW = 0;
    for (int i = 0; i < size; i++) {
        if (sumN + dataIn[i][0] <= W) {
            sumN += dataIn[i][0];
            sumW += dataIn[i][1];
        }
    }
    return sumW; 
}
void solve() {
    int maxV = 0;
    int resultV = 0;
    sort(dataIn.begin(), dataIn.end(), myfunction1);
    resultV = result();
    maxV = max(maxV, resultV);

    sort(dataIn.begin(), dataIn.end(), myfunction2);
    resultV = result();
    maxV = max(maxV, resultV);

    sort(dataIn.begin(), dataIn.end(), myfunction3);
    resultV = result();
    maxV = max(maxV, resultV);
    cout << maxV;
}

int main() {

    input();
    solve();
    return 0;
}