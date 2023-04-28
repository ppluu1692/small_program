//tính đạo hàm của hàm số tại một điểm

#include <iostream>
#include <cmath>

using namespace std;

double fx(double x)
{
	return 2*x/(x+1);
}

int main(int argc, char *argv[])
{
	cout <<"TINH DAO HAM TAI DIEM\n\n";
	
	cout <<"Nhap vao diem: ";
	double a;
	cin >>a;
	
	double delta = 1E-9;
	
	double phai, trai;
	phai = (fx(a+delta)-fx(a))/delta;
	trai = (fx(a-delta)-fx(a))/-delta;
	
	if (abs(trai - phai) < 1e-5)
		cout <<"Dao ham tai diem "<<a<<" la "<<0.5*(phai+trai);
	else cout <<"Khong co dao ham tai diem "<<a;
	
	return 0;	
	
}