#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    // 成员类型
    map<int, int>::value_type vt;
    map<int, int>::mapped_type mt;
    map<int, int>::key_type kt;
    map<int, int>::size_type st;
    map<int, int>::difference_type dt;
    map<int, int>::key_compare kc;
    map<int, int>::iterator iter;
    int a = 10;
    map<int, int>::reference rf = vt;
    map<int, int>::pointer pt;
    // 成员函数
    map<int, int> m0;
    map<int, int> m1(m0);
    map<int, int> m2(m1.begin(), m1.end());
    map<int, int> m3 = {{1, 2}, {2, 3}};
    m0 = m1;
    m2 = {{1, 2}, {2, 3}};
    m0[1] = 10;
    cout << m0[1] << endl;
    cout << m0[2] << endl;
    for (auto iter = m0.begin(); iter != m0.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << m0.empty() << endl;
    cout << m0.size() << endl;
    cout << m0.max_size() << endl;
    m0.clear();
    m0.insert({3, 10});
    m0.insert({3, 20});
    cout << m0[3] << endl;
    m0.insert(m1.begin(), m1.end());
    m0.insert({{1, 2}, {2, 3}, {3, 4}, {4, 5}});
    cout << m0[4] << endl;
    cout << m0[3] << endl;
    m0.erase(m0.begin());
    auto iter1 = m0.begin();
    advance(iter1, 1);
    m0.erase(m0.begin(), iter1);
    cout << m0.erase(3) << endl;
    cout << m0.count(3) << endl;

    return 0;
}
