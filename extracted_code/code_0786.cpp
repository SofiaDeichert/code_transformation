int n ; int function ( int a [ ] , int line , int previous ) { int t = line + previous ; if ( line == ( n - 1 ) ) return a [ t ] > a [ t + 1 ] ? a [ t ] : a [ t + 1 ] ; else { int t1 = a [ t ] + function ( a , line + 1 , t ) ; int t2 = a [ t + 1 ] + function ( a , line + 1 , t + 1 ) ; return t1 > t2 ? t1 : t2 ; } } int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; int sum = 0 , i ; for ( i = 1 ; i <= n ; sum += i , i ++ ) ; int a [ sum ] ; for ( i = 0 ; i < sum ; i ++ ) scanf ( "%d" , & a [ i ] ) ; printf ( "\n%d\n" , a [ 0 ] + function ( a , 1 , 0 ) ) ; } }