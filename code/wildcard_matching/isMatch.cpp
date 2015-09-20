#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == p) {
            return true;
        }
        if (s.size() == 0 && p.size() == 1 && p[0] == '*') return true;
        if (s.size() == 0 || p.size() == 0) return false;


        int start = 0;
        for (; start < s.size() && start < p.size(); ++start) {
            if (s[start] == p[start] || p[start] == '?') {
                continue;
            }
            if (p[start] == '*') {
                break;
            }
            return false;
        }


        s = s.substr(start, s.size() - start);
        p = p.substr(start, p.size() - start);
        if (s.size() == 0 && p.size() == 1 && p[0] == '*') return true;
        if (s.size() == 0 || p.size() == 0) return false;

        
        start = 0;
        for (; start < s.size() && start < p.size(); ++start) {
            if (s[s.size() - 1 - start] == p[p.size() - 1 - start] || p[p.size() - 1 - start] == '?') {
                continue;
            }
            if (p[p.size() - 1 - start] == '*') {
                break;
            }
            return false;
        }
        s = s.substr(0, s.size() - start);
        p = p.substr(0, p.size() - start);
        if (s.size() == 0 && p.size() == 1 && p[0] == '*') return true;
        if (s.size() == 0 || p.size() == 0) return false;

        vector<vector<bool> > dp(s.size());
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                dp[i].push_back(false);
            }
        }

        bool last_column_has_match = false;
        int last_column_first_match = -1;
        if (p[0] == '*' || p[0] == '?' || p[0] == s[0]) {
            dp[0][0] = true;
            last_column_has_match = true;
            last_column_first_match = 0;
        }
        if (p[0] == '*') {
            for (int i = 1; i < s.size(); ++i) {
                dp[i][0] = true;
            }
        }

        for (int j = 1; j < p.size(); ++j) {
            bool this_column_has_match = false;
            int this_column_first_match = -1;
            for (int i = 0; i < s.size(); ++i) {
                if ((s[i] == p[j] || p[j] == '?')&& i - 1 >= 0) {
                    if (dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                        if (!this_column_has_match) {
                            this_column_has_match = true;
                            this_column_first_match = i;
                        }
                        continue;
                    }
                }

                if (p[j] == '*') {
                    if (last_column_has_match && i >= last_column_first_match) {
                        dp[i][j] = true;
                        if (!this_column_has_match) {
                            this_column_has_match = true;
                            this_column_first_match = i;
                        }
                        continue;
                    }
                }
            }
            last_column_has_match = this_column_has_match;
            last_column_first_match = this_column_first_match;
        }
        return dp[s.size() - 1][p.size() - 1];
    }
};

int main() {
    Solution S;
    bool res = S.isMatch("aa", "*");
    std::cout << res << std::endl;
    return 0;
}
