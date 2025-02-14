#pragma once
#include <vector>
#include "HeapT.h"

using std::vector;

template <typename T>
vector<T> largestm(const vector<T>& vec, int m) {
    if (m <= 0) return {}; // Early return for non-positive m

    HeapT<T> minHeap(m);
    for (const T& val : vec) {
        if (minHeap.size() < m) {
            minHeap.insert(val);
        } else if (val > minHeap.peek()) {
            if (minHeap.size() > 0) minHeap.remove();
            minHeap.insert(val);
        }
    }

    vector<T> result(minHeap.size());
    for (int i = minHeap.size() - 1; i >= 0; --i) {
        result[i] = minHeap.remove();
    }

    return result;
}
