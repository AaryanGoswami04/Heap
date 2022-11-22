//Time complexity: O(n*k log k)
//n is the max size of all the k linked lists
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> MinHeap;
    int k = lists.size();

    if(k == 0)
        return NULL;
    
    //Step 1: Insert heads of all linked lists into the min heap
    for(int i=0; i<k; i++){
        if(lists[i] != NULL)
            MinHeap.push(lists[i]);
    }   
    ListNode *head = NULL, *tail = NULL;

    //Step 2: Remove the min element(present at the top) and put it in the output LL and insert the next element from the LL  of removed element. Repeat the process until heap is empty
    while(!MinHeap.empty()){
        ListNode *top = MinHeap.top();
        MinHeap.pop();

        if(top->next != NULL)
            MinHeap.push(top->next);

        if(head == NULL){ //Final linked list is empty
            head = top;
            tail = top;
        }
      
        else{    //Insert at the end of LL
            tail->next = top;
            tail = top;
        }
    }
    return head;
  }
};
