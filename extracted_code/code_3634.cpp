int main ( ) { int t , n , a [ 100 ] , j , i , smax , max , b [ 1000 ] , sum , k , l ; scanf ( "%d" , & t ) ; i = 0 ; while ( i < t ) { scanf ( "%d" , & n ) ; smax = 0 ; k = 0 ; while ( k < n ) { for ( j = 0 ; j <= k ; j ++ ) scanf ( "%d" , & a [ j ] ) ; sum = 0 ; for ( j = 0 ; j <= k ; j ++ ) sum = sum + a [ j ] ; max = sum ; if ( smax > max ) max = smax ; smax = sum ; k ++ ; } b [ i ] = max ; i ++ ; } for ( i = 0 ; i < t ; i ++ ) printf ( "%d\n" , b [ i ] ) ; return 0 ; }