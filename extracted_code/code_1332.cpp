int s [ 100 ] [ 100 ] , t [ 100 ] [ 100 ] ; int main ( ) { int n , i , j , a , flag = 0 , x ; scanf ( "%d" , & x ) ; while ( x -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & s [ i ] [ j ] ) ; t [ 0 ] [ 0 ] = s [ 0 ] [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) { if ( j == 0 ) t [ i ] [ j ] = s [ i ] [ j ] + t [ i - 1 ] [ j ] ; else if ( i == j ) t [ i ] [ j ] = s [ i ] [ j ] + t [ i - 1 ] [ j - 1 ] ; else { if ( flag == 0 ) { t [ i ] [ j ] = s [ i ] [ j ] + t [ i - 1 ] [ j - 1 ] ; flag = 1 ; } if ( flag == 1 ) { if ( t [ i ] [ j ] < s [ i ] [ j ] + t [ i - 1 ] [ j ] ) t [ i ] [ j ] = s [ i ] [ j ] + t [ i - 1 ] [ j ] ; flag = 0 ; } } } a = t [ n - 1 ] [ 0 ] ; for ( j = 1 , i = n ; j <= i ; j ++ ) { if ( a < t [ n - 1 ] [ j ] ) a = t [ n - 1 ] [ j ] ; } printf ( "%d" , a ) ; } return 0 ; }