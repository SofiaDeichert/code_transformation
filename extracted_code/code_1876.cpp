int main ( ) { long long int t , n , i , j , min = 9999999999 , val ; scanf ( "%lld" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { min = 9999999999 ; scanf ( "%lld" , & n ) ; for ( j = 0 ; j < n ; j ++ ) { scanf ( "%lld" , & val ) ; if ( val < min ) min = val ; } printf ( "%lld \n" , min * ( n - 1 ) ) ; } return 0 ; }