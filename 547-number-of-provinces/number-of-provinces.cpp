class Solution {
public:
    void bfs(vector<vector<int>> &isConnected,int src, vector<bool> &visited){
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<isConnected.size();i++){
                if(isConnected[node][i]== 1 && !visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};