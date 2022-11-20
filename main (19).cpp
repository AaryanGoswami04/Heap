#include <iostream>
 public:
    class node{
        public:
        int data;
        int i;
        int j;
        node(int data, int row, int col){
            this->data = data;
            i=row;
            j=col;
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
       for(int i=0; i<K;i++){
           node* temp=new node(arr[i][0], i, 0);
           minheap.push(temp);
       }
       
       vector<int>ans;
       
       while(!minheap.empty()){
           node* temp=minheap.top();
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
int main() {
  std::cout << "Hello World!\n";
}