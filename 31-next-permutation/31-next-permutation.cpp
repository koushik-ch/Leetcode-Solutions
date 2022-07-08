class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakPoint = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            breakPoint = i;
            break;
        }
    }

    if (breakPoint == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > breakPoint; i--)
    {
        if (nums[i] > nums[breakPoint])
        {
            swap(nums[i], nums[breakPoint]);
            break;
        }
    }
    reverse(nums.begin() + breakPoint + 1, nums.end());

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    }
};