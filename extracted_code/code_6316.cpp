int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long int n , i , j ; scanf ( " %ld" , & n ) ; long int arr [ n ] , count = 0 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( " %ld" , & arr [ i ] ) ; } for ( i = 0 ; i < n - 1 ; i ++ ) { for ( j = i ; j < n - 1 ; j ++ ) { if ( arr [ j ] <= arr [ j + 1 ] ) count ++ ; else break ; } } printf ( "%ld\n" , count + n ) ; } return 0 ; }