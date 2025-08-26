#include <iostream>
#include <vector>
using namespace std;

// Helper function to print a subset
void printSubset(const vector<int>& subset) {
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}

// Recursive function to generate all k-element subsets of {1, 2, ..., n}
void generateSubsets(int n, int k, int start, vector<int>& currentSubset) {
    // Base case: if the current subset has k elements, print it
    if (k == 0) {
        printSubset(currentSubset);
        return;
    }

    // Recursive case: try adding elements starting from 'start' to the current subset
    for (int i = start; i <= n; ++i) {
        currentSubset.push_back(i);  // Include i in the current subset
        generateSubsets(n, k - 1, i + 1, currentSubset);  // Recur for the remaining k-1 elements
        currentSubset.pop_back();  // Backtrack to explore the next subset without i
    }
}

int main() {
    int n, k;
    cout << "Enter n (size of the set) and k (size of the subsets): ";
    cin >> n >> k;

    vector<int> currentSubset;
    cout << "The k-element subsets of {1, 2, ..., " << n << "} are:\n";
    generateSubsets(n, k, 1, currentSubset);  // Start from element 1
    
    return 0;
}
