int main ( ) { int n , i = 0 , j = 0 , max1 = 0 , max2 = 0 , max , t ; scanf ( "%d\n" , & t ) ; while ( t ) { scanf ( "%d\n" , & n ) ; int A [ 100 ] [ 100 ] ; int m [ 100 ] [ 100 ] ; scanf ( "%d" , & A [ 0 ] [ 0 ] ) ; m [ 0 ] [ 0 ] = A [ 0 ] [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & A [ i ] [ j ] ) ; m [ i ] [ 0 ] = m [ i - 1 ] [ 0 ] + A [ i ] [ 0 ] ; } max = m [ n - 1 ] [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) { if ( i == j ) m [ i ] [ j ] = m [ i - 1 ] [ j - 1 ] + A [ i ] [ j ] ; else { max1 = m [ i - 1 ] [ j ] + A [ i ] [ j ] ; max2 = m [ i - 1 ] [ j - 1 ] + A [ i ] [ j ] ; if ( max1 > max2 ) m [ i ] [ j ] = max1 ; else m [ i ] [ j ] = max2 ; if ( max < m [ i ] [ j ] ) max = m [ i ] [ j ] ; } } } printf ( "%d\n" , max ) ; t -- ; } return 0 ; }