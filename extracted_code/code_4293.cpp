int scan ( ) { int n = 0 ; int ch = getchar_unlocked ( ) ; while ( ch < '0' || ch > '9' ) ch = getchar_unlocked ( ) ; while ( ch >= '0' && ch <= '9' ) { n = ( n * 10 ) + ch - '0' ; ch = getchar_unlocked ( ) ; } return n ; } int main ( ) { int t ; t = scan ( ) ; while ( t -- ) { int n , i , j ; int a [ 100 ] [ 100 ] ; n = scan ( ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { a [ i ] [ j ] = scan ( ) ; } } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { a [ i ] [ j ] += a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ? a [ i + 1 ] [ j ] : a [ i + 1 ] [ j + 1 ] ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }