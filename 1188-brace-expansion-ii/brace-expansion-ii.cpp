class Solution {
public:
    string s;
    int i = 0;

    set<string> parseExpression() {
        set<string> res = parseTerm();

        while (i < s.size() && s[i] == ',') {
            i++;
            set<string> temp = parseTerm();
            res.insert(temp.begin(), temp.end());
        }

        return res;
    }

    set<string> parseTerm() {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur;

            if (s[i] == '{') {
                i++;
                cur = parseExpression();
                i++;
            } else {
                cur.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (const string &a : res) {
                for (const string &b : cur) {
                    temp.insert(a + b);
                }
            }

            res = temp;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};