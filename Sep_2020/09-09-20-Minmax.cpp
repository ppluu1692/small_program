// tìm giá trị lớn nhất và nhỏ nhất trên một đoạn của một hàm số liên tục trên đoạn đó

#include <iostream>
#include <cmath>


using namespace std;

double fx(double x)
{
	return x*x + 2;
}

int main(int argc, char *argv[])
{
	cout <<"XAC DINH GIA TRI\nLON NHAT VA NHO NHAT TREN MOT DOAN\nCUA MOT HAM SO LIEN TUC TREN DOAN DO\n";
	
	cout <<"Nhap khoang: ";
	double a, b;
	cin >>a >>b;

	int n(1000);
	double min = fx(a);
	double max = min;
	
	if (a==b)
	{
		min = fx(a);
		max = min;
	}

	else {
		if (a>b) 
		{
			double tam = a;
			a = b;
			b = a;
			min = fx(a);
			max = min;
		}

		double d = (b-a)/n;
		for (int i=0; i<=n; i++)
		{
			if (fx(a+d*i)<min)
				min = fx(a+d*i);
			if (fx(a+d*i)>max)
				max = fx(a+d*i);
		}
	}
	
	printf ("\n-->Gia tri lon nhat cua f(x)\ntren [%.2f; %.2f] la %.2f",a,b,max);
	printf ("\n\n-->Gia tri nho nhat cua f(x)\ntren [%.2f; %.2f] la %.2f",a,b,min);	
	
	return 0;	
		
}