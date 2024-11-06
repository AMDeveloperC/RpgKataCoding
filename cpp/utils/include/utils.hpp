#ifndef UTILS
#define UTILS

#include <vector>
#include <unordered_map>
#include <unordered_set>

template <typename T>
inline bool areAllies(const std::vector<T>& origin, const std::vector<T>& modified) {
    if (origin.empty() && modified.empty()) return true;
    std::unordered_map<int, T> elem2freq;
    for (const T& elem : origin) {
        ++elem2freq[elem];
    }
    for (const T& elem : modified) {
        if (elem2freq.find(elem) != elem2freq.end()) return true;
    }
    return false;
}

#endif