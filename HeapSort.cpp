#include <iostream>
using namespace std;
//Time complexity:O(N log N)
//Space complexity: O(1)
//1-based indexing
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;  //left child 
    int right = 2*i+1;   //right child
        if(left < n && arr[largest]<arr[left])
           largest = left;
    
        if(right < n && arr[largest]<arr[right])
            largest = right;
    
        if(largest != i){   //If the largest value at the subtree is not at root, then swap the root and the largest value 
           swap(arr[largest], arr[i]);
           heapify(arr, n, largest);  //Heapify the node which contained the largest value
        }
}
void HeapSort(int arr[], int n){
  int size=n;
  while(size>1){
    //Step 1:swap root and last node i.e the max element of array is moved to its correct place
    swap(arr[size],arr[1]);
    size--;

    //Step 2: Heapify the root
    heapify(arr, size, 1);
  }
}
int main() {
  //arr follows 1 based indexing
 int arr[6]={-1,4,10,18,3,20};
int n=5;
HeapSort(arr,n);
}
