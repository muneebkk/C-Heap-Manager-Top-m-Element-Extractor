#include <iostream>
#include <vector>
#include "HeapT.h"
#include "largestm.h"
using namespace std;
// Ensure largestm is properly defined in this file

using namespace std;

void testHeapT() {
    cout << "=== Testing HeapT Class ===" << endl;

    // Basic Heap Functionality
    cout << "\n--- Basic Insert and Remove ---" << endl;
    HeapT<int> heap(5); // Heap with capacity of 5

    try {
        heap.insert(10);
        heap.insert(5);
        heap.insert(3);
        heap.insert(7);
        heap.insert(2);

        cout << "Heap after inserts (expected min at root): " << heap.peek() << endl;
        // Expected Output: Heap after inserts (expected min at root): 2

        cout << "Removing elements in order: ";
        while (heap.size() > 0) {
            cout << heap.remove() << " ";
        }
        cout << "\nExpected: 2 3 5 7 10" << endl;
        // Expected Output: Removing elements in order: 2 3 5 7 10
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    // Edge case: Removing from an empty heap
    cout << "\n--- Removing from Empty Heap ---" << endl;
    try {
        heap.remove();
    } catch (const runtime_error& e) {
        cout << "Expected error: " << e.what() << endl;
        // Expected Output: Expected error: Heap is Empty
    }

    // Edge case: Inserting into a full heap
    cout << "\n--- Inserting into Full Heap ---" << endl;
    try {
        heap.insert(1);
        heap.insert(2);
        heap.insert(3);
        heap.insert(4);
        heap.insert(5);
        heap.insert(6);  // Should trigger an error
    } catch (const runtime_error& e) {
        cout << "Expected error: " << e.what() << endl;
        // Expected Output: Expected error: Heap is Full
    }

    // Test Copy Constructor
    cout << "\n--- Copy Constructor ---" << endl;
    heap = HeapT<int>(3);
    heap.insert(1);
    heap.insert(10);
    heap.insert(5);
    HeapT<int> heapCopy(heap);
    cout << "Copy of heap peek: " << heapCopy.peek() << endl; // Expected: 1
    // Expected Output: Copy of heap peek: 1

    // Test Assignment Operator (Self-assignment)
    cout << "\n--- Assignment Operator (Self-assignment) ---" << endl;
    heap = heap;  // Should handle self-assignment without issues
    cout << "Self-assigned heap peek (should be same): " << heap.peek() << endl;
    // Expected Output: Self-assigned heap peek (should be same): 1

    // Test Assignment Operator (Deep Copy)
    cout << "\n--- Assignment Operator (Deep Copy) ---" << endl;
    HeapT<int> anotherHeap(5);
    anotherHeap.insert(100);
    anotherHeap = heap;
    cout << "Assigned heap peek (expected same as original): " << anotherHeap.peek() << endl;
    // Expected Output: Assigned heap peek (expected same as original): 1

    // Test Merge
    cout << "\n--- Merge ---" << endl;
    HeapT<int> heap1(3);
    heap1.insert(4);
    heap1.insert(1);
    HeapT<int> heap2(3);
    heap2.insert(3);
    heap2.insert(2);

    HeapT<int> mergedHeap = heap1.merge(heap2);
    cout << "Merged heap elements in order: ";
    while (mergedHeap.size() > 0) {
        cout << mergedHeap.remove() << " ";
    }
    cout << "\nExpected: 1 2 3 4" << endl;
    // Expected Output: Merged heap elements in order: 1 2 3 4

    // Verify that the original heaps were not modified
    cout << "Original heap1 size after merge (expected 2): " << heap1.size() << endl;
    cout << "Original heap2 size after merge (expected 2): " << heap2.size() << endl;
    // Expected Output:
    // Original heap1 size after merge (expected 2): 2
    // Original heap2 size after merge (expected 2): 2
}

void testLargestm() {
    cout << "\n=== Testing largestm Function ===" << endl;

    // Basic Test
    vector<double> vec1 = {10, 5, 2, 8, 6, 4, 3, 9, 1};
    int m1 = 4;
    cout << "\n--- Basic Test ---" << endl;
    vector<double> result1 = largestm(vec1, m1);
    cout << "Input: {10, 5, 2, 8, 6, 4, 3, 9, 1}, m = 4\nExpected: {10, 9, 8, 6}\nResult: ";
    for (int val : result1) cout << val << " ";
    cout << endl;
    // Expected Output: Result: 10 9 8 6

    // Edge case: m = 1

    // Expected Output: Result: -1 -3 -5
}

int main() {
    testHeapT();
    cout << "=========================" << endl;
    testLargestm();
    return 0;
}
