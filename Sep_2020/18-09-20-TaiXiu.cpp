//game tài xỉu

#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

int main()
{
	cout <<"GAME TAI XIU\n\n";
	cout <<"1.Tai\t2.Xiu\n";
	int selection;
	cin >>selection;
	
	printf("\b\b\b");
	if (selection==1)
		printf("Ban chon: Tai\n");
	if (selection==2)
		printf("Ban chon: Xiu\n");
	
	int xx1,xx2,xx3;
	srand((int)time(0));
	xx1 = rand()%6 +1;
	xx2 = rand()%6 +1;
	xx3 = rand()%6 +1;
	
	printf ("%d %d %d\n",xx1, xx2, xx3);
	
	int tong = xx1+xx2+xx3;
	printf ("Tong: %d\n",tong);
	tong = tong%2;
	selection--;
	if (selection==tong)
		printf ("\nChuc mung, ban da thang");
	else printf ("\nBan da thua");
	return 0;
}