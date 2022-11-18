#include <iostream>
using namespace std;
//Heapify: Moves node at ith index to its correct position
//Input array follows 0 based indexing
void heapify(vector<int> &arr, int n, int i){
    int smallest = i;
    int left = 2*i+1;  //left child
    int right = 2*i+2;   //right child
        if(left < n && arr[smallest]>arr[left])
            smallest = left;
    
        if(right < n && arr[smallest]>arr[right])
            smallest = right;
    
        if(smallest != i){   //If the smallest value at the subtree is not at root, then swap the root and the smallest value 
           swap(arr[smallest], arr[i]);
           heapify(arr, n, smallest);  //Heapify the node which contained the smallest value
        }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
    //Heapify nodes in reverse order level order tranversal i.e from bottom to top
    //Leaf nodes aren't heapfied as they already follow the heap property
    //First non leaf node at the bottom is at n/2-1th index
    for(int i=n/2-1; i>=0; i--){ //Heapify nodes in reverse order level order tranversal i.e from bottom to top
        heapify(arr, n, i);
    }
    return arr;
}
