int main ( ) { long int t , n , i , num , min ; scanf ( "%ld" , & t ) ; while ( t -- ) { min = 20000 ; scanf ( "%ld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%ld" , & num ) ; if ( num < min ) min = num ; } printf ( "%ld\n" , min * ( n - 1 ) ) ; } return 0 ; }