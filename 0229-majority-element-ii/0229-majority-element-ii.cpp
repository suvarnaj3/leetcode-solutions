class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Phase 1: find up to two candidates
        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && nums[i] != el2) {
                count1 = 1;
                el1 = nums[i];
            }
            else if (count2 == 0 && nums[i] != el1) {
                count2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) {
                count1++;
            }
            else if (nums[i] == el2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Phase 2: verify the candidates
        vector<int> ls;
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1) count1++;
            else if (nums[i] == el2) count2++;
        }

        int mini = nums.size() / 3 + 1;
        if (count1 >= mini) ls.push_back(el1);
        if (count2 >= mini) ls.push_back(el2);

        return ls;
    }
};