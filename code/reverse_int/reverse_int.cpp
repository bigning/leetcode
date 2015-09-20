#include <iostream>
#include <vector>
#include <string>
#include <climits>

using std::string;
using std::vector;

class Solution {
public:
    int reverse(int x) {
        int sign_flag = 1;
        if (x < 0) {
            sign_flag = -1;
            x = -x;
        }
        vector<int> chars;
        if (x == 0) {
            return x;
        }
        long long res = 0;
        while (x > 0) {
            int digit = x % 10;
            int res_bak = res;
            res = res * 10 + digit;
            if (res < res_bak) {
                return 0;
            }
            x = x / 10;
        }
        if (res > INT_MAX) {
            return 0;
        }
        if (sign_flag < 0) {
            res = res * -1;
        }
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.reverse(-1563847412) << std::endl;
    return 0;
}
