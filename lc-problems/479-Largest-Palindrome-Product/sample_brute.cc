#define LL long long

class Solution {
public:
    LL pal( LL i, int n ) {
        LL res = i;
        LL p   = i;
        while ( p ) {
            res *= 10;
            res += p % 10;
            p /= 10;
        }
        return res;
    }
    LL pal1( LL i, int n ) {
        LL res = i / 10;
        LL p   = i;
        while ( p ) {
            res *= 10;
            res += p % 10;
            p /= 10;
        }
        return res;
    }
    int largestPalindrome( int n ) {
        LL res = 0;
        LL l   = pow( 10, n - 1 );
        LL r   = pow( 10, n ) - 1;
        for ( int i = r; i >= l; i-- ) {
            LL p = pal( i, n );
            // IMPORT j*j>=p! j is the larger between p's divisor
            for ( LL j = r; j >= l & j * j >= p; j-- )
                if ( p % j == 0 )
                    return p % 1337;
        }
        for ( int i = r; i >= l; i-- ) {
            LL p = pal1( i, n );
            // IMPORT j*j>=p! j is the larger between p's divisor
            for ( LL j = r; j >= l & j * j >= p; j-- )
                if ( p % j == 0 )
                    return p % 1337;
        }
        return 0;
    }
};