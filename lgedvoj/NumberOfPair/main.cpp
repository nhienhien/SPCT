#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 5;
int result;
int inputArr[1000000] = {};
struct myclass {
  bool operator() (int i,int j) { return i<j; }
} myobj;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> inputArr[i];
    }
}

int findPosMax(int begin, int end) {
    int posMaxValue = (int)(max_element(inputArr + begin, inputArr + end) - inputArr);
    return posMaxValue;
}

void solve() {
    if (N == 2) {
        result = 1;
        return (void());
    } else {
        result = N - 1;
        for (int i = 0; i < N-2; i++) {
            if (inputArr[i] == inputArr[i+1]) continue;
            int beginPos = i + 2;
            int endPos = N - 1;
            while (endPos - beginPos > 0) {
                int posMaxValue = findPosMax(beginPos, endPos);
                endPos = posMaxValue - 1;
                if (inputArr[posMaxValue] <= inputArr[i]) result++;
            }
        }
    }
}

int main() {
    input();
    solve();
    cout << result;
    return 0;
}