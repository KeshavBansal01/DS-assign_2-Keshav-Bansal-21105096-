//Keshav Bansal  ECE
//21105096
//[Ans .1]

// In place algorithm-
/*An in-place algorithm transforms the input without using any extra memory. As the algorithm executes, 
the input is usually overwritten by the output, and no additional space is needed for this operation.
An in-place algorithm may require a small amount of extra memory for its operation. However, 
the amount of memory required must not be dependent on the input size and should be constant.
Several sorting algorithms rearrange the input into sorted order in-place, such as insertion sort,
 selection sort, quick sort, bubble sort, heap sort, etc. All these algorithms require a constant amount 
 of extra space for rearranging the elements in the input array.*/



 //Out place algorithm-
/* An algorithm that is not in-place is called a not-in-place or out-of-place algorithm. Unlike an 
 in-place algorithm, the extra space used by an out-of-place algorithm depends on the input size.
The standard merge sort algorithm is an example of out-of-place algorithm as it requires O(n) 
extra space for merging. The merging can be done in-place, but it increases the time complexity 
of the sorting routine.*/

//[Ans.2]

// Using In-Place Algorithm we did insertion sort here..
#include <iostream>
using namespace std;
//We created a insertion Sort void function
void insert_IP(int arr[],int n){
    //Initialising variables i and j
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}
            if(arr[i]<=temp){arr[i+1]=temp;break;}
        }
        j++;
        i=j-1;
    }
    return;
}

// Using Out-Place Algorithm we did insertion sort here..
void insert_OP(int arr[],int si,int ei){
    //si=starting index
    //ei=ending index
    if(si==ei){return;}
    int j=si+1;
    int temp=arr[j];
    while(si>=0){
        if(arr[si]>temp){
            arr[si+1]=arr[si];
            si--;
        }
        if(si==-1){arr[0]=temp;break;}
        if(arr[si]<=temp){arr[si+1]=temp;break;}
    }
    insert_OP(arr,si+1,ei);
}
//Function to print array
void pfun(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}
int main(){
    int n;
    //Taking an array as input 
    cout<<"ENTER NUMBER OF ELEMENTS IN THE ARRAY: ";
    cin>>n;
    int arr[n],arr2[n];//Two array with same size and elements
    cout<<"ENTER ELEMENTS OF ARRAY SEPERATED BY SPACE: ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    //copying arr to arr2
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    cout<<"ARRAY BEFORE SORTING : ";pfun(arr,n);
    //Calling insertion sort using in-place algorithm.
    insert_IP(arr,n);
    cout<<endl;
    cout<<"ARRAY AFTER SORTING USING IN-PLACE ALGORITHM : ";
    //printing the array
    pfun(arr,n);
    cout<<endl;
    //calling insertiong sort using out-place algorithm.
    insert_OP(arr2,0,n-1);
    cout<<"ARRAY AFTER SORTING USING OUT-PLACE ALGORITHM : ";
    //printing the array
    pfun(arr,n);
    cout<<endl;

}



/*
[ANS.3]

In-place/Outplace technique – 
A sorting technique is inplace if it does not use any extra memory to sort the array. 
Among the comparison based techniques discussed, only merge sort is outplaced technique 
as it requires an extra array to merge the sorted subarrays. 
Among the non-comparison based techniques discussed, all are outplaced techniques.
 Counting sort uses a counting array and bucket sort uses a hash table for sorting the array. 

Online/Offline technique – 
A sorting technique is considered Online if it can accept new data while the procedure is
 ongoing i.e. complete data is not required to start the sorting operation. 
Among the comparison based techniques discussed, only Insertion Sort qualifies for this
 because of the underlying algorithm it uses i.e. it processes the array (not just elements) 
 from left to right and if new elements are added to the right, it doesn’t impact the ongoing operation. 
IN-PLACE algorithm are used in Bubble sort, Selection Sort, Insertion Sort, Heapsort.
NOT IN-PLACE algorithm is used in Merge Sort, Because merge sort requires O(n) extra space.

Lets take an  exapmle if we want to reverse an array then its in-place algorithm
will be swaping the first and last element of array until we reach the 
middle of array,If we want to solve the same problem using out-place 
algorithm we have to create one extra array of same size and copy 
elements of original array from back to the front of new array,this 
algorith increases the space complexity to O(n) as we have creaed an 
extra array.

*/
