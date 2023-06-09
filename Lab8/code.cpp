#include <iostream>
using namespace std;
  
// function to heapify the tree
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest;
   int L= left(root);
   int R= right(root);
   if (L< n && arr[L]>arr[root]){
       largest=L;
   }
   else {
       largest =root;
   }
   if (R<n && arr[R]>arr[largest]){
       largest = R;
   }
   if (largest != root){
       swap(arr[root],arr[largest]);
       heapify(arr,n,largest);
   }
   
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
     for (int i = n / 2 - 1; i >= 0; i--) {
     heapify(arr, n, i);
     }
  
   // extracting elements from heap one by one
     for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
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
   
   int heap_arr[7];
   for (int i = 0; i < 10; i++) {
      heap_arr[i] = rand() % 25; 
   }
   
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
   
}
