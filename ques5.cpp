













MAY OR MAY NOT WORKS







#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX

using namespace std;

// Function to calculate the Hamming distance between two k×k matrices
int calculateHammingDistance(const vector<vector<int>>& subMatrix, const vector<vector<int>>& pattern, int k) {
    int distance = 0;
    
    // Compare element by element
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (subMatrix[i][j] != pattern[i][j]) {
                ++distance;
            }
        }
    }
    
    return distance;
}

// Function to find the k×k submatrix of M with the smallest Hamming distance to P
void findMinHammingSubmatrix(const vector<vector<int>>& M, const vector<vector<int>>& P, int n, int k) {
    int minDistance = INT_MAX;  // Start with a large value
    int bestRow = -1, bestCol = -1;

    // Slide over the matrix M to check each possible k×k submatrix
    for (int i = 0; i <= n - k; ++i) {  // i is the row index of the top-left corner
        for (int j = 0; j <= n - k; ++j) {  // j is the column index of the top-left corner
            // Extract the k×k submatrix starting from (i, j)
            vector<vector<int>> subMatrix(k, vector<int>(k));
            for (int x = 0; x < k; ++x) {
                for (int y = 0; y < k; ++y) {
                    subMatrix[x][y] = M[i + x][j + y];
                }
            }

            // Calculate the Hamming distance between subMatrix and P
            int dist = calculateHammingDistance(subMatrix, P, k);

            // If we found a smaller distance, update the result
            if (dist < minDistance) {
                minDistance = dist;
                bestRow = i;
                bestCol = j;
            }
        }
    }

    // Output the best submatrix and its position
    cout << "The k×k submatrix with the smallest Hamming distance is at position (" << bestRow << ", " << bestCol << "):\n";
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << M[bestRow + i][bestCol + j] << " ";
        }
        cout << endl;
    }
    cout << "Hamming distance: " << minDistance << endl;
}

int main() {
    int n, k;
    
    // Input the dimensions of the matrix M and the submatrix P
    cout << "Enter the size of matrix M (n): ";
    cin >> n;
    cout << "Enter the size of submatrix P (k): ";
    cin >> k;

    vector<vector<int>> M(n, vector<int>(n));  // Matrix M
    vector<vector<int>> P(k, vector<int>(k));  // Matrix P

    // Input the matrix M
    cout << "Enter the elements of the " << n << "×" << n << " matrix M:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }

    // Input the matrix P
    cout << "Enter the elements of the " << k << "×" << k << " matrix P:\n";
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> P[i][j];
        }
    }

    // Call the function to find the submatrix with the smallest Hamming distance
    findMinHammingSubmatrix(M, P, n, k);

    return 0;
}
