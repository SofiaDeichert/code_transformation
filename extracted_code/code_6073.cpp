int main ( ) { int i , j , t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n ; scanf ( "%d" , & n ) ; long long a [ n ] [ n ] , max ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j < n ; j ++ ) a [ i ] [ j ] = 0 ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; if ( i == 0 && j == 0 ) continue ; if ( j == 0 && i != 0 ) { a [ i ] [ j ] = a [ i ] [ j ] + a [ i - 1 ] [ j ] ; continue ; } if ( i == j && i != 0 ) { a [ i ] [ j ] += a [ i - 1 ] [ j - 1 ] ; continue ; } a [ i - 1 ] [ j - 1 ] >= a [ i - 1 ] [ j ] ? a [ i ] [ j ] += a [ i - 1 ] [ j - 1 ] : ( a [ i ] [ j ] += a [ i - 1 ] [ j ] ) ; } max = a [ n - 1 ] [ 0 ] ; for ( j = 0 ; j < n ; j ++ ) { if ( a [ n - 1 ] [ j ] > max ) max = a [ n - 1 ] [ j ] ; } printf ( "%lld\n" , max ) ; } return 0 ; }