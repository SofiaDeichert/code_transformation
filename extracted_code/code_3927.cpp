int main ( void ) { int t , n , i ; scanf ( "%d" , & t ) ; if ( t >= 1 && t <= 10 ) while ( t -- ) { int count = 0 ; scanf ( "%d" , & n ) ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } for ( i = 0 ; i < n - 1 ; i ++ ) { if ( a [ i ] > a [ i + 1 ] ) { count += a [ i + 1 ] ; } else { count += a [ i ] ; } } printf ( "%d\n" , count ) ; } return 0 ; }