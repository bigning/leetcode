#include <iostream>
#include <vector>
#include <string>
#include <climits>

class Solution {
public:
    bool isPalindrome(int x) {
        int reverse_num = 0;
        if (x < 0) {
            return false;
            x = -x;
        }
        int x_bak = x;
        while (x > 0) {
            reverse_num = reverse_num * 10 + (x % 10);
            x /= 10;
        }

        if (reverse_num > INT_MAX) {
            return false;
        }
        if (reverse_num == x_bak) {
            return true;
        }
        return false;
    }
};


int main() {
    Solution s;
    std::cout << s.isPalindrome(45654) << std::endl;
    return 0;
}
