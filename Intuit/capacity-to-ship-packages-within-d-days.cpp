// Question Link:https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
private:
    pair<int,int> arrayDetailsProvider(vector<int>& arr) {
        int maxi = INT_MIN;
        int sum = 0;
        for(auto &it: arr) {
            maxi = max(maxi, it);
            sum += it;
        }
        return {sum,maxi};
    }   
    
    bool check(vector<int>& weights, int possibleAns, int maxLimit) {
        int sum = 0;
        int daysDone = 1;
        int n = weights.size();
        for(int i=0; i<n; i++) {
            if(weights[i]>possibleAns)
                return false;
            if(sum+weights[i]<=possibleAns)
                sum += weights[i];
            else {
                sum = weights[i];
                daysDone++;
            }
            if(daysDone>maxLimit)
                return false;
        }
        return true;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        pair<int,int> arrayDetails = arrayDetailsProvider(weights);
        int l = arrayDetails.second, h = arrayDetails.first;
        int ans = l;
        while(l<=h) {
            int m = l + (h-l)/2;
            if(check(weights,m,days)) {
                ans = m;
                h = m-1;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
};