class KthLargest {
public:
  // Declare a min heap to keep track of the k largest elements.
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    // Store the value of 'k' to know which largest element to keep track of.
    int kthSize;

    // Constructor for initializing the KthLargest class.
    // k - The kth position to track.
    // nums - Initial list of numbers from which we find the kth largest element.
    KthLargest(int k, std::vector<int>& nums) {
        kthSize = k;
        // Add initial numbers to the heap
        for (int num : nums) {
            add(num);
        }
    }

    // Function to add a number to the stream and return the kth largest element.
    int add(int val) {
        // Add the new number to the min heap.
        minHeap.push(val);
        // If the heap size is greater than k, remove the smallest element.
        if (minHeap.size() > kthSize) {
            minHeap.pop();
        }
        // Return the kth largest element (top of the min heap).
        return minHeap.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */