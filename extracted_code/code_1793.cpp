int main ( int argc , char * argv [ ] ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int j , i , n , temp ; scanf ( "%d" , & n ) ; int * * ar = ( int * * ) malloc ( n * sizeof ( int * ) ) ; for ( i = 0 ; i < n ; i ++ ) ar [ i ] = ( int * ) malloc ( n * sizeof ( int ) ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & ar [ i ] [ j ] ) ; } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { if ( ar [ i + 1 ] [ j ] > ar [ i + 1 ] [ j + 1 ] ) temp = ar [ i + 1 ] [ j ] ; else temp = ar [ i + 1 ] [ j + 1 ] ; ar [ i ] [ j ] += temp ; } } printf ( "%d\n" , ar [ 0 ] [ 0 ] ) ; } return 0 ; }