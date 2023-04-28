//thống kê

#include <iostream>
#include <conio.h>
#include <string>
#include <cmath>
#include <time.h>
using namespace std;

//hàm chuyển từ string sang number
int chuyen(string a)
{
    int result = 0;
    int n = a.length();
    for (int i = n - 1; i >= 0; i--)
    {
        result += pow(10, n - 1 - i) * (a[i] - 48);
    }
    return result;
}

//hàm xử lí string (mode1) sang array
void mode1(string source, int sub_data[100], int &n_data)
{
    source = source + " ";
    string part = "";
    int length = source.length();
    n_data = 0;
    for (int i=0; i < length; i++)
    {
        if ((source[i] == ' ') && (part.length() > 0))
        {
            sub_data[n_data] = chuyen(part);
            n_data++;
            part = "";
        }
        else if (source[i] != ' ')
            part = part + source[i];
    }
}

//hàm xử lí string (mode2) sang array
void mode2(string source, int sub_data[100], int sub_freq[100], int &n_data)
{
    source += " ";
    int length = source.length();
    string part = "";
    for (int i=0; i < length; i++)
    {
        if ((source[i] == ' ') && (part.length() > 0))
        {
            n_data++;
            if (n_data % 2 == 1)
            {
                sub_data[n_data / 2] = chuyen(part);
            }
            else if (n_data%2 ==0)
            {
                sub_freq[n_data / 2 - 1] = chuyen(part);
            }
            part = "";
        }
        else if (source[i] != ' ')
            part = part + source[i];
    }
    n_data = n_data/2;
}


//hàm sắp xếp mảng
void sapxep(int sorted_data[],int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j -1; i++)
        {
            if (sorted_data[i] > sorted_data[i+1])
            {
                int tam = sorted_data[i];
                sorted_data[i] = sorted_data[i+1];
                sorted_data[i+1] = tam;
            }
        }
    }
}
     
// #1 tìm tổng tần số (N)
int tong_tanso(int sub_freq[100])
{
    int n_phantu = 0;
    for(int i=0;i<100;i++)
    {
        if (sub_freq[i]!=0)
            n_phantu+=sub_freq[i];
    }
    return n_phantu;
}

// #2 tìm tổng các phần tử 
int sum_n(int sub_data[], int N)
{
    int sum =0;
    for (int i=0; i<N; i++)
    {
        sum += sub_data[i];
    }
    return sum;
}

//#3 tìm tổng các phần tử bình phương
int sum_n2(int sub_data[], int N)
{
    int sum =0;
    for (int i=0; i<N; i++)
    {
        sum += sub_data[i]*sub_data[i];
    }
    return sum;
}

//#4 tìm giá trị trung bình
double trbinh(int sub_data[], int N)
{
    return 1.0*sum_n(sub_data,N)/N;
}

//#5 tìm độ lệch chuẩn và độ lệch chuẩn không gian mẫu
void dolechchuan ( int sub_data[100], int sub_freq[100], double &lech_n, double &lech_n1 )
{
    double tb = trbinh(sub_data,sub_freq);
    double sum = 0;
    for (int i=0;i<100;i++)
    {
        for(int j=0;j<sub_freq[i];j++)
        {
            sum += pow((sub_data[i]-tb),2);
        }
    }
    lech_n = sqrt(1.0*sum/tong_tanso(sub_freq));
    lech_n1 = sqrt(1.0*sum/(tong_tanso(sub_freq)-1));
} 

//#6 tìm mode (Mo)
int Mo(int sub_freq[])
{
    int max = sub_freq[0];
    int index = 0;
    for (int i=1;i<100;i++)
    {
        if (sub_freq[i]>max)
        {
            max = sub_freq[i];
            index = i;
        }
    }
    return index;
}

//#7 tìm Med
double Med(int sub_sort[],int N)
{
    if (N%2 == 0)
        return 1.0*(sub_sort[N/2-1]+sub_sort[N/2])/2;
    else
        return sub_sort[N/2];
}

// chtrinh chính
int main()
{
    //1.chọn mode   
    cout << "TOÁN THỐNG KÊ\n\n";
    cout << "Mode 1: Không nhập tần số\n";
    cout << "Mode 2: Nhập tần số\n";
    cout << "Mode 3: Tạo ngẫu nhiên N số tự nhiên trên đoạn [a;b]\n";
    int mode;
    cin >> mode;
    // clrscr();
    
    //2.nhập dữ liệu theo kiểu string
    int data[100];
    int freq[100];
    int n = 0;
    int n_phantu = 0;
    string s = "";
    string gtri = "";
    
    if (mode == 1)
    {
        cout <<"\tx\n";
        while (gtri != "stop")
        {
            n ++;
            gtri = "";
            cout <<n<<".\t";
            cin >> gtri;
            if (gtri != "stop")
                s = s + gtri + " ";
        }
    }
    else if (mode == 2)
    {
        cout <<"\tx freq\n";
        while (gtri != "stop")
        {
            n ++;
            gtri = "";
            if (n%2 == 1)
                cout <<n/2+1<<".\t";
            cin >> gtri;
            if (gtri != "stop")
                s = s + gtri + " ";
        }
    }
    else if (mode == 3)
    {
        cout <<"Nhập N: (N<100) ";
        cin >>n;
        int a, b;
        cout <<"Nhập a, b: ";
        cin >>a >>b;
        b = b-a+1;
        srand((int)time(0));
        for (int i=0;i<n;i++)
        {
            data[i] = rand()%b+a;
            freq[i] = 1;
            cout <<data[i]<<"\t";
            if (i%5 == 4)
                cout <<endl;
        }
    }
    else return 0;
     //3.chuyển string sang array data và array freq
    if (mode == 1)
    {
        mode1 (s,data,n_phantu);
        n = n_phantu;
        for (int i=0;i<n;i++)
        {
            freq[i] = 1;
        }
    }
    else if (mode == 2)
    {
        mode2(s,data,freq,n_phantu);
        n = tong_tanso(freq);
    }
    else n_phantu = n;
    
    //4.tạo array sort gồm các phần tử được sắp xếp không giảm
    int sort[n];
    int count=0;
    for (int i=0;i<n_phantu;i++)
    {
        for (int j=0;j<freq[i];j++)
        {
            sort[count] = data[i];
            count ++;
        }
    }  
    sapxep (sort,n);     
    
    //5.chọn phép tính
    int option = 0;
    cout <<endl;
    cout <<"1.n\t2.Tb\n";
    cout <<"3.Σn\t4.Σn²\n";
    cout <<"5.σ_n\t6.s_n-1\n";
    cout <<"7.Mo\t8.Med\n";
    cout <<"9.Q1\t10.Q3\n";
    cout <<"11.Min\t12.Max\n";
    
    //6.thực hiện phép tính và lặp lại đến khi nhập sai option
    while (0) 
    {
    cout <<"\nNhập phép toán: ";
    cin >> option;
 
    double lech1,lech2;
    dolechchuan(data,freq,lech1,lech2);
    
    if (option ==1)
        printf ("n = %d",n);
    else if (option ==2)
        printf ("Tb = %f",trbinh(data,freq));
    else if (option ==3)
        printf ("Σn = %d",sum_n(data,freq));
    else if (option ==4)
        printf ("Σn² = %d",sum_n2(data,freq));
    else if (option ==5)
        printf ("σ_n = %f",lech1);
    else if (option ==6)
        printf ("s_n-1 = %f",lech2);
    else if (option ==7)
        cout<<"Mo = "<<data[Mo(freq)];
    else if (option ==8)
        printf ("Med = %.1f",Med(sort,n));
    else if (option ==9)
        printf ("Q1 = %d",sort[n/4-1]);
    else if (option ==10)
        printf ("Q3 = %d",sort[n-n/4+1]);
    else if (option ==11)
        printf ("Min = %d",sort[0]);
    else if (option ==12)
        printf ("Max = %d",sort[n-1]);
    else return 0;
    }       
    for (int i=0;i<n;i++)
    {
        cout <<sort[i]<<endl;
    }
    //cout <<Mo(freq);
    return 0;
}