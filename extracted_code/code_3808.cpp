int main ( ) { int T ; scanf ( "%d" , & T ) ; while ( T -- ) { int N ; scanf ( "%d" , & N ) ; int a [ 1000 ] ; int i , j ; for ( i = 1 ; i <= N ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } int count = 0 ; for ( i = 1 ; i <= N ; i ++ ) { for ( j = i ; j = i + 1 ; j ++ ) { if ( ( a [ i ] == a [ j ] ) || ( a [ i ] < a [ j + 1 ] ) ) { count ++ ; } } } printf ( "%d\n" , count ) ; } return 0 ; }