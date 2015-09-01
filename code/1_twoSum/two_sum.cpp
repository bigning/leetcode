#include <vector>
#include <map>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> res;
        std::map<int, int> tmp_res;
        std::map<int, int>::iterator iter = tmp_res.begin();

        for (int i = 0; i < nums.size(); i++) {
            iter = tmp_res.find(nums[i]);
            if (iter == tmp_res.end()) {
                tmp_res.insert(std::pair<int, int>(target - nums[i], i));
                continue;
            }
            res.push_back(tmp_res[nums[i]] + 1);
            res.push_back(i + 1);
        }
        return res;
    }
};

int main() {
   vector<int> test_vec;
   test_vec.push_back(2);
   test_vec.push_back(7);
   test_vec.push_back(11);
   test_vec.push_back(5);

   Solution s;

   vector<int> res = s.twoSum(test_vec, 13);
   std::cout << res[0] << "  " << res[1] << std::endl;
   return 0;
}
