unsigned long compute ( unsigned long count ) ; unsigned long C ( unsigned long n , unsigned long r ) ; int main ( ) { int m , t ; scanf ( "%d\n" , & t ) ; char * Number = NULL ; unsigned long ch = EOF ; Number = ( char * ) malloc ( sizeof ( char ) ) ; unsigned long count = 0 ; unsigned long answer = 0 ; for ( m = 0 ; m < t ; m ++ ) { count = 0 ; answer = 0 ; ch = EOF ; while ( 1 ) { ch = getc ( stdin ) ; if ( ch != '\n' ) { if ( ch != 32 ) { if ( ( ch - 48 ) > atoi ( Number ) ) { Number [ 0 ] = ch ; count ++ ; } else { answer += compute ( count ) ; Number [ 0 ] = ch ; count = 1 ; } } } else { answer += compute ( count ) ; Number [ 0 ] = 0 ; break ; } } printf ( "%lu\n" , answer ) ; } return 0 ; } unsigned long compute ( unsigned long count ) { unsigned long i , total = 0 ; for ( i = 1 ; i <= count ; i ++ ) { total += C ( count , i ) ; } return total ; } unsigned long C ( unsigned long n , unsigned long r ) { if ( r > n / 2 ) r = n - r ; unsigned long ans = 1 ; unsigned long i ; for ( i = 1 ; i <= r ; i ++ ) { ans *= n - r + i ; ans /= i ; } return ans ; }