int main ( ) { int a [ 101 ] [ 101 ] = { 0 } ; int i , j , temp ; int t , n , res ; scanf ( "%d" , & t ) ; while ( t -- ) { res = 0 ; scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; if ( j == 1 && i > 1 ) { a [ i ] [ j ] += a [ i - 1 ] [ j ] ; continue ; } if ( j == i && i > 1 ) { a [ i ] [ j ] += a [ i - 1 ] [ j - 1 ] ; continue ; } temp = a [ i ] [ j ] ; if ( ( ( temp += a [ i - 1 ] [ j ] ) > ( a [ i ] [ j ] += a [ i - 1 ] [ j - 1 ] ) ) && ( i > 1 ) ) a [ i ] [ j ] = temp ; if ( i == n && a [ n ] [ j ] > res ) { res = a [ n ] [ j ] ; } } } printf ( "%d\n" , res ) ; } return 0 ; }