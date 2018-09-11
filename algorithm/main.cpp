#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

ostream& operator<< (ostream& out, const vector<int>& v)
{
    int len = v.size();
    for (int i = 0; i < len; ++i)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << v[i];
    }
    cout << endl;
}

int f()
{
    static int i = 0;
    return ++i;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    // all_of any_of none_of 全部 存在 不存在使谓词为真的元素
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
    // find_end 在一个序列中查找另一个序列，且是最后的一个出现
    vector<int> v2 = {3, 4};
    iter = find_end(v.begin(), v.end(), v2.begin(), v2.end());
    cout << *iter << endl;
    cout << distance(v.begin(), iter) << endl;
    // find_first_of 查找范围中相同的第一个元素
    cout << distance(v.begin(), find_first_of(v.begin(), v.end(), v2.begin(), v2.end())) << endl;
    // adjacent_find 查找毗邻两个元素相等
    iter = adjacent_find(v.begin(), v.end());
    cout << distance(v.begin(), iter) << endl;
    // search 查找一个序列中另一个首次出现的迭代器
    iter = search(v.begin(), v.end(), v2.begin(), v2.end());
    cout << distance(v.begin(), iter) << endl;
    // search_n 查找n个特定值的位置
    vector<int> v3 = {2, 3, 2, 2, 2, 3};
    iter = search_n(v3.begin(), v3.end(), 3, 2);
    cout << distance(v3.begin(), iter) << endl;
    // copy copy_if
    vector<int> v4(v3.size());
    copy(v3.begin(), v3.end(), v4.begin());
    copy_if(v3.begin(), v3.end(), v4.begin(), [](const int& v){ return v > 2;});
    // copy_n
    copy_n(v3.begin(), 2, v4.begin());
    // copy_backward
    vector<int> v5 = {1, 2, 3, 4};
    vector<int> v6(v5.size());
    copy_backward(v5.begin(), v5.end(), v6.end());
    cout << v6;
    // move move_backward
    move(v5.begin(), v5.end(), v6.begin());
    move_backward(v5.begin(), v5.end(), v6.end());
    // fill fill_n
    fill(v5.begin(), v5.end(), 7);
    cout << v5;
    fill_n(v5.begin(), 3, 5);
    cout << v5;
    // transform
    vector<int> v7 = {1, 2, 3, 4};
    vector<int> v8 = {1, 1, 1, 1};
    vector<int> v9(4, 0);
    transform(v7.begin(), v7.end(), v8.begin(), [](const int& v) {return v + 1;});
    cout << v8;
    transform(v7.begin(), v7.end(), v8.begin(), v9.begin(), [](const int& v1, const int& v2){return v1 + v2;});
    cout << v9;
    // generate generate_n
    generate(v9.begin(), v9.end(), f);
    cout << v9;
    generate_n(v9.begin(), 4, f);
    cout << v9;
    // remove remove_if
    iter = remove(v9.begin(), v9.end(), 5);
    cout << v9;
    v9.erase(iter, v9.end());
    cout << v9;
    remove_if(v9.begin(), v9.end(), [](const int& v) {return v > 6;});
    cout << v9;
    // remove_copy remove_copy_if
    remove_copy(v7.begin(), v7.end(), v8.begin(), 2);
    // replace replace_if
    replace(v9.begin(), v9.end(), 6, 3);
    cout << v9;
    // replace_copy replace_copy_if
    replace_copy(v9.begin(), v9.end(), v8.begin(), 1, 2);
    cout << v8 << endl;
    // swap swap_range iter_swap
    swap(v8, v9);
    swap_ranges(v8.begin(), v8.begin() + 1, v9.begin());
    iter_swap(v8.begin(), v9.begin());
    // reverse reverse_copy
    reverse(v8.begin(), v8.end());
    reverse_copy(v8.begin(), v8.end(), v7.begin());
    // rotate rotate_copy
    vector<int> v10 = {1, 2, 3, 4};
    rotate(v10.begin(), v10.begin() + 1, v10.end());
    cout << v10;
    rotate_copy(v10.begin(), v10.begin() + 1, v10.end(), v7.begin());
    cout << v7;
    // random_shuffle
    random_shuffle(v10.begin(), v10.end());
    // unique unique_copy
    unique(v10.begin(), v10.end());
    // partition partition_copy stable_partition partition_point is_partitioned
    v1 = {1, 2, 3, 4};
    partition(v1.begin(), v1.end(), [](const int& v){return v > 2;});
    cout << v1 << endl; // partition 不保序
    partition_copy(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](const int& v) {return v > 2;});
    cout << v2 << v3;
    v1 = {1, 2, 3, 4};
    stable_partition(v1.begin(), v1.end(), [](const int& v){return v > 2;});
    cout << v1; // stable_partition 保序
    cout << distance(v1.begin(), partition_point(v1.begin(), v1.end(), [](const int& v){return v > 2;})) << endl;
    cout << is_partitioned(v1.begin(), v1.end(), [](const int& v){return v < 2;}) << endl;
    // is_sorted is_sorted_until sort partial_sort partial_sort_copy stable_sort nth_element
    v1 = {1, 2, 3, 4};
    cout << is_sorted(v1.begin(), v1.end()) << endl;
    v1.push_back(3);
    cout << *is_sorted_until(v1.begin(), v1.end()) << endl;
    sort(v1.begin(), v1.end()); // sort 随机存取迭代器
    stable_sort(v1.begin(), v1.end());
    nth_element(v1.begin(), v1.begin() + 2, v1.end());
    // lower_bound upper_bound binary_search equal_range
    v1 = {1, 2, 3, 4, 5};
    cout << *lower_bound(v1.begin(), v1.end(), 2) << endl;
    cout << *upper_bound(v1.begin(), v1.end(), 2) << endl;
    cout << binary_search(v1.begin(), v1.end(), 2) << endl;
    auto x = equal_range(v1.begin(), v1.end(), 2);
    cout << *(x.first) << " " << *(x.second) <<  endl;
    // merge inplace_merge include set_difference set_intersection set_symmetric_difference set_union
    v1 = {1, 2, 3};
    v2 = {2, 3, 4};
    v3 = {1, 1, 1, 1, 1, 1};
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << v3;
    inplace_merge(v1.begin(), v1.begin() + 1, v1.end());
    cout << includes(v3.begin(), v3.end(), v1.begin(), v1.end()) << endl;
    // is_heap is_heap_until make_heap push_heap pop_heap sort_heap
    v1 = {1, 2, 3, 4};
    v2 = {1, 2, 3, 4};
    cout << is_heap(v1.begin(), v1.end()) << endl;
    cout << distance(v1.begin(), is_heap_until(v1.begin(), v1.end())) << endl;
    make_heap(v1.begin(), v1.end());
    cout << v1;
    v1.push_back(5);
    push_heap(v1.begin(), v1.end());
    cout << v1;
    pop_heap(v1.begin(), v1.end());
    cout << v1;
    make_heap(v1.begin(), v1.end());
    sort_heap(v1.begin(), v1.end());
    cout << v1;
    // max max_element min min_element minmax minmax_element
    cout << max(1, 10) << min(1, 10) << endl;
    cout << *max_element(v1.begin(), v1.end()) << " " << *min_element(v1.begin(), v1.end()) << endl;
    // equal lexicographical_compare
    cout << equal(v1.begin(), v1.end(), v2.begin()) << endl;
    cout << lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << endl;
    v1 = {1, 2, 3, 4};
    v2 = {4, 3, 2, 1};
    // is_permutation next_permutation prev_permutation
    cout << is_permutation(v1.begin(), v1.end(), v2.begin()) << endl;
    next_permutation(v1.begin(), v1.end());
    cout << v1;
    prev_permutation(v1.begin(), v1.end());
    cout << v1;
    // iota
    iota(v1.begin(), v1.end(), 1);
    cout << v1;
    // accumulate
    cout << accumulate(v1.begin(), v1.end(), 0) << endl;
    // inner_product
    v2 = {1, 2, 3, 4};
    cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0) << endl;
    // adjacent_difference partial_sum
    // uninitialized_copy uninitialized_copy_n uninitialized_fill uninitialized_fill_n
    return 0;
}
