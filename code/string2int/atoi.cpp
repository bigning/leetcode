#include <iostream>
#include <string>
#include <vector>
#include <climits>

using std::string;
using std::vector;

class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int sign_flag = 1;
        int space_num = 0;
        while (space_num < str.size() && str[space_num] == ' ') {
            ++space_num;
        }
        str = str.substr(space_num, str.size() - space_num);

        if (str[0] == '-') {
            sign_flag = -1;
            str = str.substr(1, str.size() - 1);
        }
        else if (str[0] == '+') {
            sign_flag = 1;
            str = str.substr(1, str.size() - 1);
        }
        
        int zero_num = 0;
        while (zero_num < str.size() && str[zero_num] == '0') {
            ++zero_num;
        }
        str = str.substr(zero_num, str.size() - zero_num);
        for (int i = 0; i < str.size(); i++) {
            int digit = str[i] - '0';
            if (digit < 0 || digit > 9) {
                return res * sign_flag;
            }
            res = res * 10 + digit;
            if (res > INT_MAX) {
                if (res * sign_flag > INT_MAX) {
                    return INT_MAX;
                }
                if (res * sign_flag < INT_MIN) {
                    return INT_MIN;
                }
            }
        }

        if (sign_flag == -1) {
            res = -res;
        }
        return res;
    }
};

int main() {
    Solution s;
    int res = s.myAtoi("12a9");
    std::cout << res << std::endl;
    return 0;
}
