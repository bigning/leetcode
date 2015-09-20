#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> left;
        vector<int> right;

        int left_max = height[0];
        left.push_back(0);
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] > left_max) {
                left_max = height[i];
                left.push_back(i);
            }
        }

        int right_max = height[height.size() - 1];
        right.push_back(height.size() - 1);
        for (int i = height.size() - 1; i >= 0; --i) {
            if (height[i] > right_max) {
                right_max = height[i];
                right.push_back(i);
            }
        }

        int res = 0;
        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); ++j) {
                if (right[j] <= left[i]) {
                    break;
                }
                int min = height[left[i]] < height[right[j]] ? height[left[i]] : height[right[j]];
                int tmp_res = min * (right[j] - left[i]);
                if (tmp_res > res) {
                    res = tmp_res;
                } 
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> h;
    h.push_back(1);
    h.push_back(2);
    h.push_back(3);
    h.push_back(3);
    h.push_back(2);
    h.push_back(1);
    int res = s.maxArea(h);
    std::cout << res << std::endl;

    return 0;
}
