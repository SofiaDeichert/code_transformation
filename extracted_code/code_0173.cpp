int gcd ( int a , int b ) { int rem = b % a ; if ( rem == 0 ) return a ; else return gcd ( rem , a ) ; } void main ( ) { int n , i , r [ 100 ] , lcm [ 100 ] , a , b ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d%d" , & a , & b ) ; if ( a < b ) r [ i ] = gcd ( a , b ) ; else r [ i ] = gcd ( b , a ) ; lcm [ i ] = ( a * b ) / r [ i ] ; } for ( i = 0 ; i < n ; i ++ ) printf ( "%d %d\n" , lcm [ i ] , r [ i ] ) ; }