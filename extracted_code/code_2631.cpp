int main ( ) { int test ; scanf ( "%d" , & test ) ; int i , j , n , max ; while ( test -- ) { scanf ( "%d" , & n ) ; int vec1 [ n ] [ n ] ; int vec2 [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & vec1 [ i ] [ j ] ) ; vec2 [ 0 ] [ 0 ] = vec1 [ 0 ] [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { vec2 [ i ] [ 0 ] = vec1 [ i ] [ 0 ] + vec2 [ i - 1 ] [ 0 ] ; vec2 [ i ] [ i ] = vec1 [ i ] [ i ] + vec2 [ i - 1 ] [ i - 1 ] ; } for ( i = 2 ; i < n ; i ++ ) { for ( j = 1 ; j < i ; j ++ ) { if ( vec2 [ i - 1 ] [ j ] > vec2 [ i - 1 ] [ j - 1 ] ) { vec2 [ i ] [ j ] = vec2 [ i - 1 ] [ j ] + vec1 [ i ] [ j ] ; } else { vec2 [ i ] [ j ] = vec2 [ i - 1 ] [ j - 1 ] + vec1 [ i ] [ j ] ; } } } max = vec2 [ n - 1 ] [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { if ( vec2 [ n - 1 ] [ i ] > max ) max = vec2 [ n - 1 ] [ i ] ; } printf ( "%d\n" , max ) ; } return 0 ; }