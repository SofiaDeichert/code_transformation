int main ( ) { int sum , temp , j , t , n , i , a [ 50000 ] ; scanf ( "%d" , & t ) ; while ( t != 0 ) { t -- ; sum = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = i + 1 ; j < n ; j ++ ) { if ( a [ i ] > a [ j ] ) { temp = a [ i ] ; a [ i ] = a [ j ] ; a [ j ] = temp ; } } } if ( n % 2 != 0 ) for ( i = 0 ; i < n / 2 ; i ++ ) sum = sum + ( a [ i ] * 2 ) ; else { for ( i = 0 ; i < ( n / 2 ) - 1 ; i ++ ) sum = sum + ( a [ i ] * 2 ) ; sum = sum + a [ i ] ; } printf ( "%d\n" , sum ) ; } return 0 ; }