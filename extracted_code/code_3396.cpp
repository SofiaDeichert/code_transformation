int main ( ) { int m , i ; scanf ( "%d" , & m ) ; for ( i = 1 ; i <= m ; i ++ ) { long int n ; scanf ( "%ld" , & n ) ; int j ; long int arr [ n ] ; for ( j = 0 ; j < n ; j ++ ) scanf ( "%ld" , & arr [ j ] ) ; long int min = arr [ 0 ] ; for ( j = 0 ; j < n ; j ++ ) { if ( min > arr [ j ] ) min = arr [ j ] ; } long int ans = ( n - 1 ) * min ; printf ( "%ld\n" , ans ) ; } return 0 ; }