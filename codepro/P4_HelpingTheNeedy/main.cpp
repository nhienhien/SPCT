#include <iostream>
using namespace std;

int N = 45;//The number of goods to send 
int NumGoods[10] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
int C[10] = {15,6,6,3,2,2,2,2,2,1};//The number of BOXes(in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10];//The number of boxes to send

void InputData(){
	int i;
	cin >> N;
	for(i = 0; i < 10; i++){
		cin >> C[i];
	}
}

void fixPack(int& idx, int& oddment) {

}

bool checkPack(int& idxC, int& oddment) {
    int multiple = NumGoods[idxC] * C[idxC];
    if (multiple == oddment) {
        oddment = 0;
        return true;
    }
    while (multiple < oddment) {
        oddment -= NumGoods[idxC] * C[idxC];
        idxC++;
    }
    if (NumGoods[idxC] * C[idxC] > oddment)
        return false;      
    return true;
}

void OutputData(int ans){
	int i;
	cout << ans << endl;
	for(i = 0; i < 10; i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}
int main(){
	int ans = -1;
    int index = 0;
    int Oddment = N;
	// InputData();//	Input function
    cout << checkPack(index, Oddment) << " " << index << " " << Oddment;
	//	Create the code
    if (checkPack(index, Oddment) == 1 && Oddment != 0) {
        for (int i = 0; i < )
    }

	// OutputData(ans);//	Output function

	return 0;
}