int main ( ) { int t , n , i , j , sum = 0 , a [ 100 ] [ 100 ] ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; sum = a [ 0 ] [ 0 ] ; j = 0 ; for ( i = n - 1 ; i > 0 ; i -- ) for ( j = 0 ; j < i ; j ++ ) a [ i - 1 ] [ j ] += a [ i ] [ j ] > a [ i ] [ j + 1 ] ? a [ i ] [ j ] : a [ i ] [ j + 1 ] ; printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }