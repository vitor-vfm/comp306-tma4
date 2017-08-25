/*
 Title: TMA4Question3.cpp
 Description: Solution for Question 3 in TMA4
 Date: August 25, 2017
 Author: Vitor Mendonca
*/

/*
 DOCUMENTATION

 Program Purpose:
    Create a container that implements a set interface using templates.

 Compile (assuming Cygwin is running): make q3
 Execution (assuming Cygwin is running): ./q3

 Notes:
    - In Cygwin, main must return type int
    - Assumes C++11 (see Makefile for reference)

 Classes:
    Set<T>: a class template that works as a generic container, including functionality
            of set membership, size, and iterating.

 Variables:
    mySet: an instance of the Set class with type parameter int,
           for testing.
    testSet: an instance of std::set with type parameter int, used to
             to test mySet.
*/

/*
 TEST PLAN

 Normal case:
    >./q3
    >Test set:
    >1 2 3 4 5
    >My set:
    >1 2 4 3 5

 Discussion:
    The main function in this file has the purpose of testing
    the behaviour of the Set class. It adds a series of elements to
    both sets and then compares the contents and size of the std::set
    with the Set, using asserts.

    It also prints, using a for-each type for loop (which uses
    iterators behind the scenes) to test the iteration in Set.

    In the output, we see that all the elements that are in testSet
    are also in mySet and that there are no duplicates. We also see
    that std::set keeps the elements sorted in its internal
    representation, whereas Set doesn't.

    This program takes no input.

*/

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cassert>

template<typename Data>
class Set {
private:
    std::vector<Data> innerSet;

public:
    class iterator;
    friend class iterator;

    class iterator {
        private:
            Data* innerPointer;

        public:
            iterator(Set<Data>& set) :
            innerPointer(set.size() > 0 ? &set.innerSet[0] : nullptr) {}

            iterator(Data* const ptr) :
            innerPointer(ptr) {}

            Data operator*() {
                return *innerPointer;
            }

            iterator operator++(int) {
                auto prev = innerPointer++;
                return iterator(prev);
            }

            iterator& operator++() {
                ++innerPointer;
                return *this;
            }

            bool operator==(const Set<Data>::iterator& other) {
                return innerPointer == other.innerPointer;
            }

            bool operator!=(const Set<Data>::iterator& other) {
                return !(*this == other);
            }

    };


    bool contains(Data d) {
        return std::count(innerSet.begin(), innerSet.end(), d) > 0;
    }

    void add(Data d) {
        if (!contains(d))
            innerSet.push_back(d);
    }

    void remove(Data d) {
        auto el = std::remove(innerSet.begin(), innerSet.end(), d);
        innerSet.erase(el, innerSet.end());
    }

    size_t size() const {
        return innerSet.size();
    }

    iterator begin() {
        return iterator(*this);
    }

    iterator end() {
        return iterator(&innerSet[0] + innerSet.size());
    }

};

#define NDEBUG
int main() {
    Set<int> mySet;
    std::set<int> testSet;

    int nums[] = {1,1,2,2,4,3,5,1,3,4};

    for (auto i : nums) {
        mySet.add(i);
        testSet.insert(i);
    }

    for (auto i : testSet) {
        assert(mySet.contains(i));
    }

    assert(testSet.size() == mySet.size());

    std::cout << "Test set: \n";
    for (auto el : testSet) {
        std::cout << el << " ";
    }
    std::cout << "\n";

    std::cout << "My set: \n";
    for (auto el : mySet) {
        std::cout << el << " ";
    }
    std::cout << "\n";
}
