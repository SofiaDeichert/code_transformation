int main ( void ) { int N , i , a [ 100 ] ; int count = 0 ; printf ( "Enter the size of the array" ) ; scanf ( "%d" , & N ) ; printf ( "Enter the elements" ) ; for ( i = 0 ; i < N ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } for ( i = 0 ; i < N ; i ++ ) { count ++ ; } for ( i = 0 ; i < N ; i ++ ) { if ( a [ i ] > a [ i + 1 ] ) { count ++ ; } else { break ; } } printf ( "%d" , count ) ; return 0 ; }