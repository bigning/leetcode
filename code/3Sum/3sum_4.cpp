#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int> > final_res;
        vector<int> one_res;

        if (nums.size() < 3) { return final_res; }

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) { continue; }
            int dest_sum = -nums[i];

            int start = i + 1;
            int end = nums.size() - 1;

            for (; start < end; ) {
                //std::cout << start << " " << end << std::endl;
                if (nums[start] + nums[end] == dest_sum) {
                    one_res.clear();
                    one_res.push_back(nums[i]);
                    one_res.push_back(nums[start]);
                    one_res.push_back(nums[end]);
                    final_res.push_back(one_res);
                    
                    ++start;
                    while (start < end && nums[start] == nums[start - 1]) { ++start;}
                    continue;
                }
                if (nums[start] + nums[end] < dest_sum) {
                    start++;
                    continue;
                }
                end--;
            }
        }
        return final_res;
    }
};

int main() {
    Solution s;
    std::vector<int> nums;
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(2);
    //nums.push_back(500000);
    vector<vector<int> > res = s.threeSum(nums);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
