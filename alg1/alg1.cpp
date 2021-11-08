#include <iostream>
#include <vector>
#include "List.h"

using namespace std;

int main()
{
    List list(12, 12, 23, 3);
    cout << "\nList list(12, 12, 23, 3) -> " << list;
    list.push_back(3);
    cout << "\nlist.push_back(3) -> " << list;
    list.insert(2, 2001);
    cout << "\nlist.insert(2, 2001) -> " << list;
    list.set(5, 2003);
    cout << "\nlist.set(5, 2003) -> " << list;
    list.pop_front();
    cout << "\nlist.pop_front() -> " << list;
    list.remove(2);
    cout << "\nlist.remove(2) -> " << list;
    cout << "\nlist.at(2) = " << list.at(2);
    cout << "\nlist.isEmpty() = " << list.isEmpty();
    list.reverse();
    cout << "\nlist.reverse() -> " << list;
    list.clear();
    cout << "\nlist.clear() -> " << list;
    cout << "\nlist.isEmpty() = " << list.isEmpty();
}