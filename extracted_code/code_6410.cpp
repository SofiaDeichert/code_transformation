int main ( ) { int t , n , i , j ; int sol [ 100 ] = { 0 } , a [ 100 ] , solp [ 100 ] ; scanf ( "%d" , & t ) ; int largest ; while ( t > 0 ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ j ] ) ; if ( i == 0 ) { sol [ i ] = a [ i ] ; } else { solp [ 0 ] = sol [ 0 ] ; sol [ 0 ] += a [ 0 ] ; } for ( j = 1 ; j < i ; j ++ ) { solp [ j ] = sol [ j ] ; sol [ j ] = max ( solp [ j - 1 ] + a [ j ] , solp [ j ] + a [ j ] ) ; } sol [ j ] = solp [ j - 1 ] + a [ j ] ; } largest = sol [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) if ( sol [ i ] > largest ) largest = sol [ i ] ; printf ( "%d\n" , largest ) ; t -- ; } return 0 ; }