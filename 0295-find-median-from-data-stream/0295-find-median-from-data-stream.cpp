class MedianFinder {
public:
   priority_queue<int,vector<int>,greater<int>>minHeap;
    priority_queue<int> maxHeap;
    
    void addNum(int x) 
    {
        minHeap.push(x);
        if(minHeap.size()==maxHeap.size() && minHeap.top()<maxHeap.top())
        {
            int temp = minHeap.top();
            minHeap.pop();
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(temp);
        }
        if(minHeap.size()!=maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() 
    {
        if(minHeap.size()==maxHeap.size())
        return (double)((minHeap.top()+maxHeap.top())/2.0);
        else
        return (double)maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */