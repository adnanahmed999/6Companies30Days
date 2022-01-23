// Question Link: https://practice.geeksforgeeks.org/problems/implement-atoi/1/#

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        // Your code here
        int n = str.size();
        int sum = 0;
        bool isNegative = false;
        for(int i=0; i<n; i++) {
            if(str[i]<'0' || str[i]>'9') {
                if(i==0 && str[i]=='-') {
                    isNegative = true;
                    continue;
                } else {
                    return -1;
                }
            }
            int number = str[i]-'0';
            sum = sum*10 + number;
        }
        return isNegative ? sum*(-1) : sum;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends