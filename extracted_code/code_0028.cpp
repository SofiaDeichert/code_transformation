int main ( ) { int t , max [ 100 ] , i , j , a [ 100 ] [ 100 ] , temp1 , temp2 , max1 , n , temp3 ; scanf ( "%d" , & t ) ; while ( t -- ) { for ( i = 0 ; i < 100 ; i ++ ) max [ i ] = 0 ; max1 = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { if ( j == 0 ) { temp3 = max [ 0 ] ; max [ 0 ] += a [ i ] [ 0 ] ; } else { temp1 = temp3 + a [ i ] [ j ] ; temp3 = max [ j ] ; temp2 = temp3 + a [ i ] [ j ] ; if ( temp1 > temp2 ) max [ j ] = temp1 ; else max [ j ] = temp2 ; } } } for ( i = 0 ; i < n ; i ++ ) if ( max1 < max [ i ] ) max1 = max [ i ] ; printf ( "%d\n" , max1 ) ; } return 0 ; }