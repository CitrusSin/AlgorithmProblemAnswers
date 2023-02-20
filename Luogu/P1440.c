#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

#define N ((int)2e6)

int arr[N], ascend_queue[N], queue_lb=0, queue_rb=0;

void pop_back_queue() {
    if (queue_rb > queue_lb) {
        queue_rb--;
    }
    if (queue_rb == queue_lb) {
        queue_lb = queue_rb = 0;
    }
}

void push_back_queue(int x) {
    if (queue_lb == 0 && queue_rb == N) {
        return; // Failed
    }
    if (queue_rb >= N) {
        memmove(ascend_queue, ascend_queue+queue_lb, (queue_rb-queue_lb)*sizeof(int));
        queue_rb -= queue_lb;
        queue_lb = 0;
    }
    ascend_queue[queue_rb++] = x;
}

void pop_front_queue() {
    if (queue_rb > queue_lb) {
        queue_lb++;
    }
    if (queue_rb == queue_lb) {
        queue_lb = queue_rb = 0;
    }
}

bool empty_queue() {
    return queue_lb == queue_rb;
}

int front_queue() {
    return ascend_queue[queue_lb];
}

int back_queue() {
    return ascend_queue[queue_rb-1];
}

int fast_read() {
    int ch = getchar();
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    
    int res = 0;
    while (ch >= '0' && ch <= '9') {
        res *= 10;
        res += (ch & 0x0f);
        ch = getchar();
    }

    return res;
}

void fast_write(int x) {
    if (x == 0) {
        putchar('0');
        return;
    }
    char st[20] = {};
    int idx = 0;
    while (x > 0) {
        st[idx++] = (x%10) | 0x30;
        x /= 10;
    }
    while (idx--) {
        putchar(st[idx]);
    }
}

int main() {
    int n, m;
    n = fast_read();
    m = fast_read();
    for (int i=0; i<n; i++) {
        arr[i] = fast_read();
    }

    for (int i=0; i<n; i++) {
        fast_write(empty_queue()?0:arr[front_queue()]);
        putchar('\n');
        while (!empty_queue() && arr[back_queue()] > arr[i]) {
            pop_back_queue();
        }
        if (!empty_queue() && front_queue() <= i-m) {
            pop_front_queue();
        }
        push_back_queue(i);
    }
    return 0;
}