//Keshav Bansal
//21105096 ECE

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

//We will not be passing the size of array in this function we are creating..
int linear_search(int arr[], int x)
// The loop will not stop until the condition is false..
{
    for (int i = 0;; i++) 
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
}
// Left and right indexes are being provided in this simple binary function..

int binary_search_code(int arr[],int l,int r,int x)
{
    int mid = (l+r) / 2;
    while(l<=r)
    {
        if(arr[mid]>x)
        {
            r = mid - 1;
            mid = (l+r) / 2;
        }
        else if(arr[mid]<x)
        {
            l = mid+1;
            mid = (l+r) / 2;
        }
        else
        {
            return mid;
        }
    }

}

//We try to reduce our work done to O(log(N)) time complexity, by increasing the range of our search exponentitaly by 2.

int binary_search(int arr[], int x)
{
    int low = 0;
    int high = 1;

    while (arr[high] < x)
    {
        low = high;//update the low value
        high = 2 * high;//double the range of search, when the condition is satisfies then we call BINARY SEARCH on that range(low to high).
    }

    return binary_search_code(arr,low,high,x);
}



// We are creating an array , but the size of the array is not passed to the function.

int main()
{
    // In this we are  given starting index of the array.
    int *arr = new int[10000];
    int n;
    cout << "Number of elements in an array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "ENTER THE ELEMENT TO SEARCH FOR : ";
    cin >> x;
    cout << endl;

    cout << "Index of " << x << " from LINEAR SEARCH is : " << linear_search(arr, x) << endl;
    cout << "Index of " << x << " from BINARY SEARCH is : " << binary_search(arr, x) << endl;
    delete[] arr;
}