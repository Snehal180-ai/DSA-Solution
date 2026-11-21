class Solution {
public:
    vector<int> answer;

    void dfs(int u, vector<vector<int>>& children, string& s,
             vector<vector<int>>& path, vector<int>& newParent) {
        
        int c = s[u] - 'a';

        if (!path[c].empty()) {
            newParent[u] = path[c].back();
        }

        path[c].push_back(u);

        for (int v : children[u]) {
            dfs(v, children, s, path, newParent);
        }

        path[c].pop_back();
    }

    int calculate(int u, vector<vector<int>>& newTree) {
        int size = 1;

        for (int v : newTree[u]) {
            size += calculate(v, newTree);
        }

        answer[u] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<vector<int>> path(26);

        dfs(0, children, s, path, newParent);

        vector<vector<int>> newTree(n);

        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        answer.assign(n, 0);

        calculate(0, newTree);

        return answer;
    }
};