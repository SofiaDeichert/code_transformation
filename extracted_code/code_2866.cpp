int main ( ) { int a [ 100 ] [ 100 ] , i , j , N , T , max ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d" , & N ) ; for ( i = 0 ; i < N ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; if ( i == 0 && j == 0 ) continue ; if ( j == 0 ) a [ i ] [ j ] += a [ i - 1 ] [ j ] ; else if ( i == j ) a [ i ] [ j ] += a [ i - 1 ] [ j - 1 ] ; else a [ i ] [ j ] += ( a [ i - 1 ] [ j ] > a [ i - 1 ] [ j - 1 ] ) ? a [ i - 1 ] [ j ] : a [ i - 1 ] [ j - 1 ] ; } } max = a [ N - 1 ] [ 0 ] ; for ( i = 0 ; i < N ; i ++ ) if ( a [ N - 1 ] [ i ] > max ) max = a [ N - 1 ] [ i ] ; printf ( "%d\n" , max ) ; } return 0 ; }