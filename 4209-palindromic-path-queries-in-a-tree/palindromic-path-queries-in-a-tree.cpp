class Solution {
public:
    vector<vector<int>> adj;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<int> bit;
    string s;
    int timer = 0;
    int LOG;

    void dfs(int node, int par) {
        tin[node] = ++timer;
        up[node][0] = (par == -1 ? node : par);

        for (int j = 1; j < LOG; j++) {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int nei : adj[node]) {
            if (nei == par) continue;
            depth[nei] = depth[node] + 1;
            dfs(nei, node);
        }

        tout[node] = timer;
    }

    void updateBIT(int idx, int val, int n) {
        while (idx <= n) {
            bit[idx] ^= val;
            idx += idx & -idx;
        }
    }

    int queryBIT(int idx) {
        int res = 0;
        while (idx > 0) {
            res ^= bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string str, vector<string>& queries) {
        s = str;
        adj.assign(n, {});
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        bit.assign(n + 2, 0);

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(n, vector<int>(LOG, 0));

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        timer = 0;
        dfs(0, -1);

        // Difference updates: entry and exit positions.
        for (int i = 0; i < n; i++) {
            int mask = 1 << (s[i] - 'a');
            updateBIT(tin[i], mask, n);
            updateBIT(tout[i] + 1, mask, n);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int change = oldMask ^ newMask;

                updateBIT(tin[u], change, n);
                updateBIT(tout[u] + 1, change, n);

                s[u] = c;
            } else {
                ss >> v;

                int lca = getLCA(u, v);

                int maskU = queryBIT(tin[u]);
                int maskV = queryBIT(tin[v]);
                int maskLCA = 1 << (s[lca] - 'a');

                int pathMask = maskU ^ maskV ^ maskLCA;

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};