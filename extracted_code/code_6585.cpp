int main ( ) { int T , n , i , j , a , b , m ; for ( scanf ( "%d" , & T ) ; T > 0 ; T -- ) { int s [ 99 ] [ 99 ] = { 0 } ; scanf ( "%d%d" , & n , & m ) ; s [ 0 ] [ 0 ] = m ; for ( i = 0 ; i < n - 1 ; i ++ ) for ( j = 0 ; j < i + 2 ; ) { b = s [ i ] [ j ] ; a = s [ i ] [ j - 1 ] ; if ( j > 0 && b < a ) b = a ; scanf ( "%d" , & a ) ; b += a ; s [ i + 1 ] [ j ++ ] = b ; if ( m < b ) m = b ; } printf ( "%d\n" , m ) ; } return 0 ; }