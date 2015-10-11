#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> hashMap;
        int tmp = 0;

        for(int i = 0; i < nums.size(); i++)
            hashMap[nums[i]] = i;

        for(int j = 0; j < nums.size(); j++)
        {
            tmp = target - nums[j];
            if (hashMap.find(tmp) != hashMap.end() && hashMap[tmp] > j)
            {
                result.push_back(j + 1);
                result.push_back(hashMap[tmp] + 1);
                return result;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    for (int i = 1; i < 10; i++)
        nums.push_back(i);
    vector<int> res = s.twoSum(nums, 9);

    cout << nums[res[0] - 1] << "+" << nums[res[1] - 1] << "=" << 9 << endl;
    return 0;
}
