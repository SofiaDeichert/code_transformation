int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , c = 0 , i ; scanf ( "%d" , & n ) ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; long int m = a [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { if ( m > a [ i ] ) { m = a [ i ] ; } } printf ( "%ld\n" , m * ( n - 1 ) ) ; } }