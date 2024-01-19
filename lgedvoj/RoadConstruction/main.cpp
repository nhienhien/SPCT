#include <iostream>
#include <climits>
using namespace std;

const int row[4] = {0, 1, 0, -1};
const int column[4] = {1, 0, -1, 0};

int N;//Map Size
char map[110][110];//Map information
bool visited[110][110];
int d[110][110];

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
	}
}

void Init_Value(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            d[i][j] = INT_MAX;
        }
    }
}

bool Find_Min(int& xmin, int& ymin){
    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0 && min > d[i][j]) {
                min = d[i][j];
                xmin = i;
                ymin = j;
            }
        }
    }
    return (min != INT_MAX);
}

void Update_Value_Pos(int x, int y) {
    int nearX = 0;
    int nearY = 0;
    if (x == 1 && y == 0) {
        nearX++;
    }
    for (int i = 0; i < 4; i++) {
        nearX = x + row[i];
        nearY = y + column[i];
        if (nearX < 0 || nearX >= N || nearY < 0 || nearY >= N || visited[nearX][nearY]) continue;
        if (d[nearX][nearY] > d[x][y] + map[nearX][nearY] - '0') {
            d[nearX][nearY] = d[x][y] + map[nearX][nearY] - '0';
        }
    }
}

int main(){
	int ans = -1;
	Input_Data();		//	Input function
    Init_Value();
	//	Write the code
    d[0][0] = 0;
    while (true) {
        int xmin = 0;
        int ymin = 0;
        if (Find_Min(xmin, ymin) == 0 || (xmin == N-1 && ymin == N-1)) {
            cout << d[xmin][ymin];
            return 0;
        }
        visited[xmin][ymin] = true;
        Update_Value_Pos(xmin, ymin);
    }
	cout << ans << endl;	//	Output answer

	return 0;
}
