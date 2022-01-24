// Question Link: https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/#

// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    

class Solution{
   //Function to find the leaders in the array.
   public:
   vector<int> leaders(int a[], int n){
      vector<int> vec;
      int mx = a[n-1];
      vec.push_back(mx);
      for(int i=n-2; i>=0; i--){
          if(a[i]>=mx)
          {
              vec.push_back(a[i]);
          }
          mx = max(a[i],mx);
      }
      int i=0;
      int j = vec.size()-1;
      while(i<j)
      {
          swap(vec[i],vec[j]);
          i++;
          j--;
      }
      return vec;
   }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends