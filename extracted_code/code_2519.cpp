int n = 0 , aj = 0 ; summ ( int a [ n ] [ n ] , int i , int j ) { if ( i == ( n - 1 ) ) return a [ i ] [ j ] ; int sum1 = a [ i ] [ j ] + summ ( a , i + 1 , j ) ; int sum2 = a [ i ] [ j ] + summ ( a , i + 1 , j + 1 ) ; if ( sum1 > sum2 ) return ( sum1 ) ; else return ( sum2 ) ; } main ( ) { int i , j , t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; int a [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { printf ( "%d " , a [ i ] [ j ] ) ; } printf ( "\n" ) ; } int s = summ ( a , 0 , 0 ) ; printf ( "%d\n" , s ) ; } }