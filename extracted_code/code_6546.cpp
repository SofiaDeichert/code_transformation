int max ( int x , int y ) { if ( x > y ) return x ; else return y ; } void disp_array ( int * A , int len ) { int i = 0 ; while ( i < len ) { printf ( "%d\t" , A [ i ] ) ; i ++ ; } printf ( "\n" ) ; return ; } static char _rbuf [ 8192 * 8 ] ; static char * _rend = 0 ; static char * _rpos = 0 ; static int _getchar ( ) { int n = read ( 0 , _rbuf , sizeof _rbuf ) ; if ( n <= 0 ) { printf ( "EOF(%d)\n" , n ) ; exit ( 1 ) ; } _rend = _rbuf + n ; _rpos = _rbuf + 1 ; return * _rbuf ; } static int get_i ( ) { int c ; while ( ( c = getchar ( ) ) < '0' ) { } int n = c - '0' ; while ( ( c = getchar ( ) ) >= '0' ) { n = n * 10 + ( c - '0' ) ; } return n ; } static int put_i ( int n ) { char buf [ BSIZE ] ; int bn = BSIZE - 1 ; while ( 1 ) { buf [ bn -- ] = '0' + ( n ) ; n = n / 10 ; if ( n == 0 ) break ; } while ( bn < BSIZE - 1 ) putchar ( buf [ ++ bn ] ) ; putchar ( '\n' ) ; } void sumTrain ( int rows ) { int a [ rows ] ; int b [ rows ] ; int * curr ; int * old ; old = a ; curr = b ; a [ 0 ] = 0 ; b [ 0 ] = 0 ; int i = 0 ; int n , j ; while ( i < rows ) { j = 1 ; n = get_i ( ) ; curr [ 0 ] = old [ 0 ] + n ; if ( i ) { while ( j < i ) { n = get_i ( ) ; curr [ j ] = n + max ( old [ j ] , old [ j - 1 ] ) ; j ++ ; } n = get_i ( ) ; curr [ j ] = old [ j - 1 ] + n ; } if ( old == a ) { curr = a ; old = b ; } else { old = a ; curr = b ; } i ++ ; } int mx = 0 ; for ( i = 0 ; i < rows ; i ++ ) { if ( old [ i ] > mx ) { mx = old [ i ] ; } } put_i ( mx ) ; } int main ( ) { int n , rows , c ; n = get_i ( ) ; while ( n > 0 ) { rows = get_i ( ) ; sumTrain ( rows ) ; n -- ; rows = 0 ; } return 0 ; }