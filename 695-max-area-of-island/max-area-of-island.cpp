class Solution {
    vector<vector<int>> grid;
    vector<vector<bool>> visited;

public:
    int dfs(int r, int c) {

        // Check boundaries first
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size() ||
            grid[r][c] == 0 ||
            visited[r][c])
        {
            return 0;
        }

        visited[r][c] = true;

        return 1 +
               dfs(r - 1, c) +
               dfs(r + 1, c) +
               dfs(r, c - 1) +
               dfs(r, c + 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        // Copy input grid into class member
        this->grid = grid;

        int m = grid.size();
        int n = grid[0].size();

        visited = vector<vector<bool>>(
            m, vector<bool>(n, false)
        );

        int max_area = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1 && !visited[r][c]) {
                    int curr_area = dfs(r, c);
                    max_area = max(max_area, curr_area);
                }
            }
        }

        return max_area;
    }
};