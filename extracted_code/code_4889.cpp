char rbuffer [ rbuffer_size ] ; int rfptr = rbuffer_size ; char wbuffer [ wbuffer_size ] ; int wfptr = 0 ; int readno = 0 ; void rd ( ) { rfptr = 0 ; readno = read ( 0 , rbuffer , rbuffer_size ) ; } int get_i ( ) { int sum = 0 ; char c ; int sign = 1 ; while ( 1 ) { if ( ( rfptr >= rbuffer_size ) || ( rfptr >= readno ) ) rd ( ) ; c = rbuffer [ rfptr ++ ] ; if ( c == '-' ) { sign = - 1 ; } else { if ( c == '\n' || c == ' ' ) return sum * sign ; else sum = sum * 10 + c - '0' ; } } } int max ( int a , int b ) { if ( a > b ) return a ; else return b ; } int main ( void ) { int t , n , i ; int * * p ; int k ; int tempval ; t = get_i ( ) ; while ( t -- > 0 ) { n = get_i ( ) ; p = ( int * * ) malloc ( n * sizeof ( int * ) ) ; for ( i = 0 ; i < n ; i ++ ) { p [ i ] = ( int * ) malloc ( ( i + 1 ) * sizeof ( int ) ) ; for ( k = 0 ; k <= i ; k ++ ) { p [ i ] [ k ] = get_i ( ) ; } } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( k = 0 ; k <= i ; k ++ ) { p [ i ] [ k ] += max ( p [ i + 1 ] [ k ] , p [ i + 1 ] [ k + 1 ] ) ; } } printf ( "%d\n" , p [ 0 ] [ 0 ] ) ; } }