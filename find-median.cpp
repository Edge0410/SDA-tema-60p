class MedianFinder {
public:
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        // echilibrarea heapurilor

        // maxHeap trebuie sa fie cu max 1 element mai mare decat min heap, dar
        // minHeap nu trebuie sa fie mai mare decat maxHeap pentru ca primul element
        // din maxHeap va reprezenta elementul din mijloc sau elementul din 
        // stanga mijlocului

        if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size() - minHeap.size() > 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        // maxHeap top e st, minHeap top e dr - par, maxHeap top e median - impar

        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }

 private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */