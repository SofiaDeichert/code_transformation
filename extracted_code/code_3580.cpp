int main ( ) { int i , j , b , n , t , s , s1 = 0 , s2 , a [ 99 ] [ 99 ] ; scanf ( "%d" , & t ) ; for ( b = 1 ; b <= t ; b ++ ) { scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( j = 1 ; j <= 1 ; j ++ ) { for ( i = 1 ; i <= n ; i ++ ) { s1 = s1 + a [ i ] [ j ] ; } } for ( j = 2 ; j <= n ; j ++ ) { s2 = 0 ; for ( i = 2 ; i <= n ; i ++ ) { s2 = s2 + a [ i ] [ j ] ; } if ( s1 > s2 ) { s = s1 ; } else { s = s2 ; } } printf ( "%d\n" , s ) ; } return 0 ; }