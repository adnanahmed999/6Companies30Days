// Question Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

struct node{
    int rowNo;
    int colNo;
    int arrSize;
    int val;
    
    node(int rowNumber, int colNumber, int value, int arraySize) {
        rowNo = rowNumber;
        colNo = colNumber;
        arrSize = arraySize; 
        val = value;
    }
};

struct compareNodes {
    bool operator()(node &n1, node &n2) {
        return n1.val>n2.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int start = -1;
        int end = -1;
        int minRange = INT_MAX;
        int maxCurrent = INT_MIN;
        priority_queue<node,vector<node>,compareNodes> pq;
        for(int i=0; i<n; i++) {
            node initial = node(i,0,nums[i][0],nums[i].size());
            pq.push(initial);
            maxCurrent = max(maxCurrent,nums[i][0]);
        }
        while(true) {
            node currentMinNode = pq.top();
            pq.pop();
            int minCurrent = currentMinNode.val;
            if(maxCurrent-minCurrent<minRange) {
                minRange = maxCurrent-minCurrent;
                start = minCurrent; 
                end = maxCurrent;
            }
            if(currentMinNode.colNo == currentMinNode.arrSize-1)
                break;
            int nextValue =  nums[currentMinNode.rowNo][currentMinNode.colNo+1];
            maxCurrent = max(maxCurrent,nextValue);
            node nextNode = node(currentMinNode.rowNo, currentMinNode.colNo+1, nextValue, currentMinNode.arrSize);
            pq.push(nextNode);
        }
        vector<int> ans = {start,end};
        return ans;
    }
};