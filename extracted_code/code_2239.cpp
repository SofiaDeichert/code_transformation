int main ( ) { int i , j , n , t ; long long int a [ 110 ] [ 110 ] ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%lld" , & a [ i ] [ j ] ) ; for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) a [ i ] [ j ] += ( a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ) ? a [ i + 1 ] [ j ] : a [ i + 1 ] [ j + 1 ] ; } printf ( "%lld\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }