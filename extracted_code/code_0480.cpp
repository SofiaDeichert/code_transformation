int main ( ) { int T , N , i , j , triangle [ 6000 ] ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d" , & N ) ; for ( i = 0 ; i < N * ( N + 1 ) / 2 ; i ++ ) scanf ( "%d" , & triangle [ i ] ) ; for ( i = N - 1 ; i >= 1 ; i -- ) { for ( j = 0 ; j <= i - 1 ; j ++ ) { if ( triangle [ i * ( i + 1 ) / 2 + j ] >= triangle [ i * ( i + 1 ) / 2 + j + 1 ] ) triangle [ ( i - 1 ) * i / 2 + j ] += triangle [ i * ( i + 1 ) / 2 + j ] ; else triangle [ ( i - 1 ) * i / 2 + j ] += triangle [ i * ( i + 1 ) / 2 + j + 1 ] ; } } printf ( "%d\n" , triangle [ 0 ] ) ; } return 0 ; }