class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int freq[26] = {0};

        for (string word : words) {
            for (char ch : word) {
                freq[ch - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] % n != 0)
                return false;
        }

        return true;
    }
};