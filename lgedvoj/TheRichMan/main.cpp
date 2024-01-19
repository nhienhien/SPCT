#include<vector>
#include<iostream>
using namespace std;
int N = 45;
int Money[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
int NumBill[9] = {4, 1, 5, 30, 5, 1, 1, 1, 1};
int Bill[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
void input() {
    for (int i = 0; i < 9; i++) {
        cin >> NumBill[i];
    }
    cin >> N;
}

void solve() {
    int checknearsum = 0;
    int i = 0;
    int surplus = 0;
    for (i = 0; i < N; i++) {
        if (checknearsum + Money[i]*NumBill[i] < N) {
            checknearsum += Money[i]*NumBill[i];
        } else if (checknearsum + Money[i]*NumBill[i] > N) {
            for (int j = 1; j <= NumBill[i]; j++) {
                if (checknearsum + Money[i]*j > N) {
                    surplus = checknearsum + Money[i]*j - N;
                    break;
                }
            }
            if (surplus != 0) break;
        }        
    }
    cout << surplus << " " << i << endl;
    // while (checknearsum != N) {
    //     int decrease = 0;
    //     bool checkResult = false;
    //     while (checknearsum > N) {
    //         decrease++;
    //         checknearsum -= Money[i]*decrease;
    //         Bill[i] -= decrease;
    //     }
    // }
    
}

int main() {
    solve();
    return 0;
}