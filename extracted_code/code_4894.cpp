int main ( ) { int a [ 100 ] , i , j , k , c , t , n , l ; scanf ( "%d" , & t ) ; for ( l = 0 ; l < t ; l ++ ) { c = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; for ( i = 0 ; i < n ; i ++ ) { j = i + 1 ; k = i ; while ( j < n ) { if ( a [ k ] <= a [ j ] ) { c ++ ; j ++ ; k ++ ; } else break ; } } printf ( "%d" , n + c ) ; } return 0 ; }