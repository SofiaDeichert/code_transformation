int main ( void ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int x [ 30 ] , i , j = 0 , y [ 30 ] , k , l = 0 , a1 , b1 ; long long a , b ; scanf ( "%lld%lld" , & a , & b ) ; a1 = a ; b1 = b ; for ( i = 2 ; i <= 1000000 ; i ++ ) { if ( a1 % i == 0 ) { x [ j ] = i ; a1 = a1 / i ; i -- ; j ++ ; } if ( a1 == 1 ) break ; } for ( k = 2 ; k <= 1000000 ; k ++ ) { if ( b1 % k == 0 ) { y [ l ] = k ; b1 = b1 / k ; k -- ; l ++ ; } if ( b1 == 1 ) break ; } int r = 1 , m , n ; for ( m = 0 ; m < j ; m ++ ) { for ( n = 0 ; n < l ; n ++ ) { if ( x [ m ] == y [ n ] ) { r = r * x [ m ] ; y [ n ] == 0 ; break ; } } } long long g ; g = a * b ; g = g / r ; printf ( "%d %lld\n" , r , g ) ; } return 0 ; }