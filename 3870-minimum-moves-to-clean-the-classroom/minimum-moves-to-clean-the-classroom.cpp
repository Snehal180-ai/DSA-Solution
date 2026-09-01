class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        pair<int, int> start;
        vector<pair<int, int>> litter;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    start = {i, j};
                }
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int L = litter.size();

        if (L == 0)
            return 0;

        vector<vector<int>> litterIndex(
            m, vector<int>(n, -1)
        );

        for (int i = 0; i < L; i++) {
            litterIndex[litter[i].first][litter[i].second] = i;
        }

        int targetMask = (1 << L) - 1;

        vector<vector<int>> best(
            1 << L,
            vector<int>(m * n, -1)
        );

        queue<array<int, 5>> q;

        q.push({
            start.first,
            start.second,
            0,
            energy,
            0
        });

        best[0][start.first * n + start.second] = energy;

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int row = current[0];
            int col = current[1];
            int mask = current[2];
            int remainingEnergy = current[3];
            int moves = current[4];

            if (remainingEnergy == 0)
                continue;

            for (auto &dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow < 0 || newRow >= m ||
                    newCol < 0 || newCol >= n) {
                    continue;
                }

                if (classroom[newRow][newCol] == 'X')
                    continue;

                int newEnergy = remainingEnergy - 1;
                int newMask = mask;

                if (classroom[newRow][newCol] == 'L') {
                    int id = litterIndex[newRow][newCol];
                    newMask |= (1 << id);
                }

                if (classroom[newRow][newCol] == 'R') {
                    newEnergy = energy;
                }

                if (newMask == targetMask) {
                    return moves + 1;
                }

                int position = newRow * n + newCol;

                if (newEnergy > best[newMask][position]) {
                    best[newMask][position] = newEnergy;

                    q.push({
                        newRow,
                        newCol,
                        newMask,
                        newEnergy,
                        moves + 1
                    });
                }
            }
        }

        return -1;
    }
};