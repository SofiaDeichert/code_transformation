int main ( ) { int total ; scanf ( "%d" , & total ) ; while ( total -- ) { int n , i ; long long cost ; scanf ( "%d" , & n ) ; long min , a [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%ld" , & a [ i ] ) ; min = a [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { if ( a [ i ] < min ) min = a [ i ] ; } cost = min * ( n - 1 ) ; printf ( "%lld\n" , cost ) ; } return 0 ; }