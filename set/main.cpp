#include <iostream>
#include <set>

using namespace std;

int main()
{
    // 成员类型
    set<int>::key_type kt;
    set<int>::value_type vt;
    set<int>::size_type st;
    set<int>::difference_type dt;
    set<int>::key_compare kc;
    set<int>::value_compare vc;
    set<int>::reference rf = vt;
    set<int>::const_reference crf = vt;
    set<int>::pointer pt = &vt;
    set<int>::const_pointer cpt = &vt;
    set<int>::iterator iter;
    set<int>::const_iterator citer;
    set<int>::reverse_iterator riter;
    set<int>::const_reverse_iterator criter;
    // 成员函数
    set<int> s0;
    set<int> s1(s0);
    set<int> s2(s0.begin(), s0.end());
    set<int> s3 = {1, 2, 3};
    s0 = s3;
    s0 = {1, 2, 3};
    for (auto iter = s0.begin(); iter != s0.end(); ++iter)
    {
        cout << *iter << endl;
    }
    cout << s0.empty() << endl;
    cout << s0.size() << endl;
    cout << s0.max_size() << endl;
    s0.clear();
    s0.insert(10);
    s0.insert(s1.begin(), s1.end());
    s0.insert({1, 3, 4});
    s0.erase(s0.begin());
    s0.erase(s0.begin(), s0.end());
    s0.erase(10);

    return 0;
}
