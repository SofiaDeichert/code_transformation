int main ( ) { int t ; long int a , n ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld" , & n ) ; long int arr [ n ] ; for ( a = 0 ; a < n ; a ++ ) scanf ( "%ld" , & arr [ a ] ) ; long int min = arr [ 0 ] ; for ( a = 1 ; a < n ; a ++ ) if ( arr [ a ] < min ) min = arr [ a ] ; printf ( "%ld\n" , ( n - 1 ) * min ) ; } return 0 ; }