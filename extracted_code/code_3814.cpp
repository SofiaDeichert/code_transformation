int main ( ) { int t , T ; scanf ( "%d" , & T ) ; for ( t = 0 ; t < T ; t ++ ) { int N , i , j ; scanf ( "%d" , & N ) ; int dp [ N ] [ N ] ; for ( i = 0 ; i < N ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & dp [ i ] [ j ] ) ; for ( i = N - 2 ; i >= 0 ; i -- ) for ( j = 0 ; j <= i ; j ++ ) { dp [ i ] [ j ] += dp [ i + 1 ] [ j ] > dp [ i + 1 ] [ j + 1 ] ? dp [ i + 1 ] [ j ] : dp [ i + 1 ] [ j + 1 ] ; } printf ( "%d" , dp [ 0 ] [ 0 ] ) ; } return 0 ; }