void main ( ) { long long int tri [ 1000 ] [ 1000 ] , i , j , r , c ; scanf ( "%lld" , & c ) ; while ( c > 0 ) { scanf ( "%lld" , & r ) ; for ( i = 0 ; i < r ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%lld" , & tri [ i ] [ j ] ) ; } for ( i = 0 ; i < r ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) printf ( "%lld " , tri [ i ] [ j ] ) ; printf ( "\n" ) ; } for ( i = r - 1 ; i > 0 ; i -- ) { for ( j = r - 1 ; j > 0 ; j -- ) { if ( tri [ i ] [ j ] >= tri [ i ] [ j - 1 ] ) tri [ i - 1 ] [ j - 1 ] = tri [ i ] [ j ] + tri [ i - 1 ] [ j - 1 ] ; else tri [ i - 1 ] [ j - 1 ] = tri [ i ] [ j - 1 ] + tri [ i - 1 ] [ j - 1 ] ; } } printf ( "%lld" , tri [ i ] [ j ] ) ; c -= 1 ; printf ( "\n" ) ; } }