int main ( void ) { int t , i ; scanf ( "%d" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { int a [ 100 ] , n , b = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } for ( i = 0 ; i < n - 1 ; i ++ ) { if ( a [ i ] >= a [ i + 1 ] ) { a [ i ] = a [ i + 1 ] ; b = b + a [ i ] ; } else { a [ i + 1 ] = a [ i ] ; b = a [ i ] + b ; } } printf ( "%d" , b ) ; } return 0 ; }