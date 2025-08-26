#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursive function to generate Gray code
void generateGrayCode(int n, vector<string>& grayCodes, string& x) {
    if (n == 0) {
        grayCodes.push_back(x);
        return;
    }

    x.push_back('0');
    generateGrayCode(n - 1, grayCodes, x);
    x.pop_back();  
    
    x.push_back('1');
    generateGrayCode(n - 1, grayCodes, x);
    x.pop_back();  
}

int main() {
    int bits;
    cout << "Enter number of bits: ";
    cin >> bits;
    
    vector<string> grayCodes;  // To store the Gray code sequence
    string x = "";             // Temporary string to build the sequence
    
    generateGrayCode(bits, grayCodes, x);
    
    for (auto it : grayCodes) {
        cout << it <<" , ";
    }
    
    return 0;
}
