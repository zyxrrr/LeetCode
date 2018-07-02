class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1){
            return 1;
        }
        
        if(m < n){
            int tmp = m;
            m = n;
            n = tmp;
        }
        
        long long a = 1;
        //cout << a <<endl;
        for(int i = 1; i <= n - 1; i++){
            a *= i;
            //cout << a <<endl;
        }
        long long b = 1;
        for(int i = m; i <= m + n -2; i++){
            b *= i;
        }
        //cout << a <<endl;
        return b/a;
    }
};
