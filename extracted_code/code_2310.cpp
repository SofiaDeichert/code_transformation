int main ( ) { int n , i , j , l , max = 0 , sum , sum1 , a [ 50 ] [ 50 ] ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } if ( n < 2 ) printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; else { for ( i = 0 ; i < n ; i ++ ) { l = i ; sum = a [ 0 ] [ 0 ] ; sum1 = a [ 0 ] [ 0 ] ; for ( j = 1 ; j < n ; j ++ ) { sum = sum + a [ j ] [ i ] ; sum1 = sum1 + a [ j ] [ ++ l ] ; } if ( sum > sum1 && max < sum ) max = sum ; else if ( sum1 > sum && max < sum1 ) max = sum1 ; } printf ( "%d\n" , max ) ; } return 0 ; }