int main ( ) { long long t , i ; scanf ( "%lld" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { long long n , j , k = 0 , l , a ; scanf ( "%lld" , & n ) ; scanf ( "%lld" , & a ) ; for ( j = 1 ; j < n ; j ++ ) { long long b ; scanf ( "%lld" , & b ) ; if ( a > b ) a = b ; } k = a * ( n - 1 ) ; printf ( "%lld\n" , k ) ; } return 0 ; }