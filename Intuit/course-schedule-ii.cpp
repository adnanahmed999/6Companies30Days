// Question Link: https://leetcode.com/problems/course-schedule-ii/

class Solution {

private:
    
    void topologicalDFS(vector<vector<int>>& adj, vector<int>& topologicalArray, vector<bool>& visited, int currNode) {
        visited[currNode] = true;
        for(auto eachNeighbour: adj[currNode]) {
            if(!visited[eachNeighbour])
                topologicalDFS(adj, topologicalArray, visited, eachNeighbour);
        }
        topologicalArray.push_back(currNode);
    }
    
    vector<int> topologicalSortProvider(int num, vector<vector<int>>& adj) {
        vector<int> topologicalArray;
        vector<bool> visited(num, false);
        for(int i=0; i<num; i++)
            if(!visited[i])
                topologicalDFS(adj, topologicalArray, visited, i);
        reverse(topologicalArray.begin(),topologicalArray.end());
        return topologicalArray;
    }
    
    bool isCycle(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& sameRecurVisited, int currNode) {
        visited[currNode] = true;
        sameRecurVisited[currNode] = true;
        for(auto eachNeighbour: adj[currNode]) {
            if(!visited[eachNeighbour]) {
                if(isCycle(adj, visited, sameRecurVisited, eachNeighbour))
                    return true;
            } else if(sameRecurVisited[eachNeighbour])
                return true;
        }
        sameRecurVisited[currNode] = false;
        return false;
    } 
    
    bool checkCycleInDirectedGraph(int num, vector<vector<int>>& adj) {
        vector<bool> visited(num, false);
        vector<bool> sameRecurVisited(num, false);
        for(int i=0; i<num; i++) {
            if(!visited[i]) {
                if(isCycle(adj, visited, sameRecurVisited, i)) 
                    return true;
            }
        }
        return false;
    }
    
    vector<vector<int>> adjacenyListProvider(int num, vector<vector<int>>& pre) {
        vector<vector<int>> ans(num);
        for(auto eachPair: pre) 
            ans[eachPair[1]].push_back(eachPair[0]);
        return ans;
    }

public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<vector<int>> adj = adjacenyListProvider(num, pre);
        if(checkCycleInDirectedGraph(num, adj)) return ans;
        return  topologicalSortProvider(num, adj);
    }
};