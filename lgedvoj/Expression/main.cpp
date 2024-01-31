#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
int k = 0;
vector<int> inputVec;
bool sortH2L(int i, int j) {return(i > j);}
void output() {
    cout << "=====" << endl;
    for (int i = 0; i < N; i++) {
        cout << inputVec[i] << " ";
    }
    cout << endl;
    
}
void input() {
    cin >> N; 
    cin >> k;
    int value;
    for (int i = 0; i < N; i++) {
        cin >> value;
        inputVec.push_back(value);  
    }

    sort(inputVec.begin() + 1, inputVec.end(), sortH2L);
    // output();
}

int main() {
    input();
    long int sum = inputVec[0];
    for (int i = 1; i < N; i++) {
        if (k > 0) {
            // cout << k << " " << sum << endl;
            sum += inputVec[i];
            k--;
        } else {
            // cout << k << " " << sum << endl;
            sum -= inputVec[i];
        }
        
    }
    cout << sum;
}