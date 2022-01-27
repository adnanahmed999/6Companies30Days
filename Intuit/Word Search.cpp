// Question Link: https://practice.geeksforgeeks.org/problems/word-search/1/#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    bool search(vector<vector<char>>& board, string& word, int& index, int& currI, int& currJ, int& rows, int& cols, vector<vector<int>>& directions) {
        if(index==word.length()) return true;
        if(currI<0 || currI>=rows || currJ<0  || currJ>=cols) return false;
        if(board[currI][currJ]!=word[index]) return false;
        board[currI][currJ] = '0';
        int savedI = currI;
        int savedJ = currJ;
        for(int i=0; i<4; i++) {
            int nextI = savedI + directions[i][0];
            int nextJ = savedJ + directions[i][1];
            index++;
            if(search(board, word, index, nextI, nextJ, rows, cols, directions))
                return true;    
            index--;
        }
        currI = savedI;
        currJ = savedJ;
        board[currI][currJ] = word[index];
        return false;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        int rows = board.size();
        int cols = board[0].size();
        int index = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j]==word[0]) {
                    if(search(board, word, index, i, j, rows, cols, directions)) 
                        return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends