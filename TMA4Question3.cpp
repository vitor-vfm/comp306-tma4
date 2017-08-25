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
