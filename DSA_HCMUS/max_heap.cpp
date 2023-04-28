#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void makeTrueValue(int arr[], int n, int internal) {
    int childL = 2*internal + 1;
    int childR = 2*internal + 2;
    if (childL >= n)
        return;
    if (childR >= n) {
        if (arr[childL] > arr[internal]) {
            swap(arr[childL], arr[internal]);
            makeTrueValue(arr, n, childL);
        }
    }
    else {
        if (arr[childL] >= arr[childR]) {
            if (arr[childL] > arr[internal]) {
                swap(arr[childL], arr[internal]);
                makeTrueValue(arr, n, childL);
            }
        }
        else {
            if (arr[childR] > arr[internal]) {
                swap(arr[childR], arr[internal]);
                makeTrueValue(arr, n, childR);
            }
        }
    }
}

void maxHeap(int arr[], int n) {
    for (int i = (n-2)/2; i >= 0; i--)
    {
        makeTrueValue(arr, n, i);
    }
}

void inputArr(int*& arr, int& n) {
    cout << "Nhap vao n: ";
    cin >> n;
    arr = new int[n];
    cout << "Nhap vao " << n << " phan tu trong mang: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 0;
    int* arr = NULL;
    inputArr(arr, n);
    cout << "Mang da nhap: ";
    printArr(arr, n);
    maxHeap(arr, n);
    cout << "Mang max heap: ";
    printArr(arr, n);
    return 0;
}