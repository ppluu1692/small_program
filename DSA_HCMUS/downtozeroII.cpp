#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

int A[1000001];

void dynamicArr() {
	for (int i = 1; i <= 1000000; i++)
	{
		int minPath = A[i-1]; 
		for (int j = (int)sqrt(i); j >= 2; j--) {
			if (i%j == 0)
				minPath = min(A[i/j], minPath);
		}
		A[i] = minPath+1;
	}
}

int downToZero(int n) {
    return A[n];
}

int main() {
	srand(time(NULL));
	A[0] = 0;
	A[1] = 1;
	dynamicArr();
	for (int i = 0; i < 1000; i++)
	{
		int k = (rand()*rand())%1000000;
		cout << k << " " << downToZero(k) << endl;
	}
	return 0;
}