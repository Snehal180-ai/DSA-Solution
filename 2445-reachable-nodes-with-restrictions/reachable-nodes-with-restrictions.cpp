class Solution {
public:
    int bfs(int start, vector<int> adj[], vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return count;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool> visited(n,false);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(auto a: restricted){
            visited[a]=true;
        }
        int count=bfs(0,adj,visited);
        return count;
    }
};