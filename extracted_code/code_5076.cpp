int max ( int a , int b ) { if ( a >= b ) return a ; else return b ; } int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int m , j , p , k , i , s , n , x ; scanf ( "%d" , & m ) ; x = ( m * m - m ) / 2 + m ; int a [ x ] ; for ( i = 0 ; i < x ; i ++ ) scanf ( "%d" , & a [ i ] ) ; j = m - 1 ; p = j ; k = ( m * m - m ) / 2 - 1 ; n = k ; for ( i = 0 ; i < j ; i ++ ) { for ( s = 0 ; s < ( j - i ) ; s ++ ) { a [ n ] = a [ n ] + max ( a [ n + p ] , a [ n + p + 1 ] ) ; n -- ; } p -- ; } printf ( "%d\n" , a [ 0 ] ) ; } return 0 ; }