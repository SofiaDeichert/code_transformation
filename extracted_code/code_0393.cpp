int main ( void ) { long int T , i , a , b , LCM , t ; scanf ( "%ld" , & T ) ; for ( i = 1 ; i <= T ; i ++ ) { scanf ( "%ld %ld" , & a , & b ) ; t = a ; while ( a != b ) { if ( a > b ) a = a - b ; else b = b - a ; } LCM = ( t * b ) / a ; printf ( "%ld %ld\n" , a , LCM ) ; } return 0 ; }