int main ( ) { int n , t , i , j , num , tmp1 ; int a [ 101 ] [ 101 ] , tot [ 100 ] [ 100 ] ; scanf ( "%d" , & t ) ; while ( t != 0 ) { scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = 1 ; i <= n ; i ++ ) { tot [ i ] [ i ] = 0 ; for ( j = 1 ; j <= i ; j ++ ) { if ( ( i - 1 ) != 0 ) { tot [ i ] [ j ] = tot [ i - 1 ] [ j ] + a [ i ] [ j ] ; tmp1 = tot [ i ] [ j ] ; if ( ( j - 1 ) != 0 ) { tot [ i ] [ j ] = tot [ i - 1 ] [ j - 1 ] + a [ i ] [ j ] ; if ( tmp1 > tot [ i ] [ j ] ) { tot [ i ] [ j ] = tmp1 ; } } } } printf ( "\n" ) ; } i = tot [ n ] [ 1 ] ; for ( j = 2 ; j <= n ; j ++ ) { if ( tot [ n ] [ j ] > i ) { i = tot [ n ] [ j ] ; } } printf ( "%d\n" , i + a [ 1 ] [ 1 ] ) ; } return 0 ; }