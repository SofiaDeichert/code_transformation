int maxi ( int a , int b ) { return a < b ? b : a ; } int main ( ) { int test ; scanf ( "%d" , & test ) ; int i , j , n , max ; while ( test -- ) { scanf ( "%d" , & n ) ; int vec1 [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & vec1 [ i ] [ j ] ) ; for ( i = 1 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { if ( j == 0 ) { vec1 [ i ] [ j ] = vec1 [ i - 1 ] [ j ] + vec1 [ i ] [ j ] ; } else if ( j == i ) { vec1 [ i ] [ j ] = vec1 [ i - 1 ] [ j - 1 ] + vec1 [ i ] [ j ] ; } else if ( vec1 [ i - 1 ] [ j ] > vec1 [ i - 1 ] [ j - 1 ] ) { vec1 [ i ] [ j ] = vec1 [ i - 1 ] [ j ] + vec1 [ i ] [ j ] ; } else { vec1 [ i ] [ j ] = vec1 [ i - 1 ] [ j - 1 ] + vec1 [ i ] [ j ] ; } } } max = vec1 [ n - 1 ] [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { if ( vec1 [ n - 1 ] [ i ] > max ) max = vec1 [ n - 1 ] [ i ] ; } printf ( "%d\n" , max ) ; } return 0 ; }