///=============== Histogram Using Stack ==================
namespace Histogram {
    #define mxEq(a,b)  (a = max(a,b))
    inline int solve(const int *h, const int n){
        stack<int>  stk;
        int i = 0,top, res = 0;
        while(i < n){
            if(stk.empty() || h[stk.top()] <= h[i]) stk.push(i++);
            else{
                top = stk.top(); // h[top] > h[i];
                stk.pop();
                if(stk.empty()) mxEq(res, h[top]*i); // as h[0 To top] >= h[top] < h[top To i-1]
                else            mxEq(res, h[top]*(i-stk.top()-1)); // as h[stk.top() To top] <= h[top] < h[top To i-1]
            }
        }
        while(!stk.empty()){
            top = stk.top(); 
            stk.pop();
            if(stk.empty()) mxEq(res, h[top]*i); // same as upward
            else            mxEq(res, h[top]*(i-stk.top()-1)); // same as upward
        }
        return res;   
    }
}
