#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
int c = 0;
vector<vector<int>> inputVec;

void output() {
    cout << "=====" << endl;
    for (int i = 0; i < N; i++) {
        cout << inputVec[i][0] << " " << inputVec[i][1] << endl;
    }
}
bool sortH2L(vector<int> i, vector<int> j) {return(i[0] < j[0]);}
void input() {
    cin >> N;
    cin >> c;
    
    int value;
    for (int i = 0; i < N; i++) {
        vector<int> subInput;
        cin >> value;
        subInput.push_back(value);
        cin >> value;
        subInput.push_back(value);
        inputVec.push_back(subInput);
    }
    // output();
    sort(inputVec.begin(), inputVec.end(), sortH2L);
    // output();
}

int solve(){
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (inputVec[i][0] <= c) {
            result++;
            c += inputVec[i][1];
        } else break;
    }
    return result;
}

int main() {
    input();
    int result = 0;
    result = solve();
    cout << result;
}