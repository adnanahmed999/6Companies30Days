// Question Link: https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/#

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  
  private:

  public:
    string nextPalin(string N) { 
        // complete the function here
        int n = N.size();
        int half = n/2-1;
        int maxi = INT_MIN;
        bool found = false;
        int smaller = -1;
        int bigger = -1;
        for(int i=half; i>=0; i--) {
            int current = N[i]-'0';
            if(current>=maxi) {
                maxi = current;
            } else {
                //cout<<"below"<<endl;
                found = true;
                smaller = i;
                int smallestBiggerThanI = INT_MAX;
                for(int j=i+1; j<=half; j++) {
                    if(N[j]-'0' > current) {
                        if(N[j]-'0' < smallestBiggerThanI) {
                            smallestBiggerThanI = N[j]-'0';
                            bigger = j;
                        }
                    }
                }
                break;
            }
        }
        if(!found) return "-1";
        swap(N[smaller],N[bigger]);
        swap(N[n-1-smaller],N[n-1-bigger]);
        sort(N.begin()+smaller+1,N.begin()+half+1);
        sort(N.begin()+(n-1-half),N.begin()+(n-1-smaller));
        reverse(N.begin()+(n-1-half),N.begin()+(n-1-smaller));
        return N;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends