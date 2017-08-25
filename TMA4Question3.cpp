#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

template<typename Data>
class Set {
private:
    std::vector<Data> innerSet;

public:
    // TODO: make iterator

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

    size_t size() {
        return innerSet.size();
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
}
