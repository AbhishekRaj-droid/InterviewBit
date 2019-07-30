
#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

vector<long long> greater_element_right(vector<int> &A, vector<long long> &right)
{
    stack<int> st;
    int i;
    
    st.push(0);
    
    for (i = 1; i < A.size(); i++) {
        while (!st.empty() && (A[st.top()] < A[i])) {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty()) {
        right[st.top()] = 0;
        st.pop();
    }
    
    return right;
} 


vector<long long> greater_element_left(vector<int> &A, vector<long long> &right)
{
    stack<int> st;
    int i;
    
    st.push(A.size() - 1);
    
    for (i = A.size() - 2; i >= 0; i--) {
        while (!st.empty() && (A[st.top()] < A[i])) {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty()) {
        right[st.top()] = 0;
        st.pop();
    }
    
    return right;
}

int Solution::maxSpecialProduct(vector<int> &A) {
    vector<long long> left(A.size(), 0);
    vector<long long> right(A.size(), 0);
    
    //cout << "high";
    left = greater_element_left(A, left);
    right = greater_element_right(A, right);
    
    long long prd;
    long long mx = 0;
    
    for (int i = 0; i < A.size(); i++) {
        //cout << left[i] << " " << right[i] << endl;
        prd = (long long)((left[i] % mod) * (right[i] % mod)) % mod;
        mx = max(mx, prd);
    }
    
    return mx;
}