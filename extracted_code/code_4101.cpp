int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , Dynamic [ 100 ] [ 100 ] , i , j ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j < i + 1 ; j ++ ) scanf ( "%d" , & Dynamic [ i ] [ j ] ) ; } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = i ; j >= 0 ; j -- ) { Dynamic [ i ] [ j ] += ( Dynamic [ i + 1 ] [ j + 1 ] > Dynamic [ i + 1 ] [ j ] ? Dynamic [ i + 1 ] [ j + 1 ] : Dynamic [ i + 1 ] [ j ] ) ; } } printf ( "%d\n" , Dynamic [ 0 ] [ 0 ] ) ; } return 0 ; }