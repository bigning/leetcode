#include <string>
#include <iostream>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) { return 0; }
        map<char, int> last_ind;
        vector<int> next_ind;

        for (int i = 0; i < s.size(); i++) {
            next_ind.push_back(-1);
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (last_ind.find(s[i]) == last_ind.end()) {
                last_ind.insert(std::pair<char, int>(s[i], i));
            }
            else {
                next_ind[i] = last_ind[s[i]];
                last_ind[s[i]] = i;
            }
        }

        /*
        for (int i = 0; i < s.size(); ++i) {
            std::cout << next_ind[i] << std::endl;
        }
        */

        int left = 0;
        int right = left + 1;
        int result = 1;
        int tmp_result = 1;
        while (right < s.size()) {
            if (next_ind[right] < left) {
                ++right;
                if (right == s.size()) {
                    tmp_result = s.size() - left;
                    if (tmp_result > result) { result = tmp_result; }
                }
                continue;
            }
            tmp_result = right - left;
            left = next_ind[right] + 1;
            if (tmp_result > result) { result = tmp_result; }
        }
        return result;
    }
};


int main() {
    string s = "a";
    Solution solu;
    int res = solu.lengthOfLongestSubstring(s);
    std::cout << res << std::endl;
    return 0;
}
