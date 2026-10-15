class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> q;
        int freshcount=0;
        int time=-1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    freshcount++;
            }
        }
        if(freshcount==0)
            return 0;
        
        q.push({-1,-1});

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;

            if(r==-1 && c==-1){
                time++;
                if(!q.empty())
                    q.push({-1,-1});
            }
            else{
            if(r-1>=0 && grid[r-1][c]==1){
                grid[r-1][c]=2;
                freshcount--;
                q.push({r-1,c});
            }
            if(r+1<m && grid[r+1][c]==1){
                grid[r+1][c]=2;
                freshcount--;
                q.push({r+1,c});
            }
            if(c-1>=0 && grid[r][c-1]==1){
                grid[r][c-1]=2;
                freshcount--;
                q.push({r,c-1});
            }
            if(c+1<n && grid[r][c+1]==1){
                grid[r][c+1]=2;
                freshcount--;
                q.push({r,c+1});
            }
        }
        }
        return (freshcount==0)? time:-1;
    }
};