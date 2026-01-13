class Solution {
public:
    double separateSquares(vector<vector<int>>& a) {
            long double s=0, p=1e18, q=0, r;
            for(auto &x:a) s += (long double)x[2]*x[2];
            long double t = s/2;
            for(auto &x:a){
                p = min(p,(long double)x[1]);
                q = max(q,(long double)x[1]+x[2]);
            }
            for(int i=0;i<100;i++){
                r = (p+q)/2;
                long double u=0;
                for(auto &x:a){
                    long double v=x[1], w=x[2];
                    if(r<=v) u+=0;
                    else if(r>=v+w) u+=w*w;
                    else u+=(r-v)*w;
                }
                if(u<t) p=r; else q=r;
            }
            return (double)r;
    }
};