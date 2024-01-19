#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<int> result;

bool isSubstring(string inp) {
    int size = inp.size();
    if (size == 1) {
        if (inp[0] == 'a' || inp[0] == 'b' || inp[0] == 'c') return true;
        else return false;
    }
    if (size == 2) {    
        if (inp == "ab" || inp == "bc" || inp == "ca") return true;
        else return false;
    }
    for (int i = 0; i < size; i++) {
        if (inp[i] != 'a' && inp[i] != 'b' && inp[i] != 'c') return false;
    }
    for (int i = 0; i < size - 2; i++) {
        if (inp[i] == 'a' && (inp[i+1] != 'b' || inp[i+2] != 'c')) return false;
        if (inp[i] == 'b' && (inp[i+1] != 'c' || inp[i+2] != 'a')) return false;
        if (inp[i] == 'c' && (inp[i+1] != 'a' || inp[i+2] != 'b')) return false;
    }
    return true;
}

void input() {
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        result.push_back(isSubstring(s));
    }
}

int main() {
    input();
    for (int i = 0; i < N; i++) {
        if (result[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}