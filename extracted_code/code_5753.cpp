int main ( ) { int m ; long long n , a , i , min = 99999 ; scanf ( "%d" , & m ) ; while ( m -- ) { scanf ( "%lld" , & n ) ; i = 0 ; while ( i < n ) { scanf ( "%lld" , & a ) ; if ( a < min ) min = a ; i ++ ; } printf ( "%lld\n" , min * ( n - 1 ) ) ; } return 0 ; }