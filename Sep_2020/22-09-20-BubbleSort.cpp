//bubble sort

#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

int main()
{
    int n = 1000;
    int mang[n];
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        mang[i] = rand() % 999 + 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%4d", mang[i]);
        if (i % 10 == 9)
        {
            cout << endl;
            // usleep(100000);
        }
    }
    cout << "\n";
    cout << "--------------------------------------\n";

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j -1; i++)
        {
            if (mang[i] > mang[i + 1])
            {
                int tam = mang[i];
                mang[i] = mang[i + 1];
                mang[i + 1] = tam;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%4d", mang[i]);
        if (i % 10 == 9)
        {
            cout << endl;
            // usleep(100000);
        }
    }

    return 0;
}