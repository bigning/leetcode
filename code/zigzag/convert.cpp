#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> res(numRows);
        int index = 0;
        while (index < s.size()) {
            for (int i = 0; i < numRows; ++i) {
                res[i] += s[index];
                ++index;
                if (index >= s.size()) {
                    break;
                }
            }
            if (index >= s.size()) {
                break;
            }
            for (int i = numRows - 2; i >= 1; --i) {
                if (index >= s.size()) {
                    break;
                }
                res[i] += s[index];
                ++index;
                if (index >= s.size()) {
                    break;
                }
            }
        }
        string final_res = "";
        for (int i = 0; i < numRows; ++i) {
            final_res += res[i];
        }
        return final_res;
    }
};

int main() {
    string input = "PAYPALISHIRING";
    Solution s;
    string res = s.convert(input, 3);
    std::cout << res << std::endl;
    return 0;
}
