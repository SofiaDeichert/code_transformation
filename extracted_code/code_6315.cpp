int main ( ) { int t , n , i , sum = 0 ; scanf ( "%d" , & t ) ; while ( t ) { scanf ( "%d" , & n ) ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } for ( i = 0 ; i < n - 1 ; i ++ ) { if ( a [ i ] > a [ i + 1 ] ) sum = sum * a [ i + 1 ] ; else sum = sum * a [ i ] ; } printf ( "%d\n" , sum ) ; sum = 0 ; t -- ; } }