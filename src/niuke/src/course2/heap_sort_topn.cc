//
// Created by wangheng on 4/26/20.
//
#include <iostream>
#include <vector>

using namespace std;

void adjust_heap(vector<int> &heap, int top) {
    //从第i个节点调整堆
    int len = heap[0];
    int tmp = heap[top];
    int i = top * 2;
    while (i <= len) {
        if (i + 1 <= len && heap[i + 1] < heap[i]) {
            i++;
        }
        if (heap[i] > tmp) {
            break;
        }
        heap[top] = heap[i];
        top = i;
        i *= 2;
    }
    heap[top] = tmp;
}

void insert_heap(vector<int> &heap, int val) {
    heap.push_back(val);
    heap[0]++;
    int parent = heap[0] / 2;
    int child = heap[0];
    int tmp = heap[child];
    while (parent > 0) {
        if (heap[child] > heap[parent]) {
            heap[child] = heap[parent];
            child = parent;
            parent = child / 2;
        } else {
            break;
        }
    }
    heap[child] = tmp;
}

int delete_heap(vector<int> &heap) {
    int size = heap[0];
    int res = heap[1];
    heap[1] = heap[size];
    heap[0] = heap[0] - 1;
    heap.pop_back();
    adjust_heap(heap, 1);
    return res;
}

void create_heap(vector<int> &heap) {
    int len = heap[0];//第0号元素存储heap的长度
    for (int i = len / 2; i > 0; i--) {
        adjust_heap(heap, i);
    }
}

vector<int> topn(vector<int> data_source, int n) {
    vector<int> result;
    result.push_back(n);
    int i = 0;
    for (; i < n; i++) {
        result.push_back(data_source[i]);
    }
    create_heap(result);
    while (i < data_source.size()) {
        if (data_source[i] > result[1]) {
            result[1] = data_source[i];
            adjust_heap(result, 1);
        }
        i++;
    }
    return result;
}


int main() {

    vector<int> a = {3, 4, 2, 5, 2, 1, 5, 64, 2, 12, 43, 623, 12, 12, 3, 435, 34, 23, 234, 123, 111, 67, 87, 543, 12,
                     90, 342, 567, 333, 11, 3, 34, 4453, 323, 908};
    vector<int> result = topn(a, 5);
    while(result.size() > 1){
        cout<<delete_heap(result)<<" ";
    }
    return 0;
}

