#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int T = 0;
string s = "";
vector<int> inputConvert1;
vector<int> inputConvert2;
vector<bool> result;
int convertStr(string s);
int compare(int n);
bool myfunction (int i,int j) { return (i<j); }
void input() {
    cin >> T;
    int n = 0;
    for (int i = 0; i < T; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> s;
            inputConvert1.push_back(convertStr(s));
            // cout << s << " - " << convertStr(s);
        }
        // cout << endl;
        sort(inputConvert1.begin(), inputConvert1.end(), myfunction);
        // for (int a = 0; a < n; a++) {
        //     cout << inputConvert1[a] << " ";
        // } cout << endl;
        for (int j = 0; j < n; j++) {
            cin >> s;
            inputConvert2.push_back(convertStr(s));
            // cout << s << " - " << convertStr(s);
        }
        // cout << endl;
        sort(inputConvert2.begin(), inputConvert2.end(), myfunction);
        // for (int a = 0; a < n; a++) {
        //     cout << inputConvert2[a] << " ";
        // } cout << endl;
        (int)compare(n);

        inputConvert1.erase(inputConvert1.begin(), inputConvert1.end());
        inputConvert2.erase(inputConvert2.begin(), inputConvert2.end());
    }
}

int convertStr(string s) {
    int result = 0;
    switch (s[0]){
        case 'R':
            result = 100; break; 
        case 'Y':
            result = 200; break;
        case 'B':
            result = 300; break; 
    }
    result += s[1] - '0';
    return result;
}

int compare(int n) {
    for (int i = 0; i < n; i++) {
        if (inputConvert1[i] != inputConvert2[i]) {
            result.push_back(false);
            // cout << "failed" << endl;
            return 0;
        }
    }
    result.push_back(true);
    // cout << "true" << endl;
    return 1;
}

int main() {
    input();
    for (int i = 0; i < T; i++) {
        if (result[i] == true) cout << "NOT CHEATER" << endl;
        else cout << "CHEATER" << endl;
    }
    return 0;
}