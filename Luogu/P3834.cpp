#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

class FuncSegTree {
private:
    i64 value, lazyTag;
    size_t leftBound, rightBound;
    shared_ptr<const FuncSegTree> mLeftChild;
    shared_ptr<const FuncSegTree> mRightChild;
public:
    FuncSegTree(size_t l, size_t r) : value(0), lazyTag(0), leftBound(l), rightBound(r) {}

    bool hasLeftChild() const {
        return mLeftChild != nullptr;
    }

    bool hasRightChild() const {
        return mRightChild != nullptr;
    }

    const FuncSegTree leftChild() const {
        return *mLeftChild;
    }

    const FuncSegTree rightChild() const {
        return *mRightChild;
    }

    const FuncSegTree setLeftChild(const FuncSegTree& subtree) const {
        FuncSegTree ptree = *this;
        ptree.mLeftChild = make_shared<const FuncSegTree>(subtree);
        return ptree;
    }

    const FuncSegTree setRightChild(const FuncSegTree& subtree) const {
        FuncSegTree ptree = *this;
        ptree.mRightChild = make_shared<const FuncSegTree>(subtree);
        return ptree;
    }

    const FuncSegTree pushUp(i64 value) const {
        FuncSegTree ptree = *this;
        ptree.lazyTag += value;
        return ptree;
    }

    const FuncSegTree pushDown() const {
        FuncSegTree ptree = *this;
        if (ptree.lazyTag == 0) return ptree;
        if (ptree.leftBound == ptree.rightBound) return ptree;

        if (!ptree.hasLeftChild()) {
            size_t mid = ptree.leftBound + (ptree.rightBound - ptree.leftBound) / 2;
            ptree = ptree.setLeftChild(FuncSegTree(ptree.leftBound, mid).pushUp(lazyTag))
                         .setRightChild(FuncSegTree(mid+1, ptree.rightBound).pushUp(lazyTag));
            ptree.lazyTag = 0;
            return ptree;
        }

        const FuncSegTree newLeft = ptree.leftChild().pushUp(lazyTag), newRight = ptree.rightChild().pushUp(lazyTag);
        return ptree.setLeftChild(newLeft).setRightChild(newRight);
    }
};

int main() {
    FuncSegTree segt(0, 0, 5);
    
    return 0;
}