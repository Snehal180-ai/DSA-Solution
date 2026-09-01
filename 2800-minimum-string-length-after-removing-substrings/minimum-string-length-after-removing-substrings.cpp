class Solution {
public:
    int minLength(string s) {
        string st;

        for (char ch : s) {
            if (!st.empty() &&
                ((st.back() == 'A' && ch == 'B') ||
                 (st.back() == 'C' && ch == 'D'))) {
                st.pop_back();
            } 
            else {
                st.push_back(ch);
            }
        }

        return st.size();
    }
};