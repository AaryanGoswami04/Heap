/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
*/
class MedianFinder {
public:
    priority_queue<int> Maxheap; //stores elements smaller than median
    priority_queue<int, vector<int>, greater<int>> Minheap;  //stores elements greater than median

    MedianFinder() {  
    }
    
    void addNum(int num) {   //Time complexity: O(N)
      if(Minheap.empty() || num >= Minheap.top()){
        Minheap.push(num);
        if(Minheap.size() - Maxheap.size() >1){
                Maxheap.push(Minheap.top());
                Minheap.pop();
            }
        }
        else{
            Maxheap.push(num);
            if(Maxheap.size() > Minheap.size()){
                Minheap.push(Maxheap.top());
                Maxheap.pop();
            }
        }
    }
    
    double findMedian() {  //Time complexity: O(1)
        double median;
        if(Maxheap.size() == Minheap.size())  //The size of the stream is even
            median = (Maxheap.top()+Minheap.top())/2.0; 
        else
            median = Minheap.top();
      
        return median;
    }
};
