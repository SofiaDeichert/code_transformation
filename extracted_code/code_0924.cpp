int main ( ) { int i , min , a [ 100 ] , t ; long int size ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & size ) ; for ( i = 0 ; i < size ; i ++ ) scanf ( "%d" , & a [ i ] ) ; min = a [ 0 ] ; for ( i = 1 ; i < size ; i ++ ) { if ( a [ i ] < min ) min = a [ i ] ; } printf ( "%ld\n" , min * ( size - 1 ) ) ; } return 0 ; }