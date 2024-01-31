#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
int Q = 0;
vector<int> inputVec;
vector<int> findVec;

bool sortL2H(int i, int j) {return (i < j);}
void output() {
    for (int i = 0; i < N; i++) {
        cout << inputVec[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < Q; i++) {
        cout << findVec[i] << " ";
    }
    cout << endl;
}
void input() {
    cin >> N;
    int value;
    for (int i = 0; i < N; i++) {
        cin >> value;
        inputVec.push_back(value);
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> value;
        findVec.push_back(value);
    }
    sort(inputVec.begin(), inputVec.end(), sortL2H);
}

bool isPresent(int value, int lo, int hi, int& result) {
    int pos = 0;
    while (lo <= hi) {
        // cout << "value = " << value << ":";
        // cout << lo << " " << hi << " -> ";
        int mid = (lo + hi)/2;
        if (inputVec[mid] < value) {
            // cout << "mid = " << mid << " true" << endl;
            pos = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
        // cout << lo << " " << hi << endl;
    }
    if (inputVec[pos] < value) {
        result = inputVec[pos];
        return true;
    }
    // cout << "false" << endl;
    return false;
}

int main()
{
    input();
    // output();
    bool value = 0;
    int result = 0;
    for (int i = 0; i < Q; i++) {
        // cout << "i = " << i << " " << findVec[i] << endl;
        if (findVec[i] <= inputVec[0]) cout << "NONE" << endl;
        else if (findVec[i] > inputVec[N-1]) cout << inputVec[N-1] << endl;
        else {
            value = isPresent(findVec[i], 0, N - 1, result);
            if (value == true) {
                cout << result << endl;
            } else {
                cout << "NONE" << endl;
            }
        }
    }
    return 0;
}
