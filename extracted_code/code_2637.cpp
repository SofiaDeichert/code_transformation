int main ( ) { int a [ 100 ] [ 100 ] , i , j , n , t , max ; scanf ( "%d" , & n ) ; while ( n -- ) { scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = t - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { if ( a [ i + 1 ] [ j + 1 ] > a [ i + 1 ] [ j ] ) { a [ i ] [ j ] += a [ i + 1 ] [ j + 1 ] ; } else { a [ i ] [ j ] += a [ i + 1 ] [ j ] ; } } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }