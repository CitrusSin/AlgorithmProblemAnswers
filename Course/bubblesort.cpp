#include <functional>
#include <iostream>
#include <iterator>
#include <cinttypes>
#include <vector>

using namespace std;

template <
    typename Iter,
    auto comparator = std::less<typename iterator_traits<Iter>::value_type>(),
    typename Callback
>
void bubble_sort(Iter it, Iter sentinel, Callback stage_callback) {
    using T = typename iterator_traits<Iter>::value_type;

    size_t n = sentinel - it;
    while (n--) {
        Iter pt = it;
        bool finish = true;
        for (size_t i = 0; i < n; i++) {
            Iter pt2 = pt;
            pt2++;
            if (pt2 == sentinel) break;

            if (comparator(*pt2, *pt)) {
                T tmp = *pt;
                *pt = *pt2;
                *pt2 = tmp;
                finish = false;
            }
            pt = pt2;
        }
        stage_callback();
        if (finish) return;
    }
}

int main() {
    cout << "输入数组长度：";
    size_t n;
    cin >> n;

    cout << "输入数组：";
    vector<int64_t> arr(n);
    for (size_t i=0; i<n; i++) {
        cin >> arr[i];
    }

    int stage_count = 0;
    auto callback = [&]() {
        cout << "第" << stage_count << "次循环结果：" << '\n';
        for (int64_t num : arr) {
            cout << num << ' ';
        }
        cout << '\n';
        stage_count++;
    };

    cout << "开始冒泡排序：\n";

    bubble_sort(arr.begin(), arr.end(), callback);
    cout << "结束冒泡排序。\n";

    cout << "最终结果：\n";
    for (int64_t num : arr) {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}