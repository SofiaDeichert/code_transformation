int main ( ) { int t , n , u , temp , i , j ; int sum ; int k ; int a [ 6000 ] ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d" , & n ) ; temp = ( n * ( n + 1 ) ) / 2 ; for ( u = 1 ; u <= temp ; u ++ ) { scanf ( "%d" , & a [ u ] ) ; } sum = a [ 1 ] ; k = 1 ; for ( j = 1 ; j < n ; j ++ ) { if ( ( a [ k ] + a [ k + j ] ) > ( a [ k ] + a [ k + j + 1 ] ) ) { sum = sum + a [ k + j ] ; k = k + j ; } else { sum = sum + a [ k + j + 1 ] ; k = k + j + 1 ; } } printf ( "%d" , sum ) ; printf ( "\n" ) ; } return 0 ; }