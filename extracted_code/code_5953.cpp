int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int n , small , i , a [ 100000 ] ; scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%lld" , a + i ) ; small = a [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) { if ( a [ i ] < small ) small = a [ i ] ; } printf ( "%lld\n" , small * ( n - 1 ) ) ; } return 0 ; }