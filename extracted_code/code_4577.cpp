int main ( ) { int t , i , j , k , l , n [ 100 ] [ 100 ] , b = 0 , c = 0 ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d" , & l ) ; for ( j = 0 ; j < l ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) scanf ( "%d" , & n [ j ] [ k ] ) ; } for ( k = 0 ; k < l ; k ++ ) { for ( j = 0 ; j < l ; j ++ ) b += n [ j ] [ k ] ; if ( b > c ) c = b ; b = 0 ; } printf ( "%d\n" , c + 1 ) ; } return 0 ; }