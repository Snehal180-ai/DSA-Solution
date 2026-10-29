class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<char, char> nextSlot = {
            {'0', '1'}, {'1', '2'}, {'2', '3'}, {'3', '4'},
            {'4', '5'}, {'5', '6'}, {'6', '7'}, {'7', '8'},
            {'8', '9'}, {'9', '0'}
        };

        unordered_map<char, char> prevSlot = {
            {'0', '9'}, {'1', '0'}, {'2', '1'}, {'3', '2'},
            {'4', '3'}, {'5', '4'}, {'6', '5'}, {'7', '6'},
            {'8', '7'}, {'9', '8'}
        };

        queue<string> q;
        unordered_set<string> visited(deadends.begin(), deadends.end());

        if (visited.count("0000"))
            return -1;

        q.push("0000");
        visited.insert("0000");

        int turns = 0;

        while (!q.empty()) {
            int level_size = q.size();

            while (level_size--) {
                string currComb = q.front();
                q.pop();

                if (currComb == target)
                    return turns;

                for (int wheel = 0; wheel < 4; wheel++) {

                    // Rotate forward
                    string newComb = currComb;
                    newComb[wheel] = nextSlot[currComb[wheel]];

                    if (!visited.count(newComb)) {
                        q.push(newComb);
                        visited.insert(newComb);
                    }

                    // Rotate backward
                    newComb = currComb;
                    newComb[wheel] = prevSlot[currComb[wheel]];

                    if (!visited.count(newComb)) {
                        q.push(newComb);
                        visited.insert(newComb);
                    }
                }
            }

            turns++;
        }

        return -1;
    }
};