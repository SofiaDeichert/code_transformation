int arr [ 100 ] [ 100 ] = { 0 } ; void sum_triangle ( ) { int i , j , row , ele ; scanf ( "%d" , & row ) ; ; for ( i = 0 ; i < row ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & ele ) ; if ( i == 0 ) arr [ i ] [ j ] = ele ; else { if ( j == 0 ) arr [ i ] [ j ] = ele + arr [ i - 1 ] [ j ] ; else { if ( arr [ i - 1 ] [ j - 1 ] + ele > arr [ i - 1 ] [ j ] + ele ) arr [ i ] [ j ] = arr [ i - 1 ] [ j - 1 ] + ele ; else arr [ i ] [ j ] = arr [ i - 1 ] [ j ] + ele ; } } } } int max = 0 ; for ( i = 0 ; i <= row - 1 ; i ++ ) { if ( arr [ row - 1 ] [ i ] > max ) max = arr [ row - 1 ] [ i ] ; } printf ( "%d" , max ) ; } int max ( int i , int j ) { if ( i > j ) return i ; else return j ; } int main ( ) { int t , i ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; t ++ ) { sum_triangle ( ) ; } return 0 ; }