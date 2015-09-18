#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        if (s.size() <= 1) {
            return s;
        }
        vector<int> dp(s.size());
        for (int i = 0; i < s.size(); ++i) {
            dp[i] = 1;
        }

        int last_same = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i-1]) {
                last_same = i;
            }
            if (i - 1 - dp[i - 1] >= 0 && s[i] == s[i - 1 - dp[i - 1]]) {
                dp[i] = dp[i - 1] + 2;
                continue;
            }
            if (s[i] == s[i - 1]) {
                if (i - 1 - dp[i - 1] >= 0 && s[i] != s[i - 1 - dp[i - 1]]) {
                    dp[i] = i - last_same + 1; 
                    continue;
                }
                dp[i] = i - last_same + 1;
            }
        }

        int max = 0;
        int max_index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (dp[i] >= max) {
                max = dp[i];
                max_index = i;
            }
        }
        std::cout << max << std::endl;
        result = s.substr(max_index - max + 1, max);
        return result;
    }
};

int main() {
    string str = "bb";
    Solution s;
    string res = s.longestPalindrome(str);
    std::cout << res << std::endl;
    return 0;
}
