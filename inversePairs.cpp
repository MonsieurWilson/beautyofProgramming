#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int inversePairs(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> cp(nums.size());
        return inversePairs(nums, cp, 0, nums.size() - 1);
    }
    int inversePairs(vector<int> &nums, vector<int> &cp, const int beg, const int end) {
        if (beg == end) {
            cp[beg] = nums[beg];
            return 0;
        }
        int mid = beg + (end - beg) / 2;
        int left = inversePairs(nums, cp, beg, mid), right = inversePairs(nums, cp, mid + 1, end);
        int lBeg = beg, lEnd = mid, rBeg = mid + 1, rEnd = end, cpIdx = end;
        int cnt = 0;
        while (lEnd >= lBeg && rEnd >= rBeg) {
            if (nums[lEnd] > nums[rEnd]) {
                cp[cpIdx--] = nums[lEnd--];
                cnt += rEnd - mid;
            }
            else {
                cp[cpIdx--] = nums[rEnd--];
            }
        }
        for (; lEnd >= lBeg; --lEnd) {
            cp[cpIdx--] = nums[lEnd];
        }
        for (; rEnd >= rBeg; --rEnd) {
            cp[cpIdx--] = nums[rEnd];
        }
        for (int i = beg; i <= end; ++i) {
            nums[i] = cp[i];
        }
        return cnt + left + right;
    }
};
    
int main() {
    Solution s;
    cout << "Input the vector's size:" << endl;
    int lens;
    while (cin >> lens) {
        vector<int> nums(lens);
        for (int i = 0; i < lens; ++i) {
            cin >> nums[i];
        }
        cout << "The number of inverse pairs is: " << s.inversePairs(nums) << endl;
    }
    return 0;
}
