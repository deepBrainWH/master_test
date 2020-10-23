//
// Created by wangheng on 4/14/20.
//
#include <vector>
#include <iostream>
#include <deque>
#include <list>
#include <iterator>

using namespace std;

int main() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
        cout << *itr << endl;
    }

    cout << "===========================" << endl;
    for (auto &&it:vec) {
        cout << it << endl;
    }

    vector<int> vec2(vec);
    for (auto itr = vec2.begin(); itr != vec2.end(); itr++) {
        cout << *itr << endl;
    }

    deque<int> de = {3, 4, 5, 2, 1};
    de.push_front(4);
    de.push_back(-1);
    for (deque<int>::iterator itr = de.begin(); itr != de.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    //=======================list=======================
    list<int> li = {3,4,5,2,1};
    li.push_back(3);
    list<int>::iterator itr = li.begin() ;
    li.insert(itr, 4);
    for(auto &&it : li){
        cout<<it<<endl;
    }
    return 0;
}
