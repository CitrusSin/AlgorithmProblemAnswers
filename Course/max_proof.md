# 证明擂台法求最大值算法的正确性

```pseudocode
int maxValue(int[] a) {
    int ans = a[0];
    for (int i=1; i<a.length; i++) {
        if (a[i] > ans) {
            ans = a[i];
        }
    }
    return ans;
}
```

证明：  
对于上述伪代码，传入任意长度为$n$的数组$a = \{a[0], a[1], ..., a[n]\}$，其中元素互不相同
我们采用反证法证明$maxValue(a) = \max \{a[0], a[1], ..., a[n]\}$.
若$maxValue(a) \neq \max \{a[0], a[1], ..., a[n]\}$，
根据上述代码第2行和第5行，可知存在$i$满足$0 \le i < n$，使得$maxValue(a) = a[i]$；
根据最大值概念的定义，可知存在$j$满足$0 \le j < n$，使得$\max a = a[j]$，且$\forall k (0 \le k < n \to a[j] > a[k])$；

- 若$i = j$，则$a[i] = a[j]$，$maxValue(a) = \max a$，不满足前提条件；
- 若$i < j$，则当循环执行第$j$次时，在第4行`if (a[i] > ans)`判断条件处，`ans`将会被赋为`a[j]`且不会再变小，与$maxValue(a)=a[i]$条件矛盾；
- 若$i > j$，则在循环执行第$j$次时，根据$\forall k (0 \le k < n \to a[j] > a[k])$可知代码必然进入分支条件，使得`ans = a[j]`，且此后不会再进入该分支；而当循环执行第$i$次时，在第4行`if (a[i] > ans)`判断条件处，必然进入判断分支，即`a[i] > ans`成立，此时`ans = a[j]`，即`a[i] > a[j]`，与$\forall k (0 \le k < n \to a[j] > a[k])$矛盾。

故$maxValue(a) = \max \{a[0], a[1], ..., a[n]\}$必成立。
证毕。