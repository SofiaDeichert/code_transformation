int main ( ) { int t , l , a [ 100001 ] , b [ 100001 ] , sum , n , i ; scanf ( "%d" , & t ) ; for ( l = 0 ; l < t ; l ++ ) { scanf ( "%d" , & n ) ; a [ n ] = 0 ; b [ 0 ] = 1 ; sum = 0 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; if ( a [ i ] <= a [ i + 1 ] ) { b [ i + 1 ] = b [ i ] + 1 ; } else { b [ i + 1 ] = 1 ; } sum = sum + b [ i ] ; } printf ( "%d\n" , sum ) ; } return 0 ; }