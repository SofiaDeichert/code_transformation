int main ( ) { int a [ 100 ] [ 100 ] , t , x , i , j ; scanf ( "%d" , & t ) ; while ( t ) { scanf ( "%d" , & x ) ; for ( i = 0 ; i < x ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = x - 1 ; i >= 0 ; i -- ) { for ( j = 0 ; j < i ; j ++ ) { if ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) a [ i - 1 ] [ j ] += a [ i ] [ j ] ; else a [ i - 1 ] [ j ] += a [ i ] [ j + 1 ] ; } } printf ( "%d" , a [ 0 ] [ 0 ] ) ; t -- ; printf ( "\n" ) ; } return 0 ; }