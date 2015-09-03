#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int global_res = nums[0] + nums[1] + nums[2];
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            int local_res = nums[i] + nums[left] + nums[right];

            for ( ;left < right; ) {
                int tmp_res = nums[i] + nums[left] + nums[right];
                if (abs(tmp_res - target) <= abs(local_res - target)) { local_res = tmp_res;}
                if (tmp_res == target) {
                    return target;
                }
                if (tmp_res < target) {
                    ++left;
                    continue;
                }
                if (tmp_res > target) {
                    --right;
                    continue;
                }
            }

            if (abs(local_res - target) < abs(global_res - target)) {
                global_res = local_res;
            }
        }
        return global_res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(-4);
    nums.push_back(2);
    nums.push_back(1);
    int res = s.threeSumClosest(nums, 1);
    std::cout << res << std::endl;
}
