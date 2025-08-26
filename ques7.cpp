#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// Define a custom comparator for the min-heap
struct Compare {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<0>(a) > get<0>(b);  // Min-heap based on the first value (element)
    }
};

// Function to merge k sorted arrays using a min-heap
vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    int k = arrays.size();
    vector<int> result;
    
    // Min-heap to store (element, array index, element index within that array)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> minHeap;

    // Initialize the heap with the first element from each array
    for (int i = 0; i < k; ++i) {
        if (!arrays[i].empty()) {
            minHeap.push(make_tuple(arrays[i][0], i, 0));  // (value, array index, element index)
        }
    }

    // Process the heap and build the result array
    while (!minHeap.empty()) {
        // Get the smallest element from the heap
        auto [value, arrIdx, elemIdx] = minHeap.top();
        minHeap.pop();
        
        // Add the element to the result array
        result.push_back(value);
        
        // If there are more elements in the same array, push the next element to the heap
        if (elemIdx + 1 < arrays[arrIdx].size()) {
            minHeap.push(make_tuple(arrays[arrIdx][elemIdx + 1], arrIdx, elemIdx + 1));
        }
    }
    
    return result;
}

int main() {
    // Input: k sorted arrays
    int k;
    cout << "Enter the number of arrays: ";
    cin >> k;

    vector<vector<int>> arrays(k);
    cout << "Enter the sorted arrays:" << endl;
    for (int i = 0; i < k; ++i) {
        int n;
        cout << "Enter the size of array " << i + 1 << ": ";
        cin >> n;
        arrays[i].resize(n);
        cout << "Enter the elements of array " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> arrays[i][j];
        }
    }

    // Merge the k sorted arrays
    vector<int> mergedArray = mergeKSortedArrays(arrays);

    // Output the merged array
    cout << "Merged sorted array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
