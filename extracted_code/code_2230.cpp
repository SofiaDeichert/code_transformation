int main ( ) { int t , i , j , n , temp ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; long int arr [ n ] ; for ( j = 0 ; j < n ; j ++ ) scanf ( "%d" , & arr [ j ] ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j < n ; j ++ ) { if ( j + 1 < n && arr [ j ] > arr [ j + 1 ] ) { temp = arr [ j + 1 ] ; arr [ j + 1 ] = arr [ j ] ; arr [ j ] = temp ; } } } printf ( "%lld\n" , arr [ 0 ] * ( n - 1 ) ) ; } return 0 ; }