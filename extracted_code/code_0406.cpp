int main ( ) { int t , n , arr [ 100000 ] = { } , i , j , k , check , temp , count ; scanf ( "%d" , & t ) ; while ( t -- ) { count = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & arr [ i ] ) ; for ( i = 1 ; i <= n ; i ++ ) { for ( j = 1 ; j <= n ; j ++ ) { if ( j + i - 1 <= n ) { temp = arr [ j - 1 ] ; check = 1 ; for ( k = j ; ( k <= j + i - 1 ) ; k ++ ) { if ( arr [ k - 1 ] >= temp ) temp = arr [ k - 1 ] ; else { check = 0 ; break ; } } if ( check == 1 ) count ++ ; } else break ; } } printf ( "%d\n" , count ) ; } return 0 ; }