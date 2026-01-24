#include <iostream>
#include <vector>
using namespace std;

long long calculateSum(int n) {
    // Calculate the sum of first n natural numbers
    long long totalSum = n * (n + 1LL) / 2;
    
    // Subtract all powers of 2 up to n
    long long powerOf2 = 1;
    while (powerOf2 <= n) {
        totalSum -= 2 * powerOf2;
        powerOf2 *= 2;
    }
    
    return totalSum;
}

int main() {
    int t;
    cin >> t;
    vector<int> results;
    while (t--) {
        int n;
        cin >> n;
        results.push_back(calculateSum(n));
    }
    for (auto result : results) {
        cout << result << endl;
    }
    return 0;
}
