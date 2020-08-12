#include <iostream>
using namespace std;
void mergeSort(int *,int, int , int );
void splitFunction(int *array, int left, int right)
{
    int mid;
    if (left < right){  
        mid=(left+right)/2;
        splitFunction(array,left,mid);
        splitFunction(array,mid+1,right);
        mergeSort(array,left,right,mid);
    }//had a hard time with the splitfunction cus i sometimes get an unhandled exeption, could cause program to crash
}

void mergeSort(int *array, int left, int right, int mid)
{
    int ll, r, lt, aMax[100];
    ll = left;
    lt = left;
    r = mid + 1;
    while (ll <= mid && r <= right) {
        if (array[ll] < array[r]) {
            aMax[lt] = array[ll];
            lt++;
            ll++;
        }
        else  {
            aMax[lt] = array[r];
            lt++;
            r++;
        }
    }
    while (ll <= mid) {
        aMax[lt] = array[ll];
        lt++;
        ll++;
    }
    while (r <= right) {
        aMax[lt] = array[r];
        lt++;
        r++;
    }
    for (ll = left; ll < lt; ll++)  {
        array[ll] = aMax[ll];
    }
}

void display(int* array, int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int maxArray[100], num;
    cout<<"Enter number of elements (less than 100):";
    cin>>num;
    cout<<"input numbers:";
    for (int i = 0; i < num; i++) { cin>>maxArray[i];
    }
    cout << "unsorted array: ";
    display(maxArray, num);
    splitFunction(maxArray, 0, num-1);
    cout << endl;
    cout << "sorted array: ";
    display(maxArray, num);
}