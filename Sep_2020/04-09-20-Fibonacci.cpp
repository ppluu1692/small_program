//in n số đầu tiên của dãy Fibonacci

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	cout <<"IN n SO DAU CUA DAY FIBONACCI\n";

	cout <<"Nhap vao so n (n<30): ";
	int n(1);
	cin >> n;
	
	int tr(1);
	int sau(1);
	int tam(0);
	
	for (int i = 0 ; i<n ; i++)
	{
		if (i%5 == 0) cout <<'\n';
		cout <<tr <<'\t';
		tam = sau;
		sau = sau + tr;
		tr = tam;
	}	
	return 0;	
}