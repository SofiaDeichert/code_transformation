int main ( ) { int t , i , j , l , k , sum = 0 ; scanf ( "%d" , & t ) ; for ( l = 0 ; l < t ; l ++ ) { unsigned int n ; scanf ( "%ud" , & n ) ; int A [ 100 ] [ 100 ] ; for ( j = 0 ; j < n ; j ++ ) { for ( k = 0 ; k < n ; k ++ ) A [ j ] [ k ] = 0 ; } for ( j = 0 ; j < n ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) { scanf ( "%d" , & A [ j ] [ k ] ) ; } } for ( i = 1 ; i < n ; i ++ ) { for ( j = 0 ; j < n ; j ++ ) { if ( j == 0 ) A [ i ] [ j ] += A [ i - 1 ] [ j ] ; else A [ i ] [ j ] += ( A [ i - 1 ] [ j - 1 ] > A [ i - 1 ] [ j ] ? A [ i - 1 ] [ j - 1 ] : A [ i - 1 ] [ j ] ) ; if ( A [ i ] [ j ] > sum ) sum = A [ i ] [ j ] ; } } printf ( "%d\n" , sum ) ; } }