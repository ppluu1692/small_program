//chuyển từ 1 số thập phân sang 1 phân số tối giản

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

uint64_t UCLN(uint64_t a, uint64_t b)
{
	while (a!=b)
	{
		if (a>b) a = a-b;
		else b = b-a;
	}
	return a;
}

uint64_t BCNN(uint64_t a,uint64_t b)
{
    uint64_t greater = max(a, b);
    uint64_t smallest = min(a, b);
    for (uint64_t i = greater; ; i += greater) {
        if (i % smallest  == 0)
            return i;
    }
}

uint64_t luythua(uint64_t a, uint64_t b) {
	uint64_t result = 1;
	for (uint64_t i = 0; i < b; i++)
	{
		result *= a;
	}
	return result;
}

uint64_t chuyen(string a)
{
	uint64_t result =0;
	int n = a.length();
	for (int i =n-1; i>=0;i--)
	{
		result += luythua(10,n-1-i)*(a[i]-48);			
	}
	return result;
}

void docso(string str, bool& soam, uint64_t &ng,uint64_t &tp,uint64_t &th, int &dtp, int&dth)
{
	string strng = "";
	string strtp ="";
	string strth ="";
	
	int cham = 0;
	int ngoac = 0;
	int dk = 0;

	soam = false;
	if (str[0] == '-') {
		soam = true;
		str.erase(0, 1);
	}

	int length = str.length();
	
	for (int i = 0; i<length; i++)
	{
		if (str[i]=='.')
		{
			dk = 1;
			cham = i;
			i++;
		}
		if (str[i]=='(')
			{
				dk = 2;
				ngoac = i;
				i++;
			}
		if (str[i]==')')
			dk = 3;
	
		if (dk == 0)
		{
			strng+= str[i];
		
		}
		else if (dk ==1) 
		strtp += str[i];
		else if (dk==2)
		strth += str[i];
	}
	ng = chuyen(strng);
	tp = chuyen(strtp);
	th = chuyen(strth);
	dtp = strtp.length();
	dth = strth.length();
}

int dodaiso (int n)
{
	if (n ==0 )
		return 1;
	else
	{
		int a;
		a = ceil(log(n+1e-9)/log(10));		return a;
	}	
}

int main(int argc, char *argv[])
{	
	cout <<"DOI TU SO THAP PHAN SANG PHAN SO\n\n";
	cout <<"Nhap vao mot so thap phan\n";
	cout <<"VD: 0.25-->0.25/.25 1.4323232...-->1.4(32)\n";
	string s = "";
	cin >>s;
	bool soam = false;
	uint64_t tsnguyen(0);
	uint64_t tsthapphan(0);
	uint64_t tstuanhoan(0);
	int dtp(0);
	int dth(0);
	
	docso (s, soam, tsnguyen,tsthapphan, tstuanhoan,dtp,dth);
	//////////////////////////////////////////////
	// cout << tsnguyen << " " << tsthapphan << " " << tstuanhoan << endl;
	// cout << dtp << " " << dth << endl;
	///////////////////////////////////////
	uint64_t msnguyen = 1;
	uint64_t msthapphan = luythua(10,dtp);
	uint64_t mstuanhoan = (luythua(10,dth)-1)*pow(10,dtp);
	if (mstuanhoan ==0 )
		mstuanhoan = 1;
	uint64_t mauchung = BCNN(BCNN(msnguyen,msthapphan),mstuanhoan);
	
	//tusonguyen sẽ dùng để lưu tử số của kết quả
	//mausonguyen sẽ dùng để lưu UCLN của phân số kq
	tsnguyen = tsnguyen*(mauchung/msnguyen)+tsthapphan*(mauchung/msthapphan)+tstuanhoan*(mauchung/mstuanhoan);
	msnguyen = UCLN(tsnguyen,mauchung);
	tsnguyen = tsnguyen / msnguyen;
	mauchung = mauchung / msnguyen;
	double heso = 1.0;
	if (soam) {
		cout << '-';
		heso *= -1;
	}
	cout << tsnguyen<<'/'<<setprecision(12)<<mauchung<<" ~ "<<heso*tsnguyen/mauchung;


	
	return 0;	
}