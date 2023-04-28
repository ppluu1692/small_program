#include <iostream>
using namespace std;

int h(int k) {
	return k%11;
}

int linearH(int k, int i) {
	return (h(k) + i)%11;
}

int quadraticH(int k, int i) {
	return (h(k) + i*i)%11;
}

int doubleH(int k, int i) {
	return (h(k) + i*(k%9 + 1))%11;
}

int main() {
	// cout << h(26) << endl;
	// cout << h(42) << endl;
	// cout << h(5) << endl;
	// cout << h(44) << endl;
	// cout << h(92) << endl;
	// cout << h(59) << endl;
	// cout << h(40) << endl;
	// cout << h(36) << endl;
	// cout << h(12) << endl;
	while (true) {
		int k, i;
		cin >> k >> i;
		cout << doubleH(k, i) << endl;
	}
}