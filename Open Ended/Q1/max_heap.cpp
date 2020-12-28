// Given an array of N distinct elements,
// the task is to find all elements in array except two greatest elements.

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

vector<int> worker(vector<int> arr) {
    vector<int> res;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    for (int i = 0; i < (int)arr.size(); ++i) {
        maxHeap.push(arr[i]);
    }
    if (maxHeap.size() <= 2)
        cout << "Size too small \n";
    else {
        maxHeap.pop();
        maxHeap.pop();
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }
        sort(res.begin(), res.end());
    }
    return res;
}

int main() {
    int n, k;
    vector<vector<int>> arrOfArr;
    vector<int>::iterator ptr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        vector<int> arr;
        for (int i = 0; i < k; ++i) {
            int ele;
            cin >> ele;
            arr.push_back(ele);
        }
        arrOfArr.push_back(worker(arr));
    }
    for (int i = 0; i < n; i++) {
        for (ptr = arrOfArr[i].begin(); ptr < arrOfArr[i].end(); ptr++)
            cout << *ptr << " ";
        cout << endl;
    }
}