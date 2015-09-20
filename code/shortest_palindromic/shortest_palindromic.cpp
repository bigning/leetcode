#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }

        if (s.size() == 2) {
            if (s[0] == s[1]) {
                return s;
            }
            string res = s[1] + s;
            return res;
        }
        int loc = 0;
        int type = 0;
        optimize_position(s, &loc, &type);
        std::cout << loc << " " << type << std::endl;
        int left = 0;
        int right = 0;
        if (type == 1) {
            right = 2 * loc + 1;
        }
        else {
            right = 2 * loc + 2;
        }
        string res = s;
        while (right <= s.size() - 1) {
            res = s[right] + res;
            ++right;
        }
        return res;
    }

    void optimize_position(string s, int* loc, int* type) {
        int s_size = s.size();
        int res1 = 0;
        int res2 = 0;
        for (int i = (s_size - 1) / 2; i >= 0; --i) {
            int left = i - 1; 
            int right = i + 1;
            bool valid = true;
            while (left >= 0) {
                if (s[left] == s[right]) {
                    --left;
                    ++right;
                }
                else {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res1 = i;
                break;
            }
        }

        bool g_valid = false;
        for (int i = (s_size - 1) / 2; i >= 0; --i) {
            int left = i;
            int right = i + 1;
            bool valid = true;
            while (left >= 0 && right <= s_size - 1) {
                if (s[left] == s[right]) {
                    --left;
                    ++right;
                }
                else {
                    valid = false;
                    break;
                }
            }
            if (left >= 1) {
                continue;
            }
            if (valid) {
                res2 = i;
                g_valid = true;
                break;
            }
        }
        if (g_valid == false) {
            res2 = -1;
        }

        std::cout << res1 << std::endl;
        std::cout << res2 << std::endl;
        if (res1 > res2) { 
            *loc = res1;
            *type = 1;
            return;
        }
        if (res1 == res2) {
            *loc = res2;
            *type = 2;
            return;
        }

        *loc = res2;
        *type = 2;
    }
};

int main() {
    Solution s;
    string test = "acbbbc";
    string res = s.shortestPalindrome(test);
    std::cout << res << std::endl;
    return 0;
}
