int main ( ) { int t , a [ 100 ] [ 100 ] , i , s1 , s2 , d , j , n ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < 99 ; i ++ ) { for ( j = 0 ; j < 99 ; j ++ ) a [ i ] [ j ] = - 1 ; } while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j < ( i + 1 ) ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; } for ( i = 1 ; i < n ; i ++ ) { a [ i ] [ 0 ] = a [ i ] [ 0 ] + a [ i - 1 ] [ 0 ] ; for ( j = 1 ; j < ( i + 1 ) ; j ++ ) { s1 = a [ i ] [ j ] + a [ i - 1 ] [ j ] ; s2 = a [ i ] [ j ] + a [ i - 1 ] [ j - 1 ] ; if ( s1 > s2 ) a [ i ] [ j ] = s1 ; else a [ i ] [ j ] = s2 ; } } d = a [ n - 1 ] [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) { if ( a [ n - 1 ] [ i ] > d ) d = a [ n - 1 ] [ i ] ; } printf ( "%d\n" , d ) ; } }