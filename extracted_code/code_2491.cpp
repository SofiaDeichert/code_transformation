int main ( ) { int test ; scanf ( "%d" , & test ) ; for ( int i = 0 ; i < test ; i ++ ) { int n ; scanf ( "%d" , & n ) ; int ar [ n ] ; for ( int j = 0 ; j < n ; j ++ ) { scanf ( "%d" , & ar [ j ] ) ; } int sum = 0 ; for ( int j = 0 ; j < n - 1 ; j ++ ) { if ( ar [ j ] > ar [ j + 1 ] ) { sum = sum + ar [ j + 1 ] ; } else { sum = sum + ar [ j ] ; } } printf ( "%d\n" , sum ) ; } }