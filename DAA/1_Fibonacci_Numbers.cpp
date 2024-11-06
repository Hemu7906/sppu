#include<bits/stdc++.h>
using namespace std;

int steps = 0;

int rFibbonacci(int n){
    steps++;
    if(n<0) return 0;
    if(n==1 || n==0) return 1;
    return rFibbonacci(n-1)+rFibbonacci(n-2);
}

int iFibbonacci(int n){
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    int cnt = 2;
    for(int i  =2;i<n;i++){
        cnt++;
        v.push_back(v[i-1]+v[i-2]);
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    cout << "Fibbonaci value: " << rFibbonacci(n) << endl;
    cout << "Step Count using recursive function: " << steps << endl;
    cout << "Step Count using iterative function: " << iFibbonacci(n) << endl;
    return 0;
}


/*
Recursive fibbonacci:
Time Complexity: O(n*2n)
Auxiliary Space: O(n), For recursion call stack.

Iterative fibbonacci:
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/