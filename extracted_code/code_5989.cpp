int main ( ) { int t , m , s ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int s = 0 ; long int n , i ; scanf ( "%ld" , & n ) ; long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%ld" , & a [ i ] ) ; } for ( i = 0 ; i < n - 1 ; i ++ ) { if ( a [ i ] >= a [ i + 1 ] ) s = s + a [ i + 1 ] ; else { m = a [ i ] ; a [ i ] = a [ i + 1 ] ; a [ i + 1 ] = m ; s = s + a [ i + 1 ] ; } } printf ( "%lld\n" , s ) ; } }