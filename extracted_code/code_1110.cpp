int main ( ) { long int a [ 99 ] [ 99 ] ; int i , j , s ; long int n , t ; scanf ( "%ld" , & n ) ; if ( n <= 1000 ) { while ( n > 0 ) { s = 0 ; scanf ( "%ld" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%ld" , & a [ i ] [ j ] ) ; s = s + a [ i ] [ j ] ; } } printf ( "%ld" , ( s / 2 ) ) ; t -- ; } } return 0 ; }