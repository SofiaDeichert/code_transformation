int main ( ) { int n , i , l , j , k , arr [ 100 ] [ 100 ] , sum ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & l ) ; for ( j = 0 ; j < l ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) { scanf ( "%d" , & arr [ j ] [ k ] ) ; } } sum = arr [ 0 ] [ 0 ] ; for ( j = 0 ; j < l ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) { if ( arr [ j + 1 ] [ k ] >= arr [ j ] [ k ] ) sum = sum + arr [ j + 1 ] [ k ] ; else if ( arr [ j + 1 ] [ k + 1 ] > arr [ j ] [ k ] ) sum = sum + arr [ j + 1 ] [ k + 1 ] ; } } printf ( "%d\n" , sum ) ; } return 0 ; }