int main ( ) { int t , n , line , tri [ 100 ] [ 100 ] , tri2 [ 100 ] [ 100 ] , i , j , a , b ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < 99 ; i ++ ) for ( j = 0 ; j < 99 ; j ++ ) tri2 [ i ] [ j ] = - 1 ; while ( t -- ) { scanf ( "%d" , & n ) ; line = 1 ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j < i + 1 ; j ++ ) scanf ( "%d" , & tri [ i ] [ j ] ) ; for ( i = n - 1 ; i > - 1 ; i -- ) { for ( j = 0 ; j < i + 1 ; j ++ ) { if ( j > 0 ) { a = tri [ i - 1 ] [ j - 1 ] + tri [ i ] [ j ] ; b = tri [ i - 1 ] [ j ] + tri [ i ] [ j ] ; if ( a > b ) { if ( tri2 [ i - 1 ] [ j - 1 ] < a ) tri2 [ i - 1 ] [ j - 1 ] = a ; } else { if ( tri2 [ i - 1 ] [ j ] < b ) tri2 [ i - 1 ] [ j ] = b ; } } else tri2 [ i - 1 ] [ j ] = tri [ i - 1 ] [ j ] + tri [ i ] [ j ] ; } for ( j = 0 ; j < i + 1 ; j ++ ) tri [ i - 1 ] [ j ] = tri2 [ i - 1 ] [ j ] ; } printf ( "%d\n" , tri2 [ 0 ] [ 0 ] ) ; } return 0 ; }