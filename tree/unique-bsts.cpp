#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(const int& n);
private:
    int helper(const int& n, vector<int>& arr);
};

int Solution::numTrees(const int& n) {
    vector<int> arr(n+1, -1);
    arr[0] = arr[1] = 1;
    
    return helper(n, arr);
}

int Solution::helper(const int& n, vector<int>& arr) {
    if (-1 != arr[n]) return arr[n];
    
    int result = 0;
    for (int i = 0; i < n; ++i)
        result += helper(i, arr) * helper(n - i - 1, arr);
    
    arr[n] = result;
    
    return arr[n];
}
