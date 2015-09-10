#ifndef BINARYSEARCH
#define BINARYSEARCH

class BinarySearch {
    /*
     * Binary search with two versions
     */
public:
    static int binarySearch_v1(const int *array, const int &beg, const int &end, const int &key){
        // If found the target, return its index
        // If there are not only one target in the array, return the max index
        // If no, return -1
        int mid, minidx = beg, maxidx = end - 1;
        // Notice about the loop condition, for minidx < maxidx with lead to death loop
        while (minidx < maxidx - 1){
            // Not using mid = (maxidx + minidx) / 2 to avoid overflow
            mid = minidx + (maxidx - minidx) / 2;
            if (array[mid] <= key){
                minidx = mid;
            }
            else{
                maxidx = mid;
            }
        }
        if (array[maxidx] == key){
            return maxidx;
        }
        else if (array[minidx] == key){
            return minidx;
        }
        else{
            return -1;
        }
    }
    static int binarySearch_v2(const int *array, const int &beg, const int &end, const int &key){
        // Only adapt to incresing sequence
        while (beg <= end){
            int mid = beg + (end - beg) / 2;
            if (array[mid] < key){
                beg = mid + 1;
            }
            else if (array[mid] > key){
                end = mid - 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};

#endif
