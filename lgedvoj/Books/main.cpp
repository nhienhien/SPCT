#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0;
int t = 0;
vector<int> dataIn;
void input() {
    cin >> N;
    cin >> t;
    int value = 0;
    for (int i = 0; i < N; i++) {
        cin >> value;
        dataIn.push_back(value);
    }
}

int lengthValid(int pos) {
    int length = 0;
    long int sum = 0;
    if (dataIn[pos] > t) return 0;
    if (dataIn[pos] == t) return 1;
    for (int i = pos; i < N; i++) {
        if (sum + dataIn[i] > t) return length;
        length++;
        sum += dataIn[i];
    }
    return length;
}

int main() {
    input();
    int max = 0;
    int length = 0;
    for (int i = 0; i < N; i++) {
        length = lengthValid(i);
        if (max < length) max = length;
    }
    cout << max;
    return 0;
}