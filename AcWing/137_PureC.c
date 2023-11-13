#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<stdbool.h>

// 双端队列，单调队列的基础
struct deque {
    int *front; // 队头指针
    int *back;  // 队尾指针
    int *mem;   // 队列存储空间头部指针
    int size;   // 队列存储空间大小
};
typedef struct deque deque;

// 创建一个双端队列
// capacity: 双端队列的存储空间
deque make_deque(int capacity) {
    deque d;
    // 分配队列存储空间
    d.mem = (int*)malloc(capacity*sizeof(int));
    d.size = capacity;

    d.front = d.back = d.mem;     // 初始化队头和队尾
    return d;
}

// 销毁一个双端队列
void free_deque(deque* d) {
    free(d->mem);    // 释放其存储空间
}

// 向队尾插入数字val
void insert_back_deque(deque* d, int val) {
    if (d->back == d->mem+d->size) {    // 若队尾后无多余空间
        int n = d->back - d->front;
        memmove(d->mem, d->front, n); // 移动队列数据到存储空间开头
        d->front = d->mem;
        d->back = d->front + n;
    }

    if (d->back == d->mem+d->size) {    // 若队尾后仍然没有多于空间
        return; // 插入失败
    }

    *d->back++ = val; // 将val赋值到队尾，并且队尾前进一单位
}

// 弹出队尾
int pop_back_deque(deque* d) {
    if (d->front == d->back) {
        return -1; // 队列为空，无法弹出
    }
    return *--d->back; // 返回队尾值，队尾后退一单位
}

// 弹出队头
int pop_front_deque(deque* d) {
    if (d->front == d->back) {
        return -1;
    }
    return *d->front++;
}

// 检查队列是否为空
bool empty_deque(deque* d) {
    return d->front == d->back;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int *a = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    // 前缀和优化
    int *S = (int*)malloc(n*sizeof(int));
    S[0] = a[0];
    for (int i=1; i<n; i++) {
        S[i] = S[i-1] + a[i];
    }

    deque deq = make_deque(n);

    int max_sum = -2147483647;
    /*
    // 对每一个可能的区间[i, j]进行遍历，选出最大值存入max_sum
    for (int i=0; i<n; i++) {
        int upper = i+m; // 区间右端点，先取i+m，如果i+m超过了数组边界则取数组边界
        if (upper > n) {
            upper = n;
        }
        for (int j=i; j<upper; j++) {
            int sum = 0;
            // 计算区间[i, j]的和
            //for (int k=i; k<=j; k++) {
            //    sum += a[k];
            //}
            sum = S[j];
            if (i > 0) sum -= S[i-1];
            // 判断大小，选出最大区间和
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }
    */
    // 单调队列直接保存数字下标，方便查找
    for (int j=0; j<n; j++) {
        if (!empty_deque(&deq) && *deq.front < j-m) {
            pop_front_deque(&deq);
        }

        int sum = S[j];
        if (!empty_deque(&deq)) {
            if (S[*deq.front] <= 0 || j >= m) {
                sum -= S[*deq.front];
            }
        }
        if (sum > max_sum) max_sum = sum;

        while (!empty_deque(&deq) && S[j] < S[*(deq.back-1)]) {
            pop_back_deque(&deq);
        }
        insert_back_deque(&deq, j);
    }
    printf("%d\n", max_sum);
    free(a);
    free(S);
    free_deque(&deq);
	return 0;
}