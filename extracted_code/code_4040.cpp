int geter ( ) { char a ; int b = 0 ; fread ( & a , 1 , 1 , stdin ) ; while ( ! ( a >= '0' && a <= '9' ) ) { fread ( & a , 1 , 1 , stdin ) ; } while ( a >= '0' && a <= '9' ) { b = ( b << 3 ) + ( b << 1 ) + a - '0' ; fread ( & a , 1 , 1 , stdin ) ; } return b ; } int t , n , tot , g , in [ 5000 ] , res [ 5000 ] , ptr , k ; int main ( ) { t = geter ( ) ; while ( t > 0 ) { n = geter ( ) ; tot = ( ( n * ( n + 1 ) ) / 2 ) - 1 ; ptr = tot ; g = 0 ; while ( g <= tot ) { in [ g ] = geter ( ) ; g ++ ; } for ( g = n ; g >= 1 ; g -- ) { for ( k = g ; k > 0 ; k -- ) { if ( ptr + g > tot ) { res [ ptr ] = in [ ptr ] ; } else { if ( res [ ptr + g ] > res [ ptr + g + 1 ] ) { res [ ptr ] = res [ ptr + g ] + in [ ptr ] ; } else { res [ ptr ] = res [ ptr + g + 1 ] + in [ ptr ] ; } } ptr -- ; } } printf ( "%d\n" , res [ 0 ] ) ; t -- ; } return 0 ; }