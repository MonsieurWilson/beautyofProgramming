#ifndef SORT_H
#define SORT_H

class Sort {
public:
    // Insertion sort
    template <typename Object>
    void insertionSort(vector<Object> &nums) {
        insertionSort(nums, 0, nums.size() - 1);
    }
    template <typename Object>
    void insertionSort(vector<Object> &nums, const int beg, const int end) {
        for (int i = beg + 1; i <= end; ++i) {
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
    // Merge sort
    template <typename Object>
    void mergeSort(vector<Object> &nums) {
        vector<Object> tmp(nums.size());
        mergeSort(nums, tmp, 0, nums.size() - 1);
    }
    template <typename Object>
    void mergeSort(vector<Object> &nums, vector<Object> &tmp, const int beg, const int end) {
        if (beg < end) {
            int mid = beg + (end - beg) / 2;
            mergeSort(nums, tmp, beg, mid);
            mergeSort(nums, tmp, mid + 1, end);
            mergeParts(nums, tmp, beg, mid, end);
        }
    }
    template <typename Object>
    void mergeParts(vector<Object> &nums, vector<Object> &tmp, const int beg, const int mid, const int end) {
        int lBeg = beg, lEnd = mid, rBeg = mid + 1, rEnd = end;
        int pos = lBeg;
        while (lBeg <= lEnd && rBeg <= rEnd) {
            if (nums[lBeg] < nums[rBeg]) {
                tmp[pos++] = nums[lBeg++];
            }
            else {
                tmp[pos++] = nums[rBeg++];
            }
        }
        while (lBeg <= lEnd) tmp[pos++] = nums[lBeg++];
        while (rBeg <= rEnd) tmp[pos++] = nums[rBeg++];
        for (int i = beg; i <= end; ++i) {
            nums[i] = tmp[i];
        }
    }
    // Quick sort
    template <typename Object>
    void quickSort(vector<Object> &nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
    template <typename Object>
    void quickSort(vector<Object> &nums, const int beg, const int end) {
        if (end - beg > 10) {
            int mid = divTwoParts(nums, beg, end);
            quickSort(nums, beg, mid);
            quickSort(nums, mid + 1, end);
        }
        else {
            insertionSort(nums, beg, end);
        }
    }
    template <typename Object>
    int divTwoParts(vector<Object> &nums, const int beg, const int end) {
        Object pivot = median3(nums, beg, end);
        int fst = beg + 1, lst = end - 1, mid = fst - 1;
        for (int i = fst; i < lst; ++i) {
            if (nums[i] < pivot) {
                swap(nums[++mid], nums[i]);
            }
        }
        swap(nums[++mid], nums[lst]);
        return mid;
    }
    template <typename Object>
    Object median3(vector<Object> &nums, const int beg, const int end) {
        // Let num[beg] be the min of three, num[end] be the max of three,
        // num[end - 1] be the pivot, and we just need to divide the vector
        // from beg + 1 to end - 1
        int mid = beg + (end - beg) / 2;
        if (nums[mid] < nums[beg]) {
            swap(nums[mid], nums[beg]);
        }
        if (nums[end] < nums[beg]) {
            swap(nums[end], nums[beg]);
        }
        if (nums[end] < nums[mid]) {
            swap(nums[end], nums[mid]);
        }
        swap(nums[mid], nums[end - 1]);
        return nums[end - 1];
    }
    // Radix sort
    template <typename Object>
    void radixSort(vector<Object> &nums) {
        radixSort(nums, 0, nums.size() - 1);
    }
    template <typename Object>
    void radixSort(vector<Object> &nums, const int beg, const int end) {
        Object maxV = nums[beg];
        for (int i = beg + 1; i <= end; ++i) {
            maxV = max(maxV, nums[i]);
        }
        int bits = 0;
        while (maxV) {
            maxV /= 10;
            ++bits;
        }
        for (int bit = 0; bit < bits; ++bit) {
            vector<int> cnt(10, 0);
            for (int i = beg; i <= end; ++i) {
                ++cnt[getBit(nums[i], bit)];
            }
            for (int i = 1; i < 10; ++i) {
                cnt[i] += cnt[i - 1];
            }
            vector<int> bucket(end - beg + 1, 0);
            for (int i = end; i >= beg; --i) {
                bucket[--cnt[getBit(nums[i], bit)]] = nums[i];
            }
            for (int i = beg, j = 0; i <= end; ++i, ++j) {
                nums[i] = bucket[j];
            }
        }
    }
    template <typename Object>
    int getBit(const Object &num, const int bit) {
        Object tmp = num;
        for (int b = 1; b <= bit; ++b) {
            tmp /= 10;
        }
        return tmp % 10;
    }
};
#endif 
