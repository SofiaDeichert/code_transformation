int main ( ) { int tests ; long temp , minval , i , n ; scanf ( "%d" , & tests ) ; while ( tests -- ) { scanf ( "%li" , & n ) ; minval = 200000 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%li" , & temp ) ; if ( temp < minval ) { minval = temp ; } } printf ( "%lli\n" , ( n - 1 ) * minval ) ; } return 0 ; }