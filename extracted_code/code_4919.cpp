int main ( ) { int test , tri [ SIZE ] [ SIZE ] , n , i , j , max ; scanf ( "%d" , & test ) ; while ( test -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & tri [ i ] [ j ] ) ; } for ( i = 1 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { if ( j > 0 && j < i ) tri [ i ] [ j ] += ( ( tri [ i - 1 ] [ j ] > tri [ i - 1 ] [ j - 1 ] ) ? tri [ i - 1 ] [ j ] : tri [ i - 1 ] [ j - 1 ] ) ; else if ( j == 0 ) tri [ i ] [ j ] += tri [ i - 1 ] [ j ] ; else tri [ i ] [ j ] += tri [ i - 1 ] [ j - 1 ] ; } } max = 0 ; for ( j = 0 ; j < n ; j ++ ) { if ( max < tri [ n - 1 ] [ j ] ) max = tri [ n - 1 ] [ j ] ; } printf ( "%d\n" , max ) ; } return 0 ; }