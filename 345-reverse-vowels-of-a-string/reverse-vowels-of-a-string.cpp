
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right &&
                   string("aeiouAEIOU").find(s[left]) == string::npos) {
                left++;
            }

            while (left < right &&
                   string("aeiouAEIOU").find(s[right]) == string::npos) {
                right--;
            }
            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};
