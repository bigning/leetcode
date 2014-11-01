#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



class Solution {
public:

	struct MyStruct
	{
		int value, index;
		bool operator<(const MyStruct & str) const
		{
			return value < str.value;
		}
	};

	vector<int> twoSum(vector<int> &numbers, int target) {

		vector<int> res;
		MyStruct tmp;
		vector<MyStruct> my_vec;
		for (int i = 0; i < numbers.size(); i++)
		{
			tmp.value = numbers[i];
			tmp.index = i + 1;
			my_vec.push_back(tmp);
		}
		sort(my_vec.begin(), my_vec.end());

		int i = 0, j = my_vec.size() - 1;
		while (1)
		{
			if (my_vec[i].value + my_vec[j].value == target)
			{
				if (my_vec[i].index < my_vec[j].index)
				{
					res.push_back(my_vec[i].index);
					res.push_back(my_vec[j].index);
					return res;
				}
				else
				{
					res.push_back(my_vec[j].index);
					res.push_back(my_vec[i].index);
					return res;
				}
			}
			if (my_vec[i].value + my_vec[j].value < target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		return res;
	}


};

int main()
{
	Solution s;
	vector<int> test_vec;
	test_vec.push_back(11);
	test_vec.push_back(7);
	test_vec.push_back(10);
	test_vec.push_back(15);

	vector<int> res;
	res = s.twoSum(test_vec, 22);
	cout<<res[0]<<endl<<res[1]<<endl;
	return 0;
}