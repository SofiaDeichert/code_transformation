int main ( void ) { int T ; int n , i , j ; int len ; scanf ( "%d" , & T ) ; int arr [ 4955 ] ; while ( T -- ) { scanf ( "%d" , & n ) ; len = ( n * ( n + 1 ) ) / 2 ; arr [ 0 ] = 0 ; i = 0 ; j = 0 ; for ( i = 1 ; i <= len ; i ++ ) { scanf ( "%d" , & arr [ i ] ) ; } for ( i = 1 ; i <= n ; i ++ ) { int l = ( i * ( i - 1 ) ) / 2 + 1 ; int l2 = l + i ; for ( j = l ; j < l2 ; j ++ ) { if ( j - i > l - i && j - i + 1 < l ) { if ( arr [ j - i ] >= arr [ j - i + 1 ] ) { arr [ j ] += arr [ j - i ] ; } else { arr [ j ] += arr [ j - i + 1 ] ; } } else if ( j - i + 1 < l ) { arr [ j ] += arr [ j - i + 1 ] ; } else if ( j - i > l - i ) { arr [ j ] += arr [ j - i ] ; } } } int max = 0 ; for ( i = len ; i >= len - n + 1 ; i -- ) { if ( max < arr [ i ] ) { max = arr [ i ] ; } } printf ( "%d\n" , max ) ; } return 0 ; }