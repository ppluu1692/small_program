// tính thể tích của một tứ diện với toạ độ của 4 đỉnh

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	cout <<"TINH DIEN TICH CUA MOT TU DIEN VOI TOA DO CUA 4 DINH\n";
	
	cout <<"                    x y z\n";
	
	cout <<"Nhap toa do diem A: ";
	int A[3];
	cin >>A[0]>>A[1]>>A[2];
	
	cout <<"Nhap toa do diem B: ";
	int B[3];
	cin >>B[0]>>B[1]>>B[2];
	
	cout <<"Nhap toa do diem C: ";
	int C[3];
	cin >>C[0]>>C[1]>>C[2];
	
	cout <<"Nhap toa do diem D: ";
	int D[3];
	cin >>D[0]>>D[1]>>D[2];
	
	double vtn[3];
	vtn[0] = (B[1] - A[1])*(C[2] - A[2]) - (C[1] - A[1])*(B[2] - A[2])*1.0;
	vtn[1] = (B[2] - A[2])*(C[0] - A[0]) - (C[2] - A[2])*(B[0] - A[0])*1.0;
	vtn[2] = (B[0] - A[0])*(C[1] - A[1]) - (C[0] - A[0])*(B[1] - A[1])*1.0;
	
	double a,b,c,d;
	a = vtn[0];
	b = vtn[1];
	c = vtn[2];
	d = -a*A[0] - b*A[1] - c*A[2];
	
	double AB, AC, BC;
	AB = sqrt((B[0]-A[0])*(B[0]-A[0]) + (B[1]-A[1])*(B[1]-A[1]) + (B[2]-A[2])*(B[2]-A[2]));
	AC = sqrt((C[0]-A[0])*(C[0]-A[0]) + (C[1]-A[1])*(C[1]-A[1]) + (C[2]-A[2])*(C[2]-A[2]));
	BC = sqrt((B[0]-C[0])*(B[0]-C[0]) + (B[1]-C[1])*(B[1]-C[1]) + (B[2]-C[2])*(B[2]-C[2]));
	
	double sday, p;
	p = 0.5*(AB + AC + BC);
	sday = sqrt(p*(p-AB)*(p-AC)*(p-BC));
	
	double h;
	h = abs(a*D[0] + b*D[1] + c*D[2] + d)/sqrt(a*a + b*b + c*c)*1.0;
	
	double V;
	V = sday*h/3.0;
	
	cout <<"The tich cua tu dien la: "<<V;
	
	return 0;
	
}
