/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int M = 0;
int N = 0;
bool inputArr[250][250] = {};
bool visited[250][250] = {};
int r[4] = {-1, 0, 1, 0};
int c[4] = {0, 1, 0, -1};

bool sortL2H(int i, int j) {return(i<j);}

typedef struct {
    int posx;
    int posy;
} POS;

void init() {
    M = 0;
    N = 0;
    for (int i = 0; i < 250; i++) {
        for (int j = 0; j < 250; j++) {
        inputArr[i][j] = false;
        visited[i][j] = false;
        }
    }
}

void input() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inputArr[i][j];
        }
    }
}
int size = 0;

void bfs(int i, int j) {
    size = 1;
    POS p = {i,j};
    queue<POS> q;
    q.push(p);
    visited[p.posx][p.posy] = true;
    while (!q.empty()) {
        POS pos = q.front();
        q.pop();
        for (int si = 0; si < 4; si++) {
            int newx = pos.posx + r[si];
            int newy = pos.posy + c[si];
            if (newx < 0 || newx >= M || newy < 0 || newy >= N) {
                continue;
            } else {
                if (inputArr[newx][newy] == 1 && visited[newx][newy] == false){
                    q.push({newx, newy});
                    visited[newx][newy] = true;
                    size++;
                }
            }
            // bfs(newx, newy);
        }
    }
}

int main()
{
    while(1) {
        input();
        if (M == 0 && N == 0) return 0;
        if (M != 0 && N != 0) {
            vector<int> result;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (inputArr[i][j] && visited[i][j] == false) {
                        size = 0;
                        bfs(i, j);
                        result.push_back(size);
                        // cout << size << endl;
                    }
                }
            }
            
            cout << result.size() << endl;
            sort(result.begin(), result.end(), sortL2H);
            int pre = result[0];
            int number = 0;
            for (int i = 0; i <= result.size(); i++) {
                
                if (result[i] == pre) {
                    number++;
                } else {
                    cout << pre << " " << number << endl;
                    pre = result[i];
                    number = 1;
                }
            }
            init();
        }
    }
}
/*
10 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 1 1 1
1 1 0 0 1 0 0 1 1 1
1 0 1 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1

7
1 2
2 1
6 1
10 2
20 1
*/

