long long max ( long long a , long long b ) { if ( a > b ) return a ; return b ; } int main ( ) { int test ; scanf ( "%d" , & test ) ; while ( test -- ) { int row , i , j , k ; long long arr [ 100 ] , dp [ 100 ] [ 2 ] , res = 0 ; scanf ( "%d" , & row ) ; dp [ 0 ] [ 0 ] = dp [ 0 ] [ 1 ] = 0 ; for ( i = 0 ; i < row ; ++ i ) { for ( j = 0 ; j <= i ; ++ j ) scanf ( "%lld" , & arr [ j ] ) ; for ( j = 0 ; j <= i ; ++ j ) { if ( j == 0 ) { dp [ j ] [ 1 ] = dp [ j ] [ 0 ] + arr [ j ] ; if ( dp [ j ] [ 1 ] > res ) res = dp [ j ] [ 1 ] ; continue ; } if ( j == i ) { dp [ j ] [ 1 ] = dp [ j - 1 ] [ 0 ] + arr [ j ] ; if ( dp [ j ] [ 1 ] > res ) res = dp [ j ] [ 1 ] ; continue ; } dp [ j ] [ 1 ] = arr [ j ] + max ( dp [ j ] [ 0 ] , dp [ j - 1 ] [ 0 ] ) ; if ( dp [ j ] [ 1 ] > res ) res = dp [ j ] [ 1 ] ; } for ( j = 0 ; j <= i ; ++ j ) dp [ j ] [ 0 ] = dp [ j ] [ 1 ] ; } printf ( "%lld\n" , res ) ; } return 0 ; }