int main ( ) { int y , z , i , t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & y ) ; int A [ y ] ; for ( i = 0 ; i <= y ; i ++ ) { scanf ( "%d" , & A [ i ] ) ; } int min = A [ 0 ] ; for ( z = 1 ; z <= y ; z ++ ) { if ( A [ z ] < min ) min = A [ z ] ; } printf ( "%d\n" , min * ( y - 1 ) ) ; } return 0 ; }