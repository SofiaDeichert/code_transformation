int main ( ) { int a [ 100 ] [ 100 ] ; int i , j , sum = 0 , test , n ; scanf ( "%d" , & test ) ; while ( test -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = n - 1 ; i >= 0 ; i -- ) for ( j = 0 ; j <= i ; j ++ ) a [ i - 1 ] [ j ] += ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) ? a [ i ] [ j ] : a [ i ] [ j + 1 ] ; printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }