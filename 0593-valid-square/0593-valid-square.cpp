class Solution {
    long long dist(vector<int>& p1, vector<int>& p2){
        return (p1[0] - p2[0]) * ( p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);

    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<long long> p = {dist(p1,p2), dist(p1, p3), dist(p1, p4), dist(p2,p3), dist(p2,p4), dist(p3, p4)};
        sort(p.begin(), p.end());
        if(p[0] > 0 && p[0]== p[1] && p[1] ==p[2] && p[2] == p[3] && p[4] == p[5] && p[4] == 2 * p[0]) return true;
        return false; 
    }
};