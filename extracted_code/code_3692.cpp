static char _rbuf [ 8192 * 8 ] ; static char * _rend = 0 ; static char * _rpos = 0 ; static int _getchar ( ) { int n = read ( 0 , _rbuf , sizeof _rbuf ) ; if ( n <= 0 ) { printf ( "EOF(%d)\n" , n ) ; exit ( 1 ) ; } _rend = _rbuf + n ; _rpos = _rbuf + 1 ; return * _rbuf ; } static int get_i ( ) { int c ; while ( ( ( c = mygetchar ( ) ) ) < '0' ) { } int n = c - '0' ; while ( ( ( c = mygetchar ( ) ) ) >= '0' ) { n = n * 10 + c - '0' ; } return n ; } static void put_i ( int n ) { char buf [ BSIZE ] ; int bn = BSIZE - 1 ; while ( 1 ) { buf [ bn -- ] = '0' + ( n ) ; n = n / 10 ; if ( n == 0 ) break ; } while ( bn < BSIZE - 1 ) putchar ( buf [ ++ bn ] ) ; putchar ( '\n' ) ; } int main ( ) { int n = 0 ; int i = 0 ; int j = 0 ; int k = get_i ( ) ; while ( k -- ) { n = get_i ( ) ; int a [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) { a [ i ] [ j ] = get_i ( ) ; } for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i + 1 ; j ++ ) { if ( i > 0 && j > 0 && j != i ) { a [ i ] [ j ] += max ( a [ i - 1 ] [ j ] , a [ i - 1 ] [ j - 1 ] ) ; } else if ( i != 0 ) { if ( j == 0 ) { a [ i ] [ j ] += a [ i - 1 ] [ j ] ; } else if ( j == i ) a [ i ] [ j ] += a [ i - 1 ] [ j - 1 ] ; } } int max = 0 ; for ( i = 0 ; i < n ; i ++ ) { if ( max < a [ n - 1 ] [ i ] ) max = a [ n - 1 ] [ i ] ; } put_i ( max ) ; } return 0 ; }