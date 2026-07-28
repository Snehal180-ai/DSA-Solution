class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2 == 1) {
                mid = char('a' + i);
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};