int main ( ) { int t ; scanf ( "%d" , & t ) ; for ( int i = 0 ; i < t ; i ++ ) { int n ; scanf ( "%d" , & n ) ; int line [ n ] [ n ] ; for ( int j = 0 ; j < n ; j ++ ) { for ( int k = 0 ; k < j + 1 ; k ++ ) { scanf ( "%d" , & line [ j ] [ k ] ) ; } } for ( int j = 1 ; j < n ; j ++ ) { line [ j ] [ 0 ] += line [ j - 1 ] [ 0 ] ; } for ( int k = 1 ; k < n ; k ++ ) { line [ k ] [ k ] += line [ k - 1 ] [ k - 1 ] ; for ( int j = k + 1 ; j < n ; j ++ ) { if ( line [ j - 1 ] [ k - 1 ] > line [ j - 1 ] [ k ] ) line [ j ] [ k ] += line [ j - 1 ] [ k - 1 ] ; else line [ j ] [ k ] += line [ j - 1 ] [ k ] ; } } int max = 0 ; for ( int k = 0 ; k < n ; k ++ ) { if ( max < line [ n - 1 ] [ k ] ) max = line [ n - 1 ] [ k ] ; } printf ( "%d\n" , max ) ; } return 0 ; }