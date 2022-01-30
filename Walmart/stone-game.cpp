// Question Link: https://leetcode.com/problems/stone-game/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // return true --> This will always be true for even sized array piles as Alex will always have the choice to stay on either Even or Odd sized indices.
        
        // More generalized DP solution for all cases.
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int g=0; g<n; g++) {
            for(int i=0,j=g; j<n; i++,j++) {
                if(g==0) {
                    dp[i][j] = piles[i];
                } else if(g==1) {
                    dp[i][j] = max(piles[i],piles[j]);
                } else {
                    int v1 = dp[i+2][j];
                    int v2 = dp[i+1][j-1];
                    int v3 = dp[i][j-2];
                    int min1 = min(v1,v2);
                    int min2 = min(v2,v3);
                    dp[i][j] = max(piles[i]+min1,piles[j]+min2);
                }
            }
        }
        int alexMax = dp[0][n-1];
        int arraySum = 0;
        for(auto &it: piles)
            arraySum += it;
        int bobMax = arraySum - alexMax;
        return alexMax > bobMax;
    }
};