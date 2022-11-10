// // Name:Keshav Bansal
// //Branch: ECE
// //SID: 21105096


#include <bits/stdc++.h>              
using namespace std;            


// Compare Bubble sort and Selection sort based on the following:
//1.Inplace and Outplace implementations
//2.Number of comparisons
//3.Number of swaps
 





// Bubble Sort Algorithm:

void bubble_sort(int arr[],int n){
    int i=0,j=1,t=n-1;
    int no_of_swap=0;
    int no_of_comp=0;
    while(t>0){
        while(j<=t){
            if(arr[i]>arr[j]){swap(arr[i],arr[j]);no_of_swap++;}
            i++,j++;
            no_of_comp++;
        }
        t--;
        i=0,j=1;
    }
    cout<<" . Number of SWAP:"<<no_of_swap<<endl;
    cout<<" . Number of COMPARISON:"<<no_of_comp<<endl;
    cout<<" . [INPLACE SORTING ALGORITHM USED]"<<endl;
}




void Selection_Sort(int arr[],int size)
{ int swaps=0;
int comparision=0;
    for(int i=0;i<size-1;i++)
    {
    int index_min=0;
        for (int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[index_min])
               {index_min=j;
               comparision++;
               }
        }
        if(index_min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[index_min];
            arr[index_min]=temp;
            swaps++;
        }
    }

    cout<<"no. of swaps"<<swaps<<endl;
    cout<<"no. of comparisions "<<comparision<<endl;
    cout<<"Since only changes are made in the given array only and no extra array or space is used so it is INPLACE-Algorithm"<<endl;

}


void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter number of elements in array:";cin>>n;
    int arr1[n];int arr2[n];
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){int a;cin>>a;arr1[i]=a;arr2[i]=a;}
    
    cout<<"\nARRAY before sorting:";
    print(arr1,n);
    cout<<endl;
    cout<<"BUBBLE SORT"<<endl;
    bubble_sort(arr1,n);
    cout<<" . ARRAY After Sorting Using Bubble Sorting:";
    print(arr1,n);
    cout<<endl;
    cout<<"SELECTION SORT"<<endl;
    Selection_Sort(arr2,n);
    cout<<" . ARRAY After Sorting Using Selection Sorting:";
    print(arr2,n);
}



// Time complexity:
// Bubble sort:
// In this, sorting occurs which seems to be very similar to a natural phenomena in which water bubble 
//raises to the surface and in this 
// larger element raises to the last of the array per iteration of the array .
// In this algorithm we compare all the adjacent elements and 
// swaps continuously all those which is smaller than the current element  and in every iteration.
// Since swapping takes O(1) time and in worst case if there are n elements then in one
// iteration there would be n swapping and that will take 
// O(n) time and this process will happen n times and making time complexity of Bubble  sort O(n^2).

// Selection Sort:
// In this algorithm we iterates through the complete array and find the minimum element 
//and then swap that with the first element. Swapping process takes O(1) time 
// over 1 iteration . So there will be n iteraitons to find the minimum element of every 
//position of the array and there are n positions . So this makes the time complexity 
// of Selection Sort O(n^2) in worst case.