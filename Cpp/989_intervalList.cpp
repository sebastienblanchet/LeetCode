/*
* @Author: Seb Blanchet
* @Date:   2019-06-24 21:44:37
* @Last Modified by:   Seb Blanchet
* @Last Modified time: 2019-06-24 21:46:15
*/


vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size() ) {
        if (A[i].end < B[j].start) ++i;
        else if (B[j].end < A[i].start) ++j;
        else {
            res.push_back({ max(A[i].start, B[j].start), min(A[i].end, B[j].end) });
            if (A[i].end < B[j].end) ++i;
            else ++j;
        }
    }

    return res;
}
