#include <iostream>
#include <vector>
using namespace std;

int N = 0;//Number of mushrooms
int P[150000 + 10] = {};//Mushroom value
vector<int> plusArr;
vector<int> subArr;
void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

int main(){
	int ans = 0;

	InputData();
    if (N == 1) {
        cout << P[0];
        return 0;
    }		//	Input function
    bool plus = true;
    if (P[0] > P[1]) {
        plusArr.push_back(P[0]);
        plus = false;
    }
	//	Write the code
    
    for (int i = 1; i < N; i++) {
        if (P[i] > P[i - 1] && plus == true) {
            if (i == N-1) {
                
            }
            while (P[i] == P[i + 1]) {
                i++;
            }
            if (P[i] > P[i + 1]) {
                // cout << " + " << P[i];
                plusArr.push_back(P[i]);
                plus = false;
            }
        }

        if (P[i] < P[i - 1] && plus == false) {
            while (P[i] == P[i + 1]) {
                i++;
            }
            if (P[i] < P[i + 1]) {
                // cout << " - " << P[i];
                subArr.push_back(P[i]);
                plus = true;
            }
        }
    }
    
    for (int i = 0; i < plusArr.size(); i++) {
        ans += plusArr[i];
    }
    for (int i = 0; i < subArr.size(); i++) {
        ans -= subArr[i];
    }
    cout << ans;
	return 0;
}
