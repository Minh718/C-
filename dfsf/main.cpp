vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> temp;
    int i = 0, j = 0;
    if (a.size() == 0) return b;
    if (b.size() == 0) return a;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        temp.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        temp.push_back(b[j]);
        j++;
    }

    return temp;
}

vector<int> helper(vector<vector<int>>& lists, int st, int end) {
    if (st == end) return lists[st];
    int mid = st + (end - st) / 2;
    vector<int> a = helper(lists, st, mid);
    vector<int> b = helper(lists, mid + 1, end);
    return merge(a, b);
}

vector<int> solve(vector<vector<int>>& lists) {
    int k = lists.size();
    if (k == 0) return {};

    return helper(lists, 0, k - 1);
}
