int main ( ) { int ar [ 100 ] [ 100 ] , i , j , t , l ; long long int k ; scanf ( "%d" , & t ) ; while ( t > 0 ) { scanf ( "%d" , & l ) ; for ( i = 0 ; i < l ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & ar [ i ] [ j ] ) ; } } for ( i = l - 1 ; i > 0 ; i -- ) { for ( j = 0 ; j <= i - 1 ; j ++ ) { if ( ar [ i ] [ j ] > ar [ i ] [ j + 1 ] ) ar [ i - 1 ] [ j ] = ar [ i - 1 ] [ j ] + ar [ i ] [ j ] ; else ar [ i - 1 ] [ j ] = ar [ i - 1 ] [ j ] + ar [ i ] [ j + 1 ] ; } } printf ( "%d\n" , ar [ 0 ] [ 0 ] ) ; t -- ; } return ( 0 ) ; }