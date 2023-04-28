// giải phương trình bậc nhất hai ẩn

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	
	cout << "GIAI HE PHUONG TRINH BAC NHAT HAI AN\n\n";
	cout << "a1x + b1y = c1\n";
	cout << "a2x + b2y = c2\n\n";
	
	double a1, b1, c1, a2, b2, c2;

	cout << "a1: ";
	cin >> a1;
	cout << "b1: ";
	cin >> b1;
	cout << "c1: ";
	cin >> c1;
	cout << "a2: ";
	cin >> a2;
	cout << "b2: ";
	cin >> b2;
	cout << "c2: ";
	cin >> c2;

	double x, y;
	int k;

	if ((a2 * b1 - a1 * b2) != 0)
	{
		k = 1;
		x = (c2 * b1 - b2 * c1) / (a2 * b1 - a1 * b2);
		if (b1 != 0)
			y = (c1 - a1 * x) / b1;
		else
			y = (c2 - a2 * x) / b2;
	}
	else if ((a2 * c1 - a1 * c2) != 0)
		k = 0;
	else
		k = 2;

	if (k == 0)
		cout << "\nHe phuong trinh vo nghiem";
	if (k == 1)
		printf("\nHe phuong trinh co mot nghiem duy nhat:\nx = %.2f\ty = %.2f", x, y);
	if (k > 1)
		printf("\nHe phuong trinh co vo so nghiem");

	return 0;
}
