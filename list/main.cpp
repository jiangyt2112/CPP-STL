#include <iostream>
#include <list>

using namespace std;

int main()
{
    // 成员类型 同Array
    // 成员函数
    list<int> l0;
    list<int> l1(l0);
    list<int> l2(10);
    list<int> l3(10, 10);
    list<int> l4(l2.begin(), l2.end());
    list<int> l5({1, 2, 3});

    l0 = l5;
    cout << l0.front() << " " << l0.back() << endl;
    for (auto iter = l0.begin(); iter != l0.end(); ++iter)
    {
        cout << *iter << endl;
    }
    cout << l0.size() << endl;
    cout << l0.empty() << endl;
    cout << l0.max_size() << endl;

    l0.clear();
    l0.insert(l0.begin(), 10);
    l0.insert(l0.begin(), 10, 10);
    l0.insert(l0.begin(), l1.begin(), l1.end());
    l0.insert(l0.begin(), {1, 3, 4});
    l0.erase(l0.begin());
    l0.erase(l0.begin(), l0.end());
    l0.push_back(10);
    l0.pop_back();
    l0.push_front(1);
    l0.pop_front();

    l0.sort();
    l1.sort();
    l0.merge(l1);
    l0.reverse();
    l0.remove(10);
    return 0;
}
