int T ; int A [ 100 ] [ 100 ] ; int compute ( int A [ ] [ 100 ] , int n ) { int i , j ; for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { A [ i ] [ j ] += ( A [ i + 1 ] [ j ] > A [ i + 1 ] [ j + 1 ] ) ? A [ i + 1 ] [ j ] : A [ i + 1 ] [ j + 1 ] ; } } return A [ 0 ] [ 0 ] ; } int main ( ) { int i , j , k ; scanf ( "%d" , & T ) ; int n ; for ( i = 0 ; i < T ; i ++ ) { scanf ( "%d" , & n ) ; for ( j = 0 ; j < n ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) scanf ( "%d" , & A [ j ] [ k ] ) ; } printf ( "%d\n" , compute ( A , n ) ) ; } return 0 ; }