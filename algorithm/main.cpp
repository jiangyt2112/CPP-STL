#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    // all_of any_of none_of ȫ�� ���� ������ʹν��Ϊ���Ԫ��
    cout << all_of(v.begin(), v.end(), [](const int& v) {return v <= 5;}) << endl;
    cout << any_of(v.begin(), v.end(), [](const int& v) {return v == 3;}) << endl;
    cout << none_of(v.begin(), v.end(), [](const int& v) {return v <= 1;}) << endl;
    // for_each
    for_each(v.begin(), v.end(), [](int& n) {++n;});
    for_each(v.begin(), v.end(), [](const int& n) {cout << n << " ";});
    cout << endl;
    // count count_if
    cout << count(v.begin(), v.end(), 2) << endl;
    cout << count_if(v.begin(), v.end(), [](const int& v){return v >= 2;}) << endl;
    // mismatch
    vector<int> v1 = {2, 3, 4, 3, 5};
    auto ret = mismatch(v.begin(), v.end(), v1.begin());
    cout << *(ret.first) << " " << *(ret.second) << endl;
    // mismatch(v.begin(), v.end(), v1.begin(), v1.end());
    // mismatch(v.begin(), v.end(), v1.begin(), [](auto& x, auto& y){return x != y;});
    // find find_if find_if_not
    auto iter = find(v.begin(), v.end(), 3);
    cout << *iter << endl;
    iter = find_if(v.begin(), v.end(), [](const int& v) { return v == 4;});
    cout << *iter << endl;
    iter = find_if_not(v.begin(), v.end(), [](const int& v) { return v > 4;});
    cout << *iter << endl;
    // find_end ��һ�������в�����һ�����У���������һ������
    vector<int> v2 = {3, 4};
    iter = find_end(v.begin(), v.end(), v2.begin(), v2.end());
    cout << *iter << endl;
    cout << distance(v.begin(), iter) << endl;
    // find_first_of ���ҷ�Χ����ͬ�ĵ�һ��Ԫ��
    cout << distance(v.begin(), find_first_of(v.begin(), v.end(), v2.begin(), v2.end())) << endl;
    // adjacent_find ������������Ԫ�����
    iter = adjacent_find(v.begin(), v.end());
    cout << distance(v.begin(), iter) << endl;
    // search ����һ����������һ���״γ��ֵĵ�����
    iter = search(v.begin(), v.end(), v2.begin(), v2.end());
    cout << distance(v.begin(), iter) << endl;
    //
    return 0;
}
