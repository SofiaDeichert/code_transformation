int main ( ) { int num , max = 0 , i , j , n ; scanf ( "%d" , & num ) ; while ( num -- ) { scanf ( "%d" , & n ) ; int a [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } a [ 1 ] [ 0 ] += a [ 0 ] [ 0 ] ; a [ 1 ] [ 1 ] += a [ 0 ] [ 0 ] ; for ( i = 1 ; i < n - 1 ; i ++ ) { j = 0 ; a [ i + 1 ] [ j ] += a [ i ] [ j ] ; for ( j = 0 ; j < i ; j ++ ) ; { if ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) a [ i + 1 ] [ j + 1 ] += a [ i ] [ j ] ; else a [ i + 1 ] [ j + 1 ] += a [ i ] [ j + 1 ] ; } a [ i + 1 ] [ j + 1 ] += a [ i ] [ j ] ; } max = 0 ; for ( j = 0 , i = n - 1 ; j < n - 1 ; j ++ ) { if ( a [ i ] [ j ] > max ) max = a [ i ] [ j ] ; } printf ( "%d" , max ) ; } return 0 ; }