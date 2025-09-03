#include <bits/stdc++.h>
using namespace std;

vector<string> generateGray(int n) {
    if (n == 1) {
        return {"0", "1"};
    }
    vector<string> prev = generateGray(n - 1);
    vector<string> result;
    for (int i = 0; i < prev.size(); i++) {
        result.push_back("0" + prev[i]);
    }
    for (int i = prev.size() - 1; i >= 0; i--) {
        result.push_back("1" + prev[i]);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<string> grayCodes = generateGray(n);
    cout << "Gray code of length " << n << ":\n";
    for (auto &code : grayCodes) {
        cout << code << "\n";
    }
    return 0;
}
