int main ( ) { long int testc , a [ 10 ] , n , i , j , k , flag = 0 , s = 0 ; scanf ( "%d" , & testc ) ; int sub [ 5 ] ; while ( s < testc ) { scanf ( "%d" , & n ) ; sub [ s ] = n ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = i + 1 ; j < n ; j ++ ) { flag = 0 ; if ( a [ i ] < a [ j ] ) { for ( k = i ; k < j ; k ++ ) { if ( ( a [ k ] < a [ i ] ) || ( a [ k ] > a [ j ] ) ) flag ++ ; } if ( flag == 0 ) sub [ s ] ++ ; } } } s ++ ; } printf ( "\n" ) ; for ( i = 0 ; i < testc ; i ++ ) printf ( "%d\n" , sub [ i ] ) ; return 0 ; }