int sumtri ( int a [ 100 ] [ 100 ] , int n ) { int i = 1 , j = 0 , x , y , s1 = 0 , s2 = 0 ; if ( n == 1 ) return a [ 0 ] [ 0 ] ; s1 += a [ i ] [ j ] ; s2 += a [ i ] [ j + 1 ] ; x = j ; y = j + 1 ; for ( i = 2 ; i <= ( n - 1 ) ; i ++ ) { if ( a [ i ] [ x ] <= a [ i ] [ x + 1 ] ) { s1 += a [ i ] [ x + 1 ] ; x += 1 ; } else s1 += a [ i ] [ x ] ; if ( a [ i ] [ y ] <= a [ i ] [ y + 1 ] ) { s2 += a [ i ] [ y + 1 ] ; y += 1 ; } else s2 += a [ i ] [ y ] ; } if ( s1 > s2 ) return s1 + a [ 0 ] [ 0 ] ; else return s2 + a [ 0 ] [ 0 ] ; } main ( ) { int a [ 100 ] [ 100 ] , t , i , j , n ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; printf ( "%d\n" , sumtri ( a , n ) ) ; } }