// Question Link: https://leetcode.com/problems/koko-eating-bananas/

class Solution {

private:
    bool check(vector<int>& piles, int possibleAns, int h) {
        int hours = 0;
        int n = piles.size();
        for(int i=0; i<n; i++) {
            int cps = piles[i]; // current pile size;
            hours += cps/possibleAns;
            if(cps%possibleAns!=0) hours++;
            if(hours>h) return false;
        }
        return true;
    }
    
public:   
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MAX;
        int ans = low;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(check(piles,mid,h)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};