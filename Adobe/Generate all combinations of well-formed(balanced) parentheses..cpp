// Question Link: https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/#

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{   
    
    private:
        void generate(vector<string>& finalAns, string& tempAns, int& open, int& close, int &n) {
            if(open==n && close==n) {
                finalAns.push_back(tempAns);
                return;
            }
            if(open>n || close>n) return;
            tempAns.push_back('(');
            open++;
            generate(finalAns, tempAns, open, close, n);
            tempAns.pop_back();
            open--;
            if(open>close) {
                tempAns.push_back(')');
                close++;
                generate(finalAns, tempAns, open, close, n);
                close--;
                tempAns.pop_back();
            }
            
        }
    
    public:
    vector<string> AllParenthesis(int n) {
        vector<string> finalAns;
        string tempAns;
        int open = 0;
        int close = 0;
        generate(finalAns, tempAns, open, close, n);
        return finalAns;
    }
};

// { Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n); 
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<"\n";
    }
    return 0; 
} 
  // } Driver Code Ends