/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
https://leetcode.com/problems/jump-game/
---
Return true if you can reach the last index, or false otherwise.
Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
---
Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> inputValue;
int N = 0;
int graph[10000][10000] = {};
bool visited[10000] = {};
int path[10000] = {};

void input() {
    int element = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> element;
        inputValue.push_back(element);
    }
}

void init() {
    (void)memset(visited, false, 10000);
    (void)memset(path, 0, 10000);
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < i + 1 + inputValue[i]; j++) {
            graph[i][j] = 1;
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

bool canJump(vector<int>& nums) {
    

    return 0;
}

int main() {

    input();
    init();
    cout << canJump(inputValue);
    return 0;
}
