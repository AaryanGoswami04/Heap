#include <iostream>
//TC: N^2 log(K)
//SC:O(K)
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue <int,vector<int>,greater<int>> mini;
    int n=arr.size();
    
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            mini.push(sum);
            
            if(mini.size()>k)
                mini.pop();
            }
        }
     return mini.top();
}
