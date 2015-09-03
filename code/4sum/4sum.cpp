#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int> > final_res;
        if (nums.size() < 4) { return final_res; }
        vector<int> one_res;
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) { continue; }
                int left = j + 1;
                int right = nums.size() - 1;
                int rest = target - nums[i] - nums[j];
                for (; left < right; ) {
                    if (nums[left] + nums[right] == rest) {
                        one_res.clear();
                        one_res.push_back(nums[i]);
                        one_res.push_back(nums[j]);
                        one_res.push_back(nums[left]);
                        one_res.push_back(nums[right]);
                        final_res.push_back(one_res);
                        ++left;
                        while (nums[left] == nums[left - 1]) {
                            ++left;
                        }
                    }
                    if (nums[left] + nums[right] > rest){
                        --right;
                        continue;
                    }
                    if (nums[left] + nums[right] < rest) {
                        ++left;
                    }
                }
            }
        }
        return final_res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);
    vector<vector<int> > res;
    res = s.fourSum(nums, 0);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
