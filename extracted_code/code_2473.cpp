int max ( int a , int b ) { if ( a > b ) return a ; else return b ; } void trinum ( ) { int arr [ 101 ] [ 101 ] , i = 0 , j = 0 , n ; scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; } } for ( i = n ; i >= 2 ; i -- ) { for ( j = 1 ; j <= i - 1 ; j ++ ) { arr [ i - 1 ] [ j ] += max ( arr [ i ] [ j ] , arr [ i ] [ j + 1 ] ) ; } } printf ( "\n%d" , arr [ 1 ] [ 1 ] ) ; } int main ( ) { int t = 0 , i ; scanf ( "%d" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { trinum ( ) ; } return 0 ; }