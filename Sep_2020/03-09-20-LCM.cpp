// bài toán tìm bội chung nhỏ nhất
// phương pháp: tích hai số chia cho UCLN
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "TIM BOI CHUNG NHO NHAT\n";
	
	int a,b;
	a = 1;
	b = 1;
	
	cout << "Nhap vao hai so a, b: ";
	cin >>a >>b;
	
	int m = a;
	int n = b;
	
	///tìm UCLN
	while (m != n) 
	{
		if (m>n) m = m-n;
		else n = n-m;
	}
	
	int BCNN = (a*b)/m;
	
	printf ("Boi chung nho nhat cua %d va %d la %d." ,a,b,BCNN);
	
	return 0;
}