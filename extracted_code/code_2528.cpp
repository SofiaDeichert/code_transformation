int main ( ) { int t , i ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { long int n ; scanf ( "%ld" , & n ) ; long int arr [ n ] , j ; for ( j = 0 ; j < n ; j ++ ) scanf ( "%ld" , & arr [ j ] ) ; long int min = arr [ 0 ] ; for ( j = 1 ; j < n ; j ++ ) { if ( min > arr [ j ] ) min = arr [ j ] ; } printf ( "%ld\n" , min * ( n - 1 ) ) ; } }