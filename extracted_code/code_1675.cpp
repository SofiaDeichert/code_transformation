int main ( ) { int a [ 100 ] [ 100 ] , n , r , i , j , k ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & r ) ; for ( j = 0 ; j < r ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) { scanf ( "%d" , & a [ j ] [ k ] ) ; } } for ( j = r - 2 ; j >= 0 ; j -- ) { for ( k = j ; k >= 0 ; k -- ) { a [ i ] [ j ] += ( a [ i + 1 ] [ j + 1 ] > a [ i + 1 ] [ j ] ) ? a [ i + 1 ] [ j + 1 ] : a [ i + 1 ] [ j ] ; } } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; return 0 ; }