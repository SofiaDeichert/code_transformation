int main ( ) { int t , n ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; int i , j , ar [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & ar [ i ] [ j ] ) ; } for ( i = n - 2 ; i >= 0 ; i -- ) for ( j = 0 ; j < n ; j ++ ) ar [ i ] [ j ] += ar [ i + 1 ] [ j ] > ar [ i + 1 ] [ j + 1 ] ? ar [ i + 1 ] [ j ] : ar [ i + 1 ] [ j + 1 ] ; printf ( "%d\n" , ar [ 0 ] [ 0 ] ) ; } }