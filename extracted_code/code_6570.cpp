int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long int n ; scanf ( "%ld" , & n ) ; long int a [ n ] , i , temp ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%ld" , & a [ i ] ) ; if ( i == 0 || a [ i ] < temp ) temp = a [ i ] ; } printf ( "%ld\n" , temp * ( n - 1 ) ) ; } return 0 ; }