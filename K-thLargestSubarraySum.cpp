#include <iostream>
//TC: N^2 log(K)
//SC:O(K)
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue <int,vector<int>,greater<int>> mini;
    int n=arr.size();
    vector<int>sumstore;
    
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(mini.size()<k)
                    mini.push(sum);
            else{
                if(mini.top() < sum){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
        return mini.top();
}