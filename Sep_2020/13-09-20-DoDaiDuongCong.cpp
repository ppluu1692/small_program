// bài toán tìm độ dài của một hàm số

#include <iostream>
#include <cmath>

using namespace std;

double fx(double x)
{
	return 2.0*x;
}

int main(int argc, char *argv[])
{
	cout <<"TIM DO DAI CUA DO THI HAM SO\n";
	int n(5000);
	
	cout <<"Nhap vao doan a, b: ";
	double a, b;
	cin >>a >>b;
	
	if (a>b) 
	{
		double tam = a;
		a = b;
		b = tam;
	}
	
	double s(0.0);
	
	if (a==b) 
		s = 0.0;
	else 
	{
		double d = (b-a)/n*1.0;
		for (int i=0; i<n; i++)
		{
			s+= sqrt(d*d + (fx(a+d*(i+1))-fx(a+d*i))*(fx(a+d*(i+1))-fx(a+d*i)));	
		}
	}
	
	cout <<"Do dai la: "<<s;
	
	return 0;		
	
}