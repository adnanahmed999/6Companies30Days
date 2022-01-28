// Question Link: https://leetcode.com/problems/split-array-largest-sum/

class Solution {
private:
    pair<int,int> arrayDetailsProvider(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for(auto &it: nums) {
            sum += it;
            maxi = max(maxi,it);
        }
        return {sum,maxi};
    }
    
    bool check(vector<int>& nums, int possibleAns, int maxLimit) {
        int n = nums.size();
        int sum = 0;
        int partitionsDone = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]>possibleAns)
                return false;
            if(nums[i]+sum<=possibleAns) {
                sum += nums[i];
            } else {
                sum = nums[i];
                partitionsDone++;
            }
            if(partitionsDone>maxLimit)
                return false;
        }
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        pair<int,int> arrayDetails = arrayDetailsProvider(nums);
        int low = arrayDetails.second, high = arrayDetails.first;
        int ans = low;
        while(low<=high) {
            int mid = low + (high-low)/2;
            bool checker = check(nums,mid,m-1); //  m splits means m-1 partitions
            if(checker) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1; 
            }
        }
        return ans;
    }
};