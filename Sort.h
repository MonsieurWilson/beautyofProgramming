#ifndef SORT_H
#define SORT_H

class Sort {
public:
    // Insertion sort
    template <typename Object>
    void insertionSort(vector<Object> &nums) {
        for (int i = 1; i < nums.size(); ++i) {
            Object tmp = nums[i];
            int j = i;
            for (; j > 0 && tmp < nums[j - 1]; --j) {
                nums[j] = nums[j - 1];
            }
            nums[j] = tmp;
        }
    }
};
#endif 
