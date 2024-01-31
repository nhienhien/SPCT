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
vector<vector<int>> inputVec;
bool sort1(vector<int> i, vector<int> j) {return(i[0]>j[0]);}
bool sort2(vector<int> i, vector<int> j) {return(i[1]>j[1]);}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int value = 0;
        vector<int> subVec;
        
        cin >> value;
        subVec.push_back(value);
        cin >> value;
        subVec.push_back(value);
        
        inputVec.push_back(subVec);
    }
}
void output() {
    cout << "=====" << endl;
    for (int i = 1; i <= N; i++) {
        cout << inputVec[i][0] << " " << inputVec[i][1] << endl;
    }
    
}
void solve() {
    sort(inputVec.begin(), inputVec.end(), sort2);
}
int main()
{
    inputVec.push_back({0,0});
    input();
    sort(inputVec.begin()+1, inputVec.end(), sort2);
    output();
    int st = 0;
    int en = 0;
    for (int i = 1; i < N; i++) {
        if (inputVec[i][1] != inputVec[i-1][1] && inputVec[i][1] == inputVec[i+1][1]) {
            st = i;
        } else if (inputVec[i][1] == inputVec[i-1][1] && inputVec[i][1] != inputVec[i+1][1]) {
            en = i;
        } else if (inputVec[i][1] == inputVec[i-1][1] && (i+1 == N)) {
            en = i + 1;
        }

        if (st != 0 && en != 0) {
            cout << "Sort: " << st << " " << en << endl;
            sort(inputVec.begin()+st, inputVec.begin() + en + 1, sort1);
            st = 0; en = 0;
        }
    }
    output();
    
    int sum = inputVec[1][0];
    int num = inputVec[1][1];
    int i = 2;
        while (num != 0 && i <= N) {
            sum += inputVec[i][0];
            num += inputVec[i][1] - 1;
            // cout << "i = " << i << " sum = " << sum << " num = " << num << endl;
            i++;
        }
    cout << sum;
    return 0;
}
