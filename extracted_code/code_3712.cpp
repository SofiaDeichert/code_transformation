int n ; int arr [ 100 ] [ 100 ] ; int maxsum ( int i , int j ) { if ( j == - 1 || j > i ) return 0 ; return arr [ i ] [ j ] + maximum ( maxsum ( i - 1 , j ) , maxsum ( i - 1 , j - 1 ) ) ; } int maximum ( int i , int j ) { if ( i > j ) return i ; return j ; } int main ( ) { int t ; scanf ( "%d" , & t ) ; int i , j ; int max ; while ( t -- != 0 ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; } } max = 0 ; for ( i = 0 ; i < n ; i ++ ) { max = maximum ( max , maxsum ( n - 1 , i ) ) ; } printf ( "%d\n" , max ) ; } return 0 ; }