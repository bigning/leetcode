#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) {
            return s;
        }
        int max = 0;
        int max_start_ind = 0;
        int temp_max = 0;
        int temp_start_ind = 0;
        for (int i = 0; i < s.size(); ++i) {
            extend_as_long_as_possible(s, i, i, &temp_max, &temp_start_ind);
            if (temp_max >= max) {
                max = temp_max;
                max_start_ind = temp_start_ind;
            }
            extend_as_long_as_possible(s, i, i + 1, &temp_max, &temp_start_ind);
            if (temp_max >= max) {
                max = temp_max;
                max_start_ind = temp_start_ind;
            }
        }
        return s.substr(max_start_ind, max);
    }

    void extend_as_long_as_possible(string s, int i, int j, int* p_res, int* p_start) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
        }
        *p_res = j - i - 1;
        *p_start = i + 1;
    }
};

int main() {
    string str = "bananas";
    Solution s;
    string res = s.longestPalindrome(str);
    std::cout << res << std::endl;
    return 0;
}
