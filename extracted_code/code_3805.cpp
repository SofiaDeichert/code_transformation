int main ( ) { int i , j , l = 0 , n , r , p = 1 , c , t [ 101 ] = { 0 } , a [ 101 ] = { 0 } , sum [ 101 ] = { 0 } ; scanf ( "%d" , & n ) ; while ( n -- ) { scanf ( "%d" , & r ) ; for ( i = 1 , c = 0 ; i <= r ; i ++ ) { c += i ; if ( i != r ) { p *= 2 ; a [ i ] = i - 1 ; } } for ( i = 1 ; i <= c ; i ++ ) scanf ( "%d" , & t [ i ] ) ; for ( i = 1 ; i <= p ; i ++ ) { sum [ i ] = t [ 1 ] ; for ( j = 1 , c = 1 ; j <= r - 1 ; j ++ ) { c += a [ j ] + 1 ; sum [ i ] += t [ c ] ; if ( l < sum [ i ] ) l = sum [ i ] ; } j -- ; while ( a [ j ] == j ) j -- ; a [ j ++ ] ++ ; while ( j <= r - 1 ) a [ j ++ ] -- ; } printf ( "%d\n" , l ) ; } return 0 ; }