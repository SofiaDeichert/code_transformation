static char buf [ BUF_SIZE ] ; static long pos = 0 ; static long len = 0 ; static int readC ( ) { if ( pos >= len ) { len = read ( 0 , buf , BUF_SIZE ) ; if ( len < 1 ) return - 1 ; pos = 0 ; } return buf [ pos ++ ] ; } int readInt ( ) { int c , ve = 1 , i = 0 ; do { c = readC ( ) ; } while ( ( c < '0' || c > '9' ) ) ; do { i = ( i << 3 + i << 1 ) + c - '0' ; c = readC ( ) ; } while ( c >= '0' && c <= '9' ) ; return i * ve ; } int main ( ) { int T , n , i , j ; T = readInt ( ) ; while ( T -- ) { n = readInt ( ) ; int A [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) A [ i ] [ j ] = readInt ( ) ; for ( i = n - 2 ; i >= 0 ; i -- ) for ( j = 0 ; j <= i ; j ++ ) A [ i ] [ j ] += MAX ( A [ i + 1 ] [ j ] , A [ i + 1 ] [ j + 1 ] ) ; printf ( "%d\n" , A [ 0 ] [ 0 ] ) ; } return 0 ; }