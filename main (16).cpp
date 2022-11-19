#include <iostream>
#include<queue>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k) {
       priority_queue<int>pq;
       for(int i=0; i<k;i++)
       pq.push(arr[i]);
       
       for(int i=k; i<=r;i++){
           if( arr[i] < pq.top()){
               pq.pop();
               pq.push(arr[i]);
           }
       }
       return pq.top();
    } void heapify(vector<int> &ans, int size, int i){
        int largest= i;
        int left= 2*i+1;
        int right=2*i+2;
        
            if(left<size && ans[largest]<ans[left])
                largest=left;
                
            if(right<size && ans[largest]<ans[right])
                largest=right;
            
            if(largest!=i){
                swap(ans[largest],ans[i]);
                heapify(ans, size, largest);
            }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
      //Step 1: merge both arrays
       vector<int> ans;
       for(auto i:a)
       ans.push_back(i);
         for(auto i:b)
       ans.push_back(i);
        
    //Step 2:heapify the array
        int size=ans.size();
        for(int i=size/2-1; i>=0; i--)
            heapify(ans, size, i);
        return ans;
        
    }