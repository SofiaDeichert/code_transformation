int main ( void ) { int n , m , i ; scanf ( "%d\n" , & m ) ; while ( m > 0 && m <= 10 ) for ( i = 0 ; i < m ; i ++ ) { scanf ( "%d\n" , & n ) ; int A [ 50000 ] , B , c = 0 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & A [ i ] ) ; } B = A [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { if ( B < A [ i ] ) { c = c + B ; } else { c = c + A [ i ] ; B = A [ i ] ; } } printf ( "%d" , c ) ; m -- ; } return 0 ; }