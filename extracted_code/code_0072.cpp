int main ( ) { int t , x , y , i , j , n ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; int a [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = n - 1 ; i > 0 ; i -- ) for ( j = 0 ; j < i ; j ++ ) { x = a [ i ] [ j ] ; y = a [ i ] [ j + 1 ] ; a [ i - 1 ] [ j ] += ( ( x >= y ) ? x : y ) ; } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }