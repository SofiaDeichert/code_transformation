int main ( ) { long long int n , t , i , j , c , k ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; long long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%lld" , & a [ i ] ) ; c = n ; for ( i = 0 ; i < n - 1 ; i ++ ) { k = 0 ; while ( a [ i + 1 ] > a [ i ] && i < n - 1 ) { k ++ ; i ++ ; } c += k * ( k + 1 ) / 2 ; } printf ( "%lld\n" , c ) ; } }