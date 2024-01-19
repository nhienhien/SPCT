#include <iostream>
#include <queue>
using namespace std;
#define MAX_ARRAY 100
int T;
int N;
int arr[MAX_ARRAY][MAX_ARRAY] = {0};
int visited[MAX_ARRAY] = {0};

void InputData() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for(int j = 1; j < N; j++) {
            int numkey = 0;
            cin >> numkey;
            for (int k = 1; k <= numkey; k++) {
                int poskey = 0;
                cin >> poskey;
                arr[j][poskey] = 1;
                // cout << " i = " << i << " " << "j = " << j << " " << "k = " << k << " N = " << N << " " << arr[k][poskey] << endl;
            }

        }
    }

    for (int i = 1; i <= 5; i++) {
        cout << arr[i][1] << " "<< arr[i][2] << " "<< arr[i][3] << " "<< arr[i][4] << " "<< arr[i][5] << endl;
    }
}

void BFS(int startPos) {
    visited[startPos] = 1;
    queue<int> queuePos;
    queuePos.push(startPos);

    while (queuePos.size() > 0) {
        int front = queuePos.front();
        queuePos.pop();
        visited[front] = 1;
        for (int i = 1; i <= N; i++) {
            if (visited[i] == 0 && arr[front][i] == 1) {
                queuePos.push(i);
                visited[i] = 1;
            }
        }
        
    }
}

int main() {
    InputData();
    return 0;
}