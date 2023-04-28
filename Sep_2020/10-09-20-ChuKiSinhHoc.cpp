//chu kì sinh học của con người

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	int days[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	cout << "Nhap ngay, thang, nam sinh: ";
	int d1, m1, y1;
	cin >> d1 >> m1 >> y1;

	cout << "Nhap ngay, thang, nam hien tai: ";
	int d2, m2, y2;
	cin >> d2 >> m2 >> y2;

	unsigned s, s1, s2, snn;

	s1 = y1 - 1 - 1900;
	snn = s1 / 4;
	s1 = s1 * 365 + snn;
	s1 = s1 + days[m1] + d1;

	s2 = y2 - 1 - 1900;
	snn = s2 / 4;
	s2 = s2 * 365 + snn;
	s2 = s2 + days[m2] + d2;

	s = s2 - s1;

	int theluc = s % 23;
	int tritue = s % 27;
	int camxuc = s % 33;

	double pctl = sin(theluc / 23.0 * 2 * 3.1415926) * 100;
	double pctt = sin(tritue / 27.0 * 2 * 3.1415926) * 100;
	double pccx = sin(camxuc / 33.0 * 2 * 3.1415926) * 100;
	char pc = '%';

	printf("Ngay %d thang %d nam %d:\n", d2, m2, y2);
	printf("Ngay thu %d (%.0f%c) cua chu ki the luc.\n", theluc, pctl,pc);
	printf("Ngay thu %d (%.0f%c) cua chu ki tri tue.\n", tritue, pctt,pc);
	printf("Ngay thu %d (%.0f%c) cua chu ki cam xuc.\n", camxuc, pccx,pc);
	return 0;
}