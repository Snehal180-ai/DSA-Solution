class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();

    if(n==0||grid[0][0]==1||grid[n-1][n-1]==1)
        return -1;
    if(n==1)
        return 1;

    vector<pair<int,int>> dir={
        {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}
    };

    queue<array<int,3>> q;

    q.push({0,0,1});
    grid[0][0]=1;

    while(!q.empty()){
        auto[r,c,d]=q.front();
        q.pop();

        if(r==n-1 && c==n-1){
            return d;
        }

        for(auto[x,y]:dir){
            int nr=r+x;
            int nc=c+y;
            if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0){
                grid[nr][nc]=1;
                q.push({nr,nc,d+1});
            }
        }
    }
    return -1;
}
};