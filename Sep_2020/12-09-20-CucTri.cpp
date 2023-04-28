//tìm cực tiểu, cực đại của hàm số

#include <iostream>
#include <cmath>

using namespace std;

double fx(double x)
{
	return (x*x*x -2*x*x +2.0)/(exp(-2*x)+4);
}

int main(int argc, char *argv[])
{
	cout <<"TIM CUC DAI, CUC TIEU CUA HAM SO\n";
	int n = 5000;
	
	cout <<"Nhap doan can xac dinh: ";
	double a,b;
	cin >>a>>b;

	if (a>b)
	{
		double tam = a;
		a = b;
		b = tam;
	}
	
	double x = a;
	double y = fx(a);
	
	if (a==b)
		cout<<"Nhap bay!";
	else 
	{
		double d = (b-a)/n;
		for (int i = 1; i<n; i++)
		{
			if (fx(a+d*i) > fx(a+d*(i-1)) && fx(a+d*i) > fx(a+d*(i+1)))
				cout <<"Cuc dai: ("<<a+d*i<<";"<<fx(a+d*i)<<").\n";
			if (fx(a+d*i) < fx(a+d*(i-1)) && fx(a+d*i) < fx(a+d*(i+1)))
				cout <<"Cuc tieu: ("<<a+d*i<<";"<<fx(a+d*i)<<").\n";
					
		}	
	}
	
	return 0;
		
}