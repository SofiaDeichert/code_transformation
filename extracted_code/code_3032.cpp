int mat [ 100 ] [ 100 ] ; int maximum ( int a , int b ) { return a > b ? a : b ; } int main ( ) { int testcase , n , i , sum = 0 , max = 0 , j , k ; scanf ( "%d" , & testcase ) ; for ( i = 0 ; i < testcase ; i ++ ) { sum = 0 ; max = 0 ; scanf ( "%d" , & n ) ; for ( j = 0 ; j < n ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) { if ( k <= j ) scanf ( "%d" , & mat [ j ] [ k ] ) ; else { mat [ j ] [ k ] = 0 ; } if ( j > 0 && k > 0 ) { mat [ j ] [ k ] = maximum ( mat [ j - 1 ] [ k ] , mat [ j - 1 ] [ k - 1 ] ) + mat [ j ] [ k ] ; } else if ( j > 0 ) { mat [ j ] [ k ] = mat [ j ] [ k ] + mat [ j - 1 ] [ k ] ; } if ( max < mat [ j ] [ k ] ) max = mat [ j ] [ k ] ; } } printf ( "%d\n" , max ) ; } return 0 ; }