int t , n , i , j , a [ 101 ] [ 101 ] , m , p ; long int sum [ 101 ] [ 101 ] , temp [ 2 ] , maxi ; int main ( ) { scanf ( "%d" , & t ) ; for ( t ; t > 0 ; -- t ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; ++ i ) for ( j = 0 ; j <= i ; ++ j ) scanf ( "%d" , & a [ i ] [ j ] ) ; sum [ 0 ] [ 0 ] = a [ 0 ] [ 0 ] ; for ( i = 0 ; i < n ; ++ i ) { sum [ i ] [ 0 ] = sum [ i - 1 ] [ 0 ] + a [ i ] [ 0 ] ; sum [ i ] [ i ] = sum [ i - 1 ] [ i ] + a [ i ] [ i ] ; } for ( i = 1 ; i < n ; ++ i ) { for ( j = 1 ; j < i ; ++ j ) { temp [ 0 ] = sum [ i - 1 ] [ j - 1 ] + a [ i ] [ j ] ; temp [ 1 ] = sum [ i - 1 ] [ j ] + a [ i ] [ j ] ; if ( temp [ 0 ] > temp [ 1 ] ) sum [ i ] [ j ] = temp [ 0 ] ; else sum [ i ] [ j ] = temp [ 1 ] ; } } maxi = sum [ n - 1 ] [ 0 ] ; for ( i = 1 ; i < n ; ++ i ) { if ( maxi < sum [ n - 1 ] [ i ] ) maxi = sum [ n - 1 ] [ i ] ; } printf ( "%ld\n" , maxi ) ; } return 0 ; }