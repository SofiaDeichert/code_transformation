char rbuffer [ rbuffer_size ] ; int rfptr = rbuffer_size ; char wbuffer [ wbuffer_size ] ; int wfptr = 0 ; int readno ; void rd ( ) { rfptr = 0 ; readno = read ( 0 , rbuffer , rbuffer_size ) ; } int get_i ( ) { int sum = 0 ; char c ; int sign = 1 ; while ( 1 ) { if ( ( rfptr >= rbuffer_size ) || ( rfptr >= readno ) ) rd ( ) ; c = rbuffer [ rfptr ++ ] ; if ( c == '-' ) { sign = - 1 ; } else { if ( c == '\n' || c == ' ' ) return sum * sign ; else sum = sum * 10 + c - '0' ; } } } void wr ( ) { write ( 0 , wbuffer , wbuffer_size ) ; wfptr = 0 ; } void put_i ( int i ) { char ar [ 10 ] ; ar [ 0 ] = 0 ; int sign = 1 ; int index = - 1 ; if ( i == 0 ) { ar [ 0 ] = '0' ; index = 0 ; } else { if ( i < 0 ) { sign = - 1 ; i *= - 1 ; } while ( i != 0 ) { ar [ ++ index ] = i + '0' ; i /= 10 ; } } if ( sign == - 1 ) { if ( wfptr >= wbuffer_size ) wr ( ) ; wbuffer [ wfptr ++ ] = '-' ; } while ( index >= 0 ) { if ( wfptr >= wbuffer_size ) wr ( ) ; wbuffer [ wfptr ++ ] = ar [ index -- ] ; } } void put_i_c ( int i , char c ) { char ar [ 10 ] ; ar [ 0 ] = 0 ; int sign = 1 ; int index = - 1 ; if ( i == 0 ) { ar [ 0 ] = 0 ; index = 0 ; } else { if ( i < 0 ) { sign = - 1 ; i *= - 1 ; } while ( i != 0 ) { ar [ ++ index ] = i + '0' ; i /= 10 ; } } if ( sign == - 1 ) { if ( wfptr >= wbuffer_size ) wr ( ) ; wbuffer [ wfptr ++ ] = '-' ; } while ( index >= 0 ) { if ( wfptr >= wbuffer_size ) wr ( ) ; wbuffer [ wfptr ++ ] = ar [ index -- ] ; } if ( wfptr >= wbuffer_size ) wr ( ) ; wbuffer [ wfptr ++ ] = c ; } void writeRemaining ( ) { if ( wfptr > 0 ) write ( 0 , wbuffer , wfptr ) ; } int max ( int a , int b ) { if ( a > b ) return a ; else return b ; } int main ( void ) { int t , n , i ; int * * p ; int k ; int tempval ; scanf ( "%d" , & t ) ; while ( t -- > 0 ) { scanf ( "%d" , & n ) ; p = ( int * * ) malloc ( n * sizeof ( int * ) ) ; for ( i = 0 ; i < n ; i ++ ) { p [ i ] = ( int * ) malloc ( ( i + 1 ) * sizeof ( int ) ) ; for ( k = 0 ; k <= i ; k ++ ) { scanf ( "%d" , & p [ i ] [ k ] ) ; } } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( k = 0 ; k <= i ; k ++ ) { p [ i ] [ k ] += max ( p [ i + 1 ] [ k ] , p [ i + 1 ] [ k + 1 ] ) ; } } put_i_c ( p [ 0 ] [ 0 ] , '\n' ) ; } writeRemaining ( ) ; }