class Solution {
public:
    void inDeg(vector<vector<int>>& matrix, vector<vector<int>>& dir, int i, int j, vector<vector<int>> &inDegree)
    {
        int n = matrix.size(), m = matrix[0].size();
        for(int d = 0; d<dir.size(); d++)
        {
            int r = i + dir[d][0];
            int c = j + dir[d][1];
            if(r>=0 && r<n && c>=0 && c<m)
            {
                if(matrix[i][j] < matrix[r][c])
                  inDegree[r][c]++;  
            }
        }
    }
        
        
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> inDegree(n , vector<int> (m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                inDeg(matrix, dir, i, j, inDegree);
        }
        
        queue<int> que;
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                if(inDegree[i][j]==0) que.push(i*m+j);
        }
        
//         cout<<"Queue size: "<<que.size()<<" "<<que.front()<<endl;
        
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<m; j++)
//                 cout<<inDegree[i][j]<<" ";
//             cout<<endl;
//         }
        
        int level = 0;
        while(que.size()!=0)
        {
            int size = que.size();
            while(size-->0)
            {
                int idx = que.front();
                que.pop();
                int sr = idx/m, sc = idx%m; 
                cout<<sr<<" "<<sc<<endl;
                for(int d=0; d<dir.size(); d++)
                {
                    int r = sr + dir[d][0];
                    int c = sc + dir[d][1];
                    if(r>=0 && r<n && c>=0 && c<m && matrix[sr][sc]<matrix[r][c]){
                        inDegree[r][c]--;
                        if(inDegree[r][c]==0)
                            que.push(r*m+c);
                    }
                }   
            }
            level++;
        }
        //cout<<level;
        return level;
    }
};














