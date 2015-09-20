#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num_size = nums1.size() + nums2.size();
        double res = 0;
        if (num_size % 2 == 1) {
            int int_res = 0;
            find_kth_num(nums1, nums2, num_size / 2, 0, nums1.size(), 0, nums2.size(), &int_res);
            res = int_res;
            return res;
        } 
        int res1 = 0;
        int res2 = 0;
        find_kth_num(nums1, nums2, num_size / 2 - 1, 0, nums1.size(), 0, nums2.size(), &res1);
        find_kth_num(nums1, nums2, num_size / 2, 0, nums1.size(), 0, nums2.size(), &res2);

        std::cout << res1 << std::endl;
        //:w
        std::cout << res2 << std::endl;

        res = ((double)(res1) + (double)(res2)) / 2.0;
        return res;
    }

    void find_kth_num(vector<int>& num1, vector<int>& num2, int k, int left1, int right1, int left2, int right2, int* p_res) {

        if (right1 - left1 + right2 - left2 < 10) {
            vector<int> v;
            for (int i = left1; i < right1; ++i) {
                v.push_back(num1[i]);
            }
            for (int i = left2; i < right2; ++i) {
                v.push_back(num2[i]);
            }
            std::sort(v.begin(), v.end());
            *p_res = v[k];
            return;
        }

        std::cout << left1 << " " << right1 << " " << left2 << " " << right2 << " k:" << k << std::endl;

        if (k == 0) {
            if (right1 <= left1) {
                *p_res = num2[left2];
                return;
            }
            if (right2 <= left2) {
                *p_res = num1[left1];
                return;
            }
        }
        if (k == 0) {*p_res = (num1[left1] < num2[left2] ? num1[left1] : num2[left2]); return; }
        
        if (right1 == left1 + 1) {
            vector<int> final_res;
            final_res.push_back(num1[left1]);
            for (int i = left2; i < right2; ++i) {
                final_res.push_back(num2[i]);
            }
            std::sort(final_res.begin(), final_res.end());
            *p_res = final_res[k];
            return;
        }
        if (right2 == left2 + 1) {
            vector<int> final_res;
            final_res.push_back(num2[left2]);
            for (int i = left1; i < right1; ++i) {
                final_res.push_back(num1[i]);
            }
            std::sort(final_res.begin(), final_res.end());
            *p_res = final_res[k];
            return;
        }

        if (right1 <= left1) {
            *p_res = num2[left2 + k];
            return;
        }
        if (right2 <= left2) {
            *p_res = num1[left1 + k];
            return;
        }

        int middle_val1 = num1[(left1 + right1) / 2];
        if (middle_val1 >= num1[right1 - 1] && middle_val1 >= num2[right2 - 1]) {
            --right1;
            find_kth_num(num1, num2, k, left1, right1, left2, right2, p_res);
            return;
        }

        int rank_in_array2 = 0;
        find_rank(num2, left2, right2, middle_val1, &rank_in_array2);
        //std::cout << "find rank res, " << left2 << " " << right2 << " " << middle_val1 << " " << rank_in_array2 << std::endl;
        int num_less_than_val = (left1 + right1) / 2 - left1 + rank_in_array2 + 1;

        std::cout << "middle val " << middle_val1 << " left has " << (left1 + right1) / 2 + 1 - left1 << "  right has " << rank_in_array2 << std::endl;

        if (k < num_less_than_val) {
            int new_right2 = left2 + rank_in_array2  < right2? left2 + rank_in_array2 : right2;
            int new_right1 = (left1 + right1) / 2 + 1 < right1 ? (left1 + right1) / 2 + 1 : right1;
            find_kth_num(num1, num2, k, left1, new_right1, left2, new_right2, p_res);
            return;
        }
        find_kth_num(num1, num2, k - num_less_than_val, (left1 + right1) / 2 + 1, right1, left2 + rank_in_array2 , right2, p_res);
    }

    void find_range(vector<int>& num, int left, int right, int* p_new_left, int* p_right) {
    }

    void find_rank(vector<int>& num, int left, int right, int val, int* rank) {
        int ini_left = left;
        if (val <= num[left]) {
            *rank = 0;
            return;
        }
        if (val >= num[right - 1]) {
            *rank = right - left;
            return;
        }
        int middle = (left + right) / 2;
        while (right >= left + 2) {
            std::cout << "find rank left and right: " << left << " " << right << std::endl;

            if (num[middle] == val) {
                *rank = middle - left;
                return;
            }
            if (val < num[middle]) {
                right = middle;
            }
            else {
                left = middle;
            }
            middle = (left + right) / 2;
        }
        *rank = right - ini_left;
    }
};
 
int main() {
    vector<int> num1;
    num1.push_back(1);
    num1.push_back(10);

    vector<int> num2;
    num2.push_back(2);
    num2.push_back(3);
    num2.push_back(4);
    num2.push_back(5);
    num2.push_back(6);
    num2.push_back(7);
    num2.push_back(8);
    num2.push_back(9);
    Solution s;
    double res = s.findMedianSortedArrays(num1, num2);
    std::cout << res << std::endl;
    return 0;
}
