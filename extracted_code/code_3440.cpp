int main ( ) { int n , l , k , i , j , t , p , max ; int arr [ 100 ] ; scanf ( "%d%d" , & n , & l ) ; for ( p = 1 ; p <= n ; p ++ ) { for ( i = 0 , k = 0 ; i < l ; i ++ ) { for ( j = 0 , t = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & t ) ; k = k + t ; } arr [ i ] = k ; } for ( i = 0 , max = 0 ; i < l ; i ++ ) { if ( arr [ i ] > max ) max = arr [ i ] ; } printf ( "%d" , max / 2 ) ; } return 0 ; }