#ifndef HEAPSORT_H
#define HEAPSORT_H

template <typename Object>
class HeapSort {
public:
    void operator () (vector<Object> &vec) {
        int lens = vec.size();
        // build heap
        for (int i = lens / 2; i >= 0; --i) {
            percDown(vec, i, lens);
        }
        for (int i = lens - 1; i > 0; --i) {
            swap(vec[0], vec[i]);
            percDown(vec, 0, i);
        }
    }
private:
    inline int lChild(const int i) const {
        return 2 * i + 1;
    }

    void percDown(vector<Object> &vec, int i, int lens) {
        int child;
        Object tmp = vec[i];
        for (; lChild(i) < lens; i = child) {
            child = lChild(i);
            if (child != lens - 1 && vec[child] < vec[child + 1]) {
                ++child;
            }
            if (tmp < vec[child]) {
                vec[i] = vec[child];
            }
            else {
                break;
            }
        }
        vec[i] = tmp;
    }
};
#endif
