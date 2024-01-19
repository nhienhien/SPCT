#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> input;
int N = 0;
int inputArr[200] = {};

void inputValue() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> inputArr[i];
    }
}

void ConvertInput() {
    vector<int> sub = {inputArr[0], 1};
    input.push_back(sub);
    int index = 0;
    for (int i = 1; i < N; i++) {
        if (inputArr[i] == inputArr[i-1]) {
            // cout << i << " " << inputArr[i] << " == " << inputArr[i-1] << endl;
            input[index][1]++;
        } else {
            // cout << i << " " << inputArr[i] << " != " << inputArr[i-1] << endl;
            index++;
            sub = {inputArr[i], 1};
            input.push_back(sub);
        }
    }
}

void Output() {
    for (uint8_t i = 0; i < (uint8_t)input.size(); i++) {
        cout << input[i][0] << " " << input[i][1] << endl;
    }
}

int getScore(int n, int A[]) {
    int res = 1;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (A[i] == A[i - 1]) cnt++;
        else cnt = 1;
        res = max(res, cnt);
    }
    return res;
}

int solve() {
    int size = input.size();
    // cout << size << endl;
    
    int result = getScore(N, inputArr);
    if (size == 1) return (input[0][1]);
    if (size == 2) return (input[0][1], input[1][1]);
    for (int i = 2; i < size; i++) {
        if (input[i][0] == input[i-2][0]) {
            result = max(result, input[i][1] + input[i-2][1]);
        }
    }
    return result;
}

int main() {
    inputValue();
    if (N == 2) {
        if (inputArr[0] == inputArr[1]) cout << 2;
        else cout << 1;
        return 0;
    } 
    ConvertInput();
    // Output();
    // cout << "Output" << endl;
    cout << solve();
    return 0;
}