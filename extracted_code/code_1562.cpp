int main ( ) { int t , n , a [ 100 ] [ 100 ] ; scanf ( "%d" , & t ) ; while ( t -- ) { int s1 = 0 , s2 = 0 , i , j ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } int k = 0 ; s1 = s2 = a [ 0 ] [ 0 ] ; for ( i = 0 ; i < n - 1 ; i ++ ) { j = k ; s1 = s1 + a [ i + 1 ] [ j ] ; s2 = s2 + a [ i + 1 ] [ j + 1 ] ; if ( s1 > s2 ) { s2 = s1 ; k = j ; } else { s1 = s2 ; k = j + 1 ; } } printf ( "%d" , s1 ) ; } return 0 ; }