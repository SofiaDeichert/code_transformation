int main ( ) { int t , a [ 1000 ] , b [ 1000 ] , n , sum = 0 , tot = 0 , j , k , l , i ; scanf ( "%d" , & t ) ; if ( t >= 1 && t <= 1000 ) { for ( l = 0 ; l < t ; l ++ ) { scanf ( "%d" , & n ) ; while ( n > 0 ) { sum = sum + n ; n -- ; } for ( i = 0 ; i < sum ; i ++ ) scanf ( "%d" , & a [ i ] ) ; for ( j = 0 ; j < n ; j ++ ) for ( k = 0 ; k < sum ; k ++ ) { if ( a [ k ] == j ) tot ++ ; } b [ l ] = tot ; tot = 0 ; sum = 0 ; } for ( i = 0 ; i < t ; i ++ ) printf ( "%d \n" , b [ i ] ) ; } return 0 ; }