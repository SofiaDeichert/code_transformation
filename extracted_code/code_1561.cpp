int main ( ) { long long n , i , j , n1 , n2 ; scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { long long a , b ; scanf ( "%lld %lld" , & a , & b ) ; n1 = a , n2 = b ; while ( a != b ) { if ( a > b ) a -= b ; else b -= a ; } printf ( "%lld %lld\n" , a , ( n1 * n2 ) / a ) ; } }