int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , i , j ; scanf ( "%d" , & n ) ; int a [ n ] ; long long int x = 9999999 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; if ( x > a [ i ] ) { x = a [ i ] ; } } printf ( "%lld\n" , x ) ; } }