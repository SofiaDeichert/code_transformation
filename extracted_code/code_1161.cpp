int main ( ) { long long int t , n , i , j , count ; scanf ( "%lld" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { count = 0 ; scanf ( "%lld" , & n ) ; long long int a [ n ] ; for ( j = 0 ; j < n ; j ++ ) { scanf ( "%lld" , & a [ j ] ) ; if ( a [ j - 1 ] <= a [ j ] && j > 0 ) count ++ ; else continue ; } count = n + count ; printf ( "%lld\n" , count ) ; } return 0 ; }