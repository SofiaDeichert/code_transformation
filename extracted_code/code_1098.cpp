int main ( ) { int n , l , i , sum , count , actsum , j ; scanf ( "%d" , & n ) ; if ( ( n <= 0 ) || ( n > 99 ) ) return 2 ; int first ; int ans [ n ] ; for ( j = 0 ; j < n ; j ++ ) { scanf ( "%d" , & l ) ; int a [ ( l * l + l ) / 2 + 1 ] ; for ( i = 0 ; i < ( ( l * l + l ) / 2 ) ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; if ( ( a [ i ] < 1 ) || ( a [ i ] > 98 ) ) return 2 ; } count = 0 ; actsum = a [ 0 ] + a [ 1 ] + a [ 2 ] ; sum = 0 ; first = a [ 0 ] ; for ( i = 1 ; i < ( ( l * l + l ) / 2 ) ; i ++ ) { sum += a [ i ] + a [ i + 1 ] + first ; first = a [ i ] ; i ++ ; i += count ; count += 1 ; if ( sum >= actsum ) actsum = sum ; sum = 0 ; } ans [ j ] = actsum ; } for ( j = 0 ; j < n ; j ++ ) printf ( "%d\n" , ans [ j ] ) ; return 1 ; }