int main ( ) { int t , r , c , i , j , n , a [ 100 ] [ 100 ] ; scanf ( "%d" , & t ) ; while ( t > 0 ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i <= ( n - 1 ) ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = ( n - 1 ) ; i > 0 ; i -- ) { for ( j = 0 ; j < ( n - 1 ) ; j ++ ) { if ( a [ i ] [ j ] <= a [ i ] [ j + 1 ] ) { a [ i - 1 ] [ j ] = a [ i - 1 ] [ j ] + a [ i ] [ j + 1 ] ; } else { a [ i - 1 ] [ j ] = a [ i - 1 ] [ j ] + a [ i ] [ j ] ; } } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; t -- ; } }