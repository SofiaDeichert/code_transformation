int main ( ) { long int t , i , j , n ; scanf ( "%ld" , & t ) ; while ( t -- ) { scanf ( "%ld" , & n ) ; long int a , b = 100000 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%ld" , & a ) ; if ( a < b ) b = a ; } printf ( "%ld\n" , b * ( n - 1 ) ) ; } return 0 ; }