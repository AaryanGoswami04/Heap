#include <iostream>
 public:
    class node{
        public:
        int data;
        int i;
        int j;
        node(int data, int row, int col){
            this->data = data;
            i = row;
            j = col;
        }
    };

    class compare{
        public:
        bool operator()(node* a,node* b){
            return a->data > b->data;
        }
    };

    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
       priority_queue<node*, vector<node*>, compare> minheap;
     
      //Step 1: Push first element of each array in min heap
       for(int i=0; i<K;i++){
           node* temp=new node(arr[i][0], i, 0);
           minheap.push(temp);
       }
       
       vector<int>ans;
       
     //Step 2: 
     //Insert heap.top() in ans array
     //Pop heap.top();
     //Insert the next element of the array(which contained heap.top()) into min heap
     //Repeat until heap becomes empty
       while(!minheap.empty()){
           node* temp = minheap.top();
           ans.push_back(temp->data);
           minheap.pop();
           
           int i=temp->i;
           int j=temp->j;
           
           if(j+1 < arr[i].size()){
               node* next = new node(arr[i][j+1], i ,j+1);
               minheap.push(next);
           }
       }
       return ans;
    }
