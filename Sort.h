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
            for (; j >= 1 && tmp < nums[j - 1]; --j) {
                nums[j] = nums[j - 1];
            }
            nums[j] = tmp;
        }
    }
    // Shell sort
    template <typename Object>
    void shellSort(vector<Object> &nums) {
        for (int gap = nums.size() / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < nums.size(); ++i) {
                Object tmp = nums[i];
                int j = i;
                for (; j >= gap && tmp < nums[j - gap]; j -= gap) {
                    nums[j] = nums[j - gap];
                }
                nums[j] = tmp;
            }
        }
    }
    // Heap sort
    template <typename Object>
    void heapSort(vector<Object> &nums) {
        int N = nums.size();
        for (int i = N / 2; i >= 0; --i) {
            percDown(nums, i, N);
        }
        for (int i = N - 1; i > 0; --i) {
            swap(nums[0], nums[i]);
            percDown(nums, 0, i);
        }
    }
    inline int lChild(const int i) const {
        return 2 * i + 1;
    }
    template <typename Object>
    void percDown(vector<Object> &nums, int beg, const int lens) {
        int child;
        Object tmp = nums[beg];
        for (; lChild(beg) < lens; beg = child) {
            child = lChild(beg);
            if (child != lens - 1 && nums[child] < nums[child + 1]) {
                ++child;
            }
            if (tmp < nums[child]) {
                nums[beg] = nums[child];
            }
            else {
                break;
            }
        }
        nums[beg] = tmp;
    }
};
#endif 
