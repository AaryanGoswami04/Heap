#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;  //left child
    int right = 2*i+1;   //right child
        if(left < n && arr[largest]<arr[left])
           largest = left;
    
        if(right < n && arr[largest]<arr[right])
            largest = right;
    
        if(largest != i){   //If the smallest value at the subtree is not at root, then swap the root and the smallest value 
           swap(arr[largest], arr[i]);
           heapify(arr, n, largest);  //Heapify the node which contained the smallest value
        }
}
void HeapSort(int arr[], int n){
  int size=n;
  while(size>1){
    //swap
    swap(arr[size],arr[1]);
    size--;

    //Step 2
    heapify(arr, size, 1);
  }
}
int main() {
 int arr[6]={-1,4,10,18,3,20};
int n=5;
//heap creation
for(int i=n/2;i>0;i--)
   heapify(arr, n, i);
HeapSort(arr,n);
}