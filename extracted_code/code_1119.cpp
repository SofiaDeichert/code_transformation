int main ( void ) { int test ; scanf ( "%d" , & test ) ; while ( test -- ) { int n , i , min ; int arr [ MAX ] ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & arr [ i ] ) ; min = arr [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) { if ( min >= arr [ i ] ) min = arr [ i ] ; } long long int val = min * ( n - 1 ) ; printf ( "%lld\n" , val ) ; } return 0 ; }