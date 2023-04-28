//  xác định trọng tâm của tứ giác

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

	cout <<"\nXAC DINH TRONG TAM CUA TU GIAC\n";
	
	int xA, xB, xC, xD, yA, yB, yC, yD;
	cout <<"Nhap vao toa do diem A: ";
	cin >>xA>>yA;
	cout <<"Nhap vao toa do diem B: ";
	cin >>xB>>yB;
	cout <<"Nhap vao toa do diem C: ";
	cin >>xC>>yC;
	cout <<"Nhap vao toa do diem D: ";
	cin >>xD>>yD;
	
	double xE,xF,xG,xH,yE,yF,yG,yH;
	xE = 0.5*(xA+xB);
	xF = 0.5*(xC+xB);
	xG = 0.5*(xC+xD);
	xH = 0.5*(xA+xD);
	yE = 0.5*(yA+yB);
	yF = 0.5*(yC+yB);
	yG = 0.5*(yC+yD);
	yH = 0.5*(yA+yD);
	
	double xO,yO;
	
	if ((xE == xG)&&(yE == yG)) 
	{
		xO = xE;
		yO = yE;
	}
	else if ((xF == xH)&&(yF == yH))
	{
		xO = xF;
		yO = yF;
	}
	else 
	{
		double a1, b1, c1, a2, b2, c2;
		
		a1 = yG - yE;
		b1 = xE - xG;
		c1 = -xE*a1 -yE*b1;
		
		a2 = yH - yF;
		b2 = xF - xH;
		c2 = -xF*a2 -yF*b2;
		
		xO = (-c2*b1 +b2*c1)/(a2*b1 - a1*b2);
		if (b1!=0) yO = (-c1 -a1*xO)/b1;
		else yO = (-c2 - a2*xO)/b2;
			
	}
	
	printf ("\nToa do trong tam tu giac ABCD la\n(%.2f;%.2f)\n\n",xO,yO);
	
	return 0;
 }