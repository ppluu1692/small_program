//rút gọn phân số

#include <iostream>
using namespace std;
int UCLN(int a,int b)
{
	while (a!=b)
	{
		if (a>b) a = a-b;
		else b = b-a;
	}
	return a;
}

int BCNN(int a,int b)
{
	return (a*b)/UCLN(a,b);
}
int main()
{
	cout <<"RUT GON PHAN SO\n\n";
	cout <<"Nhap tu so: ";
	int ts;
	cin >>ts;
	cout <<"Nhap mau so: ";
	int ms;
	cin >>ms;
	
	int k = UCLN(ts,ms);
	ts = ts/k;
	ms = ms/k;
	
	printf ("%d/%d = %d/%d",ts*k,ms*k,ts,ms);
	return 0;
	
}