int main ( ) { int t , n , i ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; int arr [ n ] ; long long min = 100000 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & arr [ i ] ) ; if ( arr [ i ] <= min ) { min = arr [ i ] ; } } printf ( "%lld\n" , ( n - 1 ) * min ) ; } return 0 ; }