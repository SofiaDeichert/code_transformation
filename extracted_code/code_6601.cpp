long long int max ( long long int a , long long int b ) { if ( a > b ) return a ; else return b ; } int main ( ) { long long int t , r , i , k , tri [ 1001 ] [ 1001 ] , j , sum ; scanf ( "%lld" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%lld" , & r ) ; for ( k = 0 ; k < r ; k ++ ) { for ( j = 0 ; j <= k ; j ++ ) { scanf ( "%lld" , & tri [ k ] [ j ] ) ; } } for ( k = 1 ; k < r ; k ++ ) { for ( j = 0 ; j <= k ; j ++ ) { if ( j == 0 ) { tri [ k ] [ j ] = tri [ k ] [ j ] + tri [ k - 1 ] [ j ] ; } else if ( j == i ) { tri [ k ] [ j ] = tri [ k ] [ j ] + tri [ k - 1 ] [ j - 1 ] ; } else { tri [ k ] [ j ] = tri [ k ] [ j ] + max ( tri [ k - 1 ] [ j ] , tri [ k - 1 ] [ j - 1 ] ) ; } } } sum = 0 ; for ( j = 0 ; j < r ; j ++ ) { if ( tri [ r - 1 ] [ j ] > sum ) sum = tri [ r - 1 ] [ j ] ; } printf ( "%lld\n" , sum ) ; } return 0 ; }