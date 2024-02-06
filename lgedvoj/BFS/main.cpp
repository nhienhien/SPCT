/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;
int N = 0;
int numPath = 0;
bool inputVal[1000][1000] = {};
bool visited[1000] = {};

void input() {
    cin >> N >> numPath;
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < numPath; i++) {
        cin >> num1 >> num2;
        inputVal[num1][num2] = true;
        inputVal[num2][num1] = true;
    }
}

void bfs(int S) {
    queue<int> q;
    q.push(S);
    visited[S] = true;
    while(!q.empty()) {
        int topPre = q.front();
        // cout << topPre << " ";
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (inputVal[topPre][i] == true && visited[i] == false) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    input();
    int counter = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            bfs(i);
            counter++;
        }
    }
    // cout << endl;
    cout << counter;

    return 0;
}


