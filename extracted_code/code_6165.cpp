int main ( ) { int t , i , n , sum ; scanf ( "%d" , & t ) ; while ( t > 0 ) { sum = 0 ; scanf ( "%d" , & n ) ; int a [ n + 1 ] , b [ n + 1 ] ; for ( i = 1 ; i <= n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } b [ 0 ] = 1 ; for ( i = 1 ; i < n ; i ++ ) { if ( a [ i ] <= a [ i + 1 ] ) { b [ i ] = b [ i - 1 ] + 1 ; } else { b [ i ] = 1 ; } } for ( i = 0 ; i < n ; i ++ ) { sum = sum + b [ i ] ; } printf ( "%d\n" , sum ) ; t -- ; } }