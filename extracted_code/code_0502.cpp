int main ( void ) { unsigned long long T , N , i , j , max , lar , A [ 1000 ] [ 1000 ] ; scanf ( "%llu" , & T ) ; while ( T -- ) { scanf ( "%llu" , & N ) ; for ( i = 0 ; i < N ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%llu" , & A [ i ] [ j ] ) ; } for ( i = 1 ; i < N ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { if ( j == 0 ) A [ i ] [ 0 ] += A [ i - 1 ] [ 0 ] ; else if ( i == j ) A [ i ] [ j ] += A [ i - 1 ] [ j - 1 ] ; else { max = ( A [ i - 1 ] [ j - 1 ] > A [ i - 1 ] [ j ] ) ? A [ i - 1 ] [ j - 1 ] : A [ i - 1 ] [ j ] ; A [ i ] [ j ] += max ; } } } lar = A [ N - 1 ] [ 0 ] ; for ( j = 0 ; j < N ; j ++ ) { if ( A [ N - 1 ] [ j ] > lar ) lar = A [ N - 1 ] [ j ] ; } printf ( "%llu\n" , lar ) ; } return 0 ; }