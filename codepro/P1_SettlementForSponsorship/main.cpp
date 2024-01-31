#include <iostream>
using namespace std;

long int N;//Number of sponsored goods
long int D[100000 + 10];//Preference
long int sol = -30001;//Maximum preference of the first method

void InputData(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> D[i];
	}
}

void Solve()
{
	int i, sum = 0;
	for (i = 1; i < N; i++) {
		D[i] = max(D[i-1] + D[i], D[i]);
		sum = D[i];
		// cout << sum << endl;
		if (sum > sol) sol = sum;
	}
}


int main(){
	InputData();//Input function
	Solve();
	cout << sol << endl;//Output
	return 0;
}
