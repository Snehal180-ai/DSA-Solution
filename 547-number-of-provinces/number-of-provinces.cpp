class Solution {
public:
    void dfs(vector<vector<int>> &isConnected,int src, vector<bool> &visited){
        visited[src]=true;
        for(int v=0;v<isConnected.size();v++){
            if( isConnected[src][v]==1 && !visited[v]){
                dfs(isConnected,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};