int main ( ) { int b [ 101 ] [ 101 ] , a [ 100000 ] , i , j , n , k = 1 , x [ 1000 ] , t , m ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { x [ i ] = 0 ; } for ( m = 0 ; m < t ; m ++ ) { scanf ( "\n%d" , & n ) ; for ( i = 0 ; i < 100000 ; i ++ ) { a [ i ] = 0 ; } for ( i = 0 ; i < n ; i ++ ) { printf ( "\n" ) ; for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & b [ i ] [ j ] ) ; } } a [ 1 ] = b [ 0 ] [ 0 ] ; a [ 2 ] = b [ 1 ] [ 0 ] + b [ 0 ] [ 0 ] ; a [ 3 ] = b [ 1 ] [ 1 ] + b [ 0 ] [ 0 ] ; a [ 4 ] = a [ 2 ] + b [ 2 ] [ 0 ] ; a [ 5 ] = a [ 2 ] + b [ 2 ] [ 1 ] ; a [ 6 ] = a [ 3 ] + b [ 2 ] [ 1 ] ; a [ 7 ] = a [ 3 ] + b [ 2 ] [ 2 ] ; k = 8 ; for ( i = 3 ; i < n ; i ++ ) { for ( j = 0 ; j < i ; j ++ ) { a [ k ] = b [ i ] [ j ] + a [ ( i - 1 ) * ( i - 1 ) - i + j + 3 ] ; ++ k ; a [ k ] = b [ i ] [ j + 1 ] + a [ ( i - 1 ) * ( i - 1 ) - i + j + 3 ] ; ++ k ; } } for ( i = 1 ; i < ( ( n * n ) ) ; i ++ ) { if ( x [ m ] < a [ i ] ) { x [ m ] = a [ i ] ; } } } i = 0 ; while ( i < t ) { printf ( "\n%d" , x [ i ] ) ; i ++ ; } return 0 ; }