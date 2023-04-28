#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <chrono>
#include <time.h>
#include <ctime>
using namespace std;

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(vector<int>& vt, int n)
{
	srand((unsigned int)time(0));

	for (int i = 0; i < n; i++)
	{
		int x = rand() % n;
		vt.push_back(x);
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(vector<int>& vt, int n)
{
	for (int i = 0; i < n; i++)
	{
		vt.push_back(i);
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(vector<int>& vt, int n)
{
	for (int i = 0; i < n; i++)
	{
		vt.push_back(n - 1 - i);
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(vector<int>& vt, int n)
{
	for (int i = 0; i < n; i++)
	{
		vt.push_back(i);
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(vt[r1], vt[r2]);
	}
}

void GenerateData(vector<int>& vt, int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(vt, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(vt, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(vt, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(vt, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

void selectionSort(vector<int>& vt)
{
	int n = vt.size();
    for (int i = 0; i < n-1; i++)
    {
        int iMin = i;
        for (int j = i+1; j < n; j++)
        	if (vt[j] < vt[iMin])
            	iMin = j;
        swap(vt[i], vt[iMin]);
    }
}

void insertionSort(vector<int>& vt)
{
	int n = vt.size();
    for (int i = 1; i < n; i++)
    {
        int key = vt[i];
        int j = i - 1;
        while (j >= 0 && vt[j] > key)
        {
            vt[j + 1] = vt[j];
            j = j - 1;
        }
        vt[j + 1] = key;
    }
}

void bubbleSort(vector<int>& vt)
{
    int n = vt.size();
    for (int i = 0; i < n-1; i++)    
		for (int j = 0; j < n-i-1; j++)
			if (vt[j] > vt[j+1])
				swap(vt[j], vt[j+1]);
}

void merge(vector<int>& vt, int l, int m, int r) {

	vector<int> temp;

	int i, j;
	i = l;
	j = m + 1;

	while (i <= m && j <= r) {

		if (vt[i] <= vt[j]) {
			temp.push_back(vt[i]);
			++i;
		}
		else {
			temp.push_back(vt[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(vt[i]);
		++i;
	}

	while (j <= r) {
		temp.push_back(vt[j]);
		++j;
	}

	for (int i = l; i <= r; ++i)
		vt[i] = temp[i - l];

}

void mergeSort(vector<int>& vt, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(vt, l, m);
		mergeSort(vt, m + 1, r);
		merge(vt, l, m, r);
	}
}

int partition (vector<int>& vt, int l, int r)
{
    int pivot = vt[r];   
    int i = (l - 1);  
 
    for (int j = l; j <= r- 1; j++)
    {
        if (vt[j] <= pivot)
        {
            i++;  
            swap(vt[i], vt[j]);
        }
    }
    swap(vt[i + 1], vt[r]);
    return (i + 1);
}

void quickSort(vector<int>& vt, int l, int r)
{
    if (l < r)
    {
        int pivot = partition(vt, l, r);
 
        quickSort(vt, l, pivot - 1);
        quickSort(vt, pivot + 1, r);
    }
}

void heapify(vector<int>& vt, int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && vt[l] > vt[largest])
        largest = l;
 
    if (r < n && vt[r] > vt[largest])
        largest = r;

    if (largest != i) {
        swap(vt[i], vt[largest]);
        heapify(vt, n, largest);
    }
}
 
void heapSort(vector<int>& vt)
{
    int n = vt.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vt, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(vt[0], vt[i]);
        heapify(vt, i, 0);
    }
}

void printArr(vector<int> vt) {
    for (auto element : vt) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    vector<int> myVec;
    GenerateData(myVec, 100, 0);
    printArr(myVec);
    auto millisec_since_epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    auto sec_since_epoch = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();

    cout << "seconds since epoch: " << sec_since_epoch << endl;
    cout << "milliseconds since epoch: " << millisec_since_epoch << endl;
    bubbleSort(myVec);
    printArr(myVec);
    return 0;
}