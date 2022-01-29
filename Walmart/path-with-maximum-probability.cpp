// Question Link: https://leetcode.com/problems/path-with-maximum-probability/

class Solution {

private:
    vector<vector<pair<int,double>>> adjMatrixProvider(int num, vector<vector<int>>& edges, vector<double>& succ) {
        vector<vector<pair<int,double>>> adj(num);
        int n = edges.size();
        for(int i=0; i<n; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            double weight = succ[i];
            pair<int,double> p1 = {x,weight};
            pair<int,double> p2 = {y,weight};
            adj[y].push_back(p1);
            adj[x].push_back(p2);
        }
        return adj;
    }
    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj = adjMatrixProvider(n, edges, succProb);
        vector<double> probs(n,0);
        probs[start] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        while(!pq.empty()) {
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            for(auto eachNeigh: adj[currNode]) { // neigh = neighbour
                double connectingProb = eachNeigh.second;
                int neigh = eachNeigh.first;
                if(currProb*connectingProb > probs[neigh]) {
                    probs[neigh] = currProb*connectingProb;
                    pq.push({probs[neigh],neigh});
                }
            }
        }
        return probs[end];
    }
};