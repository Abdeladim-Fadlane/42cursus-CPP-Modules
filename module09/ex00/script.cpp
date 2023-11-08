#include <iostream>
#include <map>

template<typename K, typename V>
typename std::map<K, V>::const_iterator findClosest(const std::map<K, V>& m, const K& key) 
{
    typename std::map<K, V>::const_iterator lower = m.lower_bound(key);
    std::cout<<lower->first<<"\n";
    if (lower == m.begin())
        return lower;
    if (lower == m.end())
        return --lower;
    
    typename std::map<K, V>::const_iterator beforeLower = lower;
    --beforeLower;
     std::cout<<beforeLower->first<<"\n";
    if ((key - beforeLower->first) <= (lower->first - key))
        return beforeLower;
    else
        return lower;
}

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "One";
    myMap[3] = "Three";
    myMap[6] = "Six";
    myMap[9] = "Nine";

    int key = 5; // Key to search for

    std::map<int, std::string>::const_iterator closest = findClosest(myMap, key);

    std::cout << "Closest key: " << closest->first << ", value: " << closest->second << std::endl;

    return 0;
}
