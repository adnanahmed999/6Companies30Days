// Question Link: https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    
    // run bfs to track reachable grid position from pacific or atlantic boundary
    void bfs(int m, int n, queue<pair<int,int>>&Q, vector<vector<int>>& grid, vector<vector<bool>>&visited)
    {
        int rowOffset[] = {0,0,1,-1};
        int colOffset[] = {1,-1,0,0};
        int currentHeight;
        int cx,cy;
        int px,py;
        
        while(!Q.empty())
        {
            cx = Q.front().first;
            cy = Q.front().second;
            currentHeight = grid[cx][cy];
            
            Q.pop();
            
            for(int k=0;k<4;k++)
            {
                px = cx + rowOffset[k];
                py = cy + colOffset[k];
                
                // child node can be reached from current nodes if 
                // greater or equal in height compared to current node height
                if(px>=0 && px<m && py>=0 && py<n && grid[px][py]>=currentHeight && !visited[px][py])
                {
                    visited[px][py] = true;
                    Q.push({px,py});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
        vector<vector<int>>result;
        
        int m = grid.size();
        if(m==0) return result;
        
        int n = grid[0].size();
        if(n==0) return result;
        
        // track nodes reachable from pacific boundary
        vector<vector<bool>>pacificVisited(m,vector<bool>(n,false));
        
        // track nodes reachable from atlantic boundary
        vector<vector<bool>>atlanticVisited(m,vector<bool>(n,false));
        
        queue<pair<int,int>>Q;
        
        // add pacific boundary nodes  in to queue
        for(int i=0;i<n;i++)
        {
            if(!pacificVisited[0][i])
            {
                pacificVisited[0][i] = true;
                Q.push({0,i});                    
            }
        }

        // add pacific boundary nodes  in to queue       
        for(int i=1;i<m;i++)
        {
            if(!pacificVisited[i][0])
            {
                pacificVisited[i][0] = true;
                Q.push({i,0});                    
            }
        }
        
        // run bfs from pacific boundary nodes
        bfs(m,n,Q,grid,pacificVisited);
        
        // add atlantic boundary nodes
        for(int i=0;i<n;i++)
        {
            if(!atlanticVisited[m-1][i])
            {
                atlanticVisited[m-1][i] = true;
                Q.push({m-1,i});                    
            }
        }

        // add atlantic boundary nodes        
        for(int i=0;i<m-1;i++)
        {
            if(!atlanticVisited[i][n-1])
            {
                atlanticVisited[i][n-1] = true;
                Q.push({i,n-1});                    
            }
        }
        
        // run bfs from atlantic boundary nodes
        bfs(m,n,Q,grid,atlanticVisited);
        
        // push nodes in to result vector which are reachable both from pacific and atlantic boundary
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(pacificVisited[i][j] && atlanticVisited[i][j])
                    result.push_back({i,j});
        
        return result;
    }
};