#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

// Function to compute Hamming distance between submatrix of M starting at (r,c) and P
int computeHammingDistance(const vector<vector<int>>& M, const vector<vector<int>>& P, int r, int c, int k) {
    int dist = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (M[r + i][c + j] != P[i][j]) {
                dist++;
            }
        }
    }
    return dist;
}

// Function to find the top-left coordinate of the submatrix with minimum Hamming distance
pair<int, int> findMinHammingSubmatrix(const vector<vector<int>>& M, const vector<vector<int>>& P, int n, int k) {
    int minDist = INT_MAX;
    pair<int, int> minPos = {-1, -1};

    for (int r = 0; r <= n - k; ++r) {
        for (int c = 0; c <= n - k; ++c) {
            int dist = computeHammingDistance(M, P, r, c, k);
            if (dist < minDist) {
                minDist = dist;
                minPos = {r, c};
            }
        }
    }
    return minPos;
}

int main() {
    int n, k;
    cout << "Enter size of matrix M (n): ";
    cin >> n;
    cout << "Enter size of matrix P (k): ";
    cin >> k;

    vector<vector<int>> M(n, vector<int>(n));
    vector<vector<int>> P(k, vector<int>(k));

    cout << "Enter matrix M (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> M[i][j];

    cout << "Enter matrix P (" << k << "x" << k << "):\n";
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j)
            cin >> P[i][j];

    pair<int, int> pos = findMinHammingSubmatrix(M, P, n, k);
    if (pos.first == -1) {
        cout << "No valid submatrix found.\n";
    } else {
        cout << "Top-left corner of submatrix with minimum Hamming distance: (" << pos.first << ", " << pos.second << ")\n";
        cout << "Minimum Hamming distance: " << computeHammingDistance(M, P, pos.first, pos.second, k) << "\n";
    }
    return 0;
}
