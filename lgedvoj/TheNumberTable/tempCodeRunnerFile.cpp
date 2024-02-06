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

int solve() {
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
    int result = solve();
    cout << result;
    return 0;
}