main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , max ; scanf ( "%d" , & n ) ; int i , a [ n ] , count = 0 , j ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; for ( i = 0 ; i < n ; i ++ ) { max = a [ i ] ; for ( j = i ; j < n ; j ++ ) { if ( a [ i ] <= a [ j ] ) { if ( max > a [ j ] ) break ; count ++ ; max = a [ j ] ; } } } printf ( "%d\n" , count ) ; } }