int main ( ) { long long int t , i , j , k , n [ 7 ] [ 100000 ] , flag ; scanf ( "%lld" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%lld" , & n [ i ] [ 0 ] ) ; for ( j = 1 ; j <= n [ i ] [ 0 ] ; j ++ ) scanf ( "%lld" , & n [ i ] [ j ] ) ; } for ( i = 0 ; i < t ; i ++ ) { j = 1 ; k = j + 1 ; while ( j <= n [ i ] [ 0 ] ) { if ( n [ i ] [ j ] < n [ i ] [ k ] ) flag ++ ; j ++ ; } flag = flag + n [ i ] [ 0 ] ; printf ( "%lld\n" , flag ) ; } return 0 ; }