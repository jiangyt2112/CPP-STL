#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    // 成员类型 同Array
    // 成员函数
    forward_list<int> l0;
    forward_list<int> l1(l0);
    forward_list<int> l2(10);
    forward_list<int> l3(10, 10);
    forward_list<int> l4(l0.begin(), l0.end());
    forward_list<int> l5({1, 2, 3});

    l0 = l1;
    cout << l2.front() << endl;
    for (auto iter = l2.begin(); iter != l2.end(); ++iter)
    {
        cout << *iter << endl;
    }
    // cout << l2.size() << endl; 没有size
    cout << l2.empty() << endl;
    cout << l2.max_size() << endl;
    l2.clear();
    l2.insert_after(l2.before_begin(), 11);
    l2.insert_after(l2.before_begin(), 11, 11);
    l2.insert_after(l2.before_begin(), l0.begin(), l0.end());
    l2.insert_after(l2.before_begin(), {1, 2, 3});
    cout << l2.front() << endl;
    l2.erase_after(l2.before_begin());
    l2.erase_after(l2.before_begin(), l2.end());
    l2.push_front(12);
    l2.pop_front();
    l2.swap(l0);

    l0.sort();
    l1.sort();
    l0.merge(l1);

    return 0;
}
