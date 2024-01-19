#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N = 0;
vector<int> inputVec;
bool myfunction (int i,int j) { return (i<j); }
vector<vector<int>> input;

void Input() {
    cin >> N;
    int value = 0;
    for (int i = 0; i < N; i++) {
        cin >> value;
        inputVec.push_back(value);
    }
}

int C(int k, int n) {
	if (k == 0 || k == n) return 1;
	if (k == 1) return n;
	return C(k - 1, n - 1) + C(k, n - 1);
}

void ConvertInput() {
    vector<int> sub = {inputVec[0], 1};
    input.push_back(sub);
    int index = 0;
    for (int i = 1; i < N; i++) {
        if (inputVec[i] == inputVec[i-1]) {
            // cout << i << " " << inputVec[i] << " == " << inputVec[i-1] << endl;
            input[index][1]++;
        } else {
            // cout << i << " " << inputVec[i] << " != " << inputVec[i-1] << endl;
            index++;
            sub = {inputVec[i], 1};
            input.push_back(sub);
        }
    }
}

// void Output() {
//     for (uint8_t i = 0; i < (uint8_t)input.size(); i++) {
//         cout << input[i][0] << " " << input[i][1] << endl;
//     }
// }

int findValueValid(int value) {
    int result = 0;
    int size = input.size();
    for (int i = 0; i < size; i++) {
        if (input[i][0] >= value*2) break;
        if (input[i][0] < value*2 && input[i][0] != value) {
            result += input[i][1];
        }
    }
    return result;
}

int solve() {
    int result = 0;
    int size = input.size();
    for (int i = 0; i < size; i++) {
        if (input[i][1] > 1) {
            result += findValueValid(input[i][0])*C(2, input[i][1]);
        }
    }
    return result;
}

int main() {
    Input();
    sort(inputVec.begin(), inputVec.end(), myfunction);
    ConvertInput();
    // Output();
    cout << solve();
    return 0;
}