bool cmp(string a, string b) {
    string ab = a + b;
    string ba = b + a;
    
    return ab.compare(ba) > 0 ? true : false;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> arr;
    int n = A.size();
    for (int i = 0; i < A.size(); i++) {
        string str = to_string(A[i]);
        arr.push_back(str);
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    string ans = arr[0];
    
    for (int i = 1; i < n; i++) {
        ans += arr[i];
    }
    if (ans[0] == '0') {
        return "0";
    }
    return ans;
}
