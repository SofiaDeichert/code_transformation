int main ( ) { int min , a [ 10 ] , t , no , i ; scanf ( "%d\n" , & t ) ; while ( t -- ) { scanf ( "%d\n" , & no ) ; for ( i = 1 ; i < no ; i ++ ) scanf ( "%d" , & a [ i ] ) ; min = a [ 0 ] ; for ( i = 0 ; i < no ; i ++ ) { if ( a [ i ] < min ) min = a [ i ] ; } printf ( "%d" , min * ( no - 1 ) ) ; } return 0 ; }