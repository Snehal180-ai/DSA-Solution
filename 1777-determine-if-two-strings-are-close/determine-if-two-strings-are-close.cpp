
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Count character frequencies
        for (char c : word1) {
            freq1[c - 'a']++;
        }

        for (char c : word2) {
            freq2[c - 'a']++;
        }

        // Condition 1: Both strings must have the same characters
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0) != (freq2[i] == 0)) {
                return false;
            }
        }

        // Condition 2: Frequencies must match after sorting
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};
