int main ( ) { int test ; scanf ( "%d" , & test ) ; while ( test -- ) { int n ; scanf ( "%d" , & n ) ; int ar [ n ] ; int i , length = 0 , sum = 0 ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & ar [ i ] ) ; for ( i = 0 ; i < n - 1 ; i ++ ) { length ++ ; if ( ar [ i ] > ar [ i + 1 ] || i == n - 1 ) { sum += ( length ) * ( length + 1 ) / 2 ; length = 0 ; } } printf ( "%d\n" , sum ) ; } return 0 ; }