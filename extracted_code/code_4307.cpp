int max ( int a , int b ) { if ( a >= b ) return a ; return b ; } int main ( ) { int t , n , i , j ; int a [ 100 ] [ 100 ] , sum [ 100 ] [ 100 ] = { 0 } ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) { if ( i == 0 && j == 0 ) sum [ i ] [ j ] = a [ i ] [ j ] ; else if ( j == 0 ) sum [ i ] [ j ] = a [ i ] [ j ] + sum [ i - 1 ] [ 0 ] ; else sum [ i ] [ j ] = a [ i ] [ j ] + max ( sum [ i - 1 ] [ j ] , sum [ i - 1 ] [ j - 1 ] ) ; } int max = 0 ; for ( i = 0 ; i < n ; i ++ ) if ( sum [ n - 1 ] [ i ] >= max ) max = sum [ n - 1 ] [ i ] ; printf ( "%d\n" , max ) ; } return 0 ; }