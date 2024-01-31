#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N; // Number of executable code data
int M; // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10]; // Virus data

int sol; // Correct answer

void InputData(void)
{
	int i;

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (i = 0; i < M; i++) {
		cin >> B[i];
	}
	sort(B, B + M);
}

void OutputData(void)
{
	cout << sol;
}
int Find(int start, int* arr)
{
	int i;
	
	sort(arr,arr + M);
	int dis = B[0] - arr[0];
	for (i = 0; i < M; i++) {
		if (B[i] - arr[i] != dis) return 0;
	}
	return 1;
}

void Solve(void)
{
	int i;
	for (i = 0; i <= N - M; i++) {
		int arr[M] = {};
		copy(A+i, A+i+M, arr);
		sol += Find(i, arr);
	}
}

int main(void)
{
	InputData(); // Input

	Solve(); // Problem solving

	OutputData(); // Output

	return 0;
}
