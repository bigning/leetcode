#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool isMatch(string s, string p) {
        s = '^' + s;
        p = '^' + p;
        vector<vector<bool> > dp(s.size());
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                dp[i].push_back(false);
            }
        }
        std::cout << "ok" << std::endl;
        dp[0][0] = true;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i] == '*') {
                if (dp[0][i - 1] == true) {
                    dp[0][i] = true;
                    continue;
                }
                if (i - 2 >= 0 && dp[0][i - 2] == true) {
                    dp[0][i] = true;
                    continue;
                }
            }
        }

        for (int i = 1; i < s.size(); ++i) {
            for (int j = 1; j < p.size(); ++j) {
                if (p[j] == '*') {
                    if (dp[i][j - 1] == true) {
                        dp[i][j] = true;
                        continue;
                    }
                    if (j - 2 >= 0 && dp[i][j - 2] == true) {
                        dp[i][j] = true;
                        continue;
                    }
                    if (s[i] == s[i - 1] && dp[i - 1][j] == true && s[i] == p[j - 1]) {
                        dp[i][j] = true;
                        continue;
                    }
                    if (p[j - 1] == '.' && dp[i - 1][j] == true) {
                        dp[i][j] = true;
                    }
                }
                if (p[j] == '.' || p[j] == s[i]) {
                    if (dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[s.size() - 1][p.size() - 1];
    }
};

int main() {
    Solution S;
    bool res = S.isMatch("aaa", "ab*a");
    std::cout << res << std::endl;
    return 0;
}
