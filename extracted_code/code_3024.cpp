int main ( ) { int a [ max ] , i , min , n , t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; if ( i == 0 ) min = a [ 0 ] ; else if ( i > 0 && a [ i ] < min ) min = a [ i ] ; } printf ( "%d\n" , ( min * ( n - 1 ) ) ) ; } return 0 ; }