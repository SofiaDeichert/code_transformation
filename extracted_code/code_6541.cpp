int main ( ) { int t , A [ 100 ] , i , n , piv , cost = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & A [ i ] ) ; } piv = A [ 0 ] ; for ( i = 0 ; i < n - 1 ; i ++ ) { if ( piv > A [ i + 1 ] ) piv = A [ i + 1 ] ; cost = cost + piv ; } printf ( "%d\n" , cost ) ; cost = 0 ; } return 0 ; }