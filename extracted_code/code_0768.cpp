void lcm ( int x , int y , int t1 ) { int m ; m = ( x * y ) / t1 ; printf ( " %d" , m ) ; } void gcd ( int x , int y ) { int t1 , t2 ; t1 = x ; t2 = y ; while ( t1 != t2 ) { if ( t1 > t2 ) t1 = t1 - t2 ; else t2 = t2 - t1 ; } printf ( "\n%d" , t1 ) ; lcm ( x , y , t1 ) ; } void main ( ) { int n , i ; int a [ 100 ] , b [ 100 ] ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; scanf ( "%d" , & b [ i ] ) ; } for ( i = 0 ; i < n ; i ++ ) { gcd ( a [ i ] , b [ i ] ) ; } }