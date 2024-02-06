#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int M = 0;
int N = 0;
int K = 0;
void input() {
    cin >> M >> N >> K;
}

long int solve() {
    int counter = 0;
    int num = 2;
    int first = 0;
    int second = 0;
    while (counter < K) {
        first = num/2;
        second = num - first;
        // cout << first << " " << second << endl << "=====" << endl;
        while (first > 0 && second < num && counter < K) {
            if (first <= M && second <= N) {
                counter++;
                // cout << "Choose: " << first << " " << second << " " << counter << endl;
            }
            if (first != second && first <= N && second <= M) {
                counter++;
                // cout << "Choose: " << second << " " << first << " " << counter << endl;
            }
            first--;
            second++;
            // cout << first << " " << second << " " << counter << endl;
        }
        num++;
    }
    first++;
    second--;
    return (first*first + second*second);
}

int main() {
    input();
    long int result = solve();
    cout << result;
    return 0;
}

/*
10 100000000 490016301
2401159840660162
31623 31623 417949255
532178980
100000000 10 463363114
2147053809761360
*/