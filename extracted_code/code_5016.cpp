int main ( ) { int n = 0 , m = 0 , i = 0 , j = 0 , k = 0 , t = 0 , u = 0 , h = 0 , l = 0 , g = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & m ) ; u = 0 ; l = 0 ; for ( j = 0 ; j < m ; j ++ ) { l = g ; h = g = 0 ; for ( k = 0 ; k <= j ; k ++ ) { scanf ( "%d" , & t ) ; if ( ( k == l || k == l + 1 ) && h < t ) { g = k ; h = t ; } } u = u + h ; printf ( "\n" ) ; } printf ( "%d" , u ) ; } return 0 ; }