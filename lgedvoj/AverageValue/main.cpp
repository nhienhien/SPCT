/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0;
vector<int> inputVec;
int Q = 0;
vector<int> inputAve;
vector<float> average;

bool sortL2H(int i, int j) {return(i<j);}
void output() {
    for (int i = 0; i < N; i++) {
        cout << inputVec[i] << " ";
    }
    cout << endl;
}

void input() {
    cin >> N;
    int value = 0;
    for (int i = 0; i < N; i++) {
        cin >> value;
        inputVec.push_back(value);
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> value;
        inputAve.push_back(value);
    }
    sort(inputVec.begin(), inputVec.end(), sortL2H);
    output();
}

void Average() {
    float sum = (float)inputVec[0];
    average.push_back(sum);
    cout << average[0] << " ";
    for (int i = 1; i < N; i++) {
        sum = average[i-1]*i + inputVec[i];
        average.push_back(sum/(i+1));
        cout << average[i] << " ";
    }
    cout << endl;
}

bool binarySearch(int lo, int hi, int value, int& pos) {
    int mid = (lo + hi)/2;
    while (lo <= hi) {
        if (average[mid] < value) {
            pos = mid;
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    if (average[pos] < value) return true;
    return false;
}

int main()
{
    input();
    Average();
    int result = 0;
    for (int i = 0; i < Q; i++) {
        if (binarySearch(0, N-1, inputAve[i], result)) {
            cout << result << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
