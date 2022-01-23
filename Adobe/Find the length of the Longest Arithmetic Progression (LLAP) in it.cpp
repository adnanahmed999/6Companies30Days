// Question Link:https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/#

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int nums[], int n) {
        if(n==1) return 1;
        int count = INT_MIN;
        vector<unordered_map<int,int>> vm(n);
        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                int diff = nums[j]-nums[i];
                if(vm[j].find(diff)!=vm[j].end()) {
                    vm[i][diff] = max(vm[i][diff],vm[j][diff]+1);
                } else {
                    vm[i][diff] = max(vm[i][diff],1);
                }
                count = max(count,vm[i][diff]);
            }
        }
        return count+1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends