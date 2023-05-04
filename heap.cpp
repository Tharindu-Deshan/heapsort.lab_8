#include <iostream>
#include <cmath>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int idx_left = 2*root +1 ;
   int idx_right = 2*root +2 ;
   int idx_max = root;
   if(idx_left < n &&  arr[idx_max]< arr[idx_left] ){
        idx_max =  idx_left;
   }
   if(idx_right<n && arr[idx_right]> arr[idx_max]){
       idx_max = idx_right;
   }
   if(root != idx_max) {
       int temp = arr[idx_max];
       arr[idx_max] = arr[root];
       arr[root]= temp;
       heapify(arr,n,idx_max);
   }

  
   
}
  
// implementing heap sort
void heapSort(int arr[], int N) {

    for (int i = floor(N/2); i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i >= 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[8] ;
   for(int i =0 ; i<8 ; i++ ){
       heap_arr[i]=::rand()%99;
   }


   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
