int main ( ) { int t , i , j , n ; long int a [ 100 ] [ 100 ] , sum = 0 , max = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; } for ( i = 0 ; i < n - 1 ; i ++ ) { for ( j = i ; j < n - 1 ; j ++ ) { sum += a [ j ] [ i ] ; } sum = sum + a [ j ] [ i + 1 ] ; if ( max < sum ) max = sum ; sum = 0 ; } printf ( "%d\n" , max ) ; } }