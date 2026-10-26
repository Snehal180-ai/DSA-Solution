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

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    priority_queue<array<int, 3>,vector<array<int, 3>>,greater<array<int, 3>>> pq;
    
    dist[0][0]=1;
    pq.push({1,0,0});

    while(!pq.empty()){
        auto[d,r,c]=pq.top();
        pq.pop();

        if(r==n-1 && c==n-1){
            return d;
        }

        for(auto[x,y]:dir){
            int nr=r+x;
            int nc=c+y;
            if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0){
                grid[nr][nc]=1;
                int newdist=d+1;
                if(newdist<dist[nr][nc]){
                    pq.push({newdist,nr,nc});
                }
            }
        }
    }
    return -1;
}
};