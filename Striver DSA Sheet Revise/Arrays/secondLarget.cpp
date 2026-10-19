#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int second_Largest() {
    vector<int> arr = {10, 5,6,8,4,5543,3,7};
    int first_max = arr[0];
    int sec_max = arr[1];

    if(first_max < sec_max) {
        // just swap Numbers
        int temp = first_max;
        first_max = sec_max;
        sec_max = temp;
    }

    for(int i=2; i<arr.size(); i++) {
        if(arr[i] > first_max) {
            sec_max = first_max;
            first_max = arr[i];
        } else if(sec_max < arr[i]) {
            sec_max = arr[i];
        }
    }

    cout << first_max << "  " << sec_max;
}

int main() {
    second_Largest();
}