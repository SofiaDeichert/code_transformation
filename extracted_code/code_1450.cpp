int max1 ( int a , int b ) { return a > b ? a : b ; } int main ( ) { int a [ 105 ] [ 105 ] , i , j , count , cases , max2 ; scanf ( "%d" , & cases ) ; while ( cases -- ) { scanf ( "%d" , & count ) ; scanf ( "%d" , & a [ 0 ] [ 0 ] ) ; a [ 0 ] [ 1 ] = 0 ; for ( i = 1 ; i < count ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; a [ i ] [ j ] = max1 ( a [ i - 1 ] [ j ] , a [ i - 1 ] [ j - 1 ] ) + a [ i ] [ j ] ; } a [ i ] [ j + 1 ] = 0 ; } max2 = a [ count - 1 ] [ 0 ] ; for ( i = 0 ; i < count ; i ++ ) { if ( a [ count - 1 ] [ i ] > max2 ) max2 = a [ count - 1 ] [ i ] ; } printf ( "%d\n" , max2 ) ; } return 0 ; }