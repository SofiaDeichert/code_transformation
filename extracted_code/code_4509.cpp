int main ( ) { int s , i , j , n , b ; int a [ 100 ] [ 100 ] ; scanf ( "%d" , & n ) ; for ( b = 0 ; b < n ; b ++ ) { scanf ( "%d" , & s ) ; for ( i = 0 ; i < s ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = s - 1 ; i > 0 ; i -- ) for ( j = 0 ; j < i ; j ++ ) { if ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) a [ i - 1 ] [ j ] += a [ i ] [ j ] ; else a [ i - 1 ] [ j ] += a [ i ] [ j + 1 ] ; } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }