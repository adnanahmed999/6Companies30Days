// Question Link: https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;
        queue<pair<int,int>> pq; // By mistake named queue as pq (priority queue)
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j]) {
                    pq.push({i,j});      
                }
            }
        }
        if(pq.size()==r*c || pq.size()==0) return -1;
        // cout<<pq.size()<<endl;
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()) {
            cnt++;
            int n = pq.size();
            for(int i=0; i<n; i++) {
                int x = pq.front().first;
                int y = pq.front().second;
                pq.pop();
                for(int j=0; j<4; j++) {
                    int nx = x + directions[j][0];
                    int ny = y + directions[j][1];
                    if(nx>=0 && nx<r && ny>=0 && ny<c && !visited[nx][ny] && grid[nx][ny]==0) {
                        visited[nx][ny] = true;
                        pq.push({nx,ny});
                    }
                }
            }
        }
        return cnt-1;
    }
};