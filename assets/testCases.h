#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <string>

using std::vector;
using std::string;

// Test case descriptions
const string testCaseOne = "Test 1:\n"
                           "Tests the functionality of peek, insert, and bubbleUp.\n"
                           "If you run into an error here, verify you are implementing\n"
                           "a min heap and also verify the bubbleUp algorithm.";

const string testCaseTwo = "Test 2:\n"
                           "Tests the functionality of peek, insert, and bubbleUp.\n"
                           "If you run into an error here, verify you are implementing\n"
                           "a min heap and also verify the bubbleUp algorithm.";

const string testCaseThree = "Test 3:\n"
                             "Tests the functionality of your remove function. Assuming\n"
                             "the previous tests are passed, your code can implement insert\n"
                             "decently. If this function failed, double-check your implementation\n"
                             "of remove() and bubbleDown.";

const string testCaseFour = "Test 4:\n"
                            "Tests the merge function, ensuring that all items are\n"
                            "inserted in a way that keeps the structure of a heap.";

const string testCaseFive = "Test 5:\n"
                            "Tests the functionality of the largestM function. This function\n"
                            "should return the m largest elements in descending order.";

const string testCaseSix = "Test 6:\n"
                           "If you passed testCaseFour and failed testCaseFive, ensure\n"
                           "you are taking the minimum of m and the size of the vector.";

// Test function for int outputs
void testFunction(const int output, const int expected, const float testNo, const string& details) {
    std::cout << "=========================" << std::endl;
    std::cout << "Running Test: " << testNo << std::endl;
    if (output == expected) {
        std::cout << "Test " << testNo << " Passed!" << std::endl;
        std::cout << "=========================" << std::endl;
        return;
    }
    std::cout << "Expected Output: " << expected << std::endl;
    std::cout << "Your Code Outputted: " << output << std::endl;
    std::cout << details << std::endl;
    assert(expected == output);
}

// Test function for double outputs
void testFunction(const double output, const double expected, const float testNo, const string& details) {
    std::cout << "=========================" << std::endl;
    std::cout << "Running Test: " << testNo << std::endl;
    if (output == expected) {
        std::cout << "Test " << testNo << " Passed!" << std::endl;
        std::cout << "=========================" << std::endl;
        return;
    }
    std::cout << "Expected Output: " << expected << std::endl;
    std::cout << "Your Code Outputted: " << output << std::endl;
    std::cout << details << std::endl;
    assert(expected == output);
}
