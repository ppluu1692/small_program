//base-N

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

string doicoso(string &coso, int ds)
{
    string kq = "";
    int cs = coso.length();
    int count = 0;
    while (ds > 0)
    {
        kq = kq + coso[ds % cs];
        ds = ds / cs;
        count++;
    }
    string kq1 = kq;
    for (int i = 0; i < count; i++)
    {
        kq1[i] = kq[count - i - 1];
    }

    return kq1;
}

int main()
{
    do
    {
        cout << "DOI CO SO\n\n";
        cout << "Nhap vao 1 so: ";
        int dec;
        cin >> dec;
        string bin = "01";
        string oct = "01234567";
        string hex = "0123456789ABCDEF";
        char selection;
        cout << "1.BIN\t2.OCT\t3.HEX\n";
             cout << "Nhap b de quay lai, nhap ! de ket thuc ";
        do
        {
             cin >> selection;
             cout <<"\b";
             if (selection == '1')
                 cout <<"BIN: "<<doicoso(bin,dec)<<"\n\n\n";
             if (selection == '2')
                 cout <<"OCT: "<<doicoso(oct,dec)<<"\n\n\n";
             if (selection == '3')
                 cout <<"HEX: "<<doicoso(hex,dec)<<"\n\n\n";
             if (selection =='!')
                 return 0;
        }
        while (selection != 'b');
        system("cls");
    }
    while (1);
    return 0;
}