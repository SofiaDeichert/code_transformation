int main ( ) { int t , k , i , j , n , p , q ; int a [ 105 ] [ 105 ] ; scanf ( "%d" , & t ) ; for ( k = 0 ; k < t ; k ++ ) { scanf ( "%d" , & n ) ; for ( p = 0 ; p < n ; p ++ ) { for ( q = 0 ; q <= p ; q ++ ) { scanf ( "%d" , & a [ p ] [ q ] ) ; } } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { a [ i ] [ j ] = a [ i ] [ j ] + ( a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ? a [ i + 1 ] [ j ] : a [ i + 1 ] [ j + 1 ] ) ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }