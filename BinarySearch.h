#ifndef BINARYSEARCH
#define BINARYSEARCH

class BinarySearch{
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
		int first = beg, last = end - 1;
		int mid;
		bool found = false;
		while (first < last && found == false){
			mid = first + (last - first) / 2;
			if (array[mid] < key){
				first = mid + 1;
			}
			else if (array[mid] > key){
				last = mid - 1;
			}
			else{
				found = true;
			}
		}
		if (found == true){
			return mid;
		}
		else{
			return -1;
		}
	}
};

#endif
