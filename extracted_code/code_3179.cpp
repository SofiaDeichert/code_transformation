int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a [ maxx ] [ maxx ] , n , i , sum = 0 , max1 , j ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; } for ( i = 0 ; i < n ; i ++ ) { max1 = a [ i ] [ 0 ] ; for ( j = 0 ; j <= i ; j ++ ) { if ( a [ i ] [ j ] > max1 ) max1 = a [ i ] [ j ] ; } sum = sum + max1 ; } printf ( "%d\n" , sum - 1 ) ; } return 0 ; }