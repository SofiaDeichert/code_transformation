int main ( ) { unsigned int t ; unsigned long n , i , j ; long long int a [ 200000 ] , sum , k , l ; scanf ( "%u" , & t ) ; while ( t ) { scanf ( "%lu" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%lld" , & a [ i ] ) ; k = 0 ; l = 0 ; for ( i = 0 ; i < n - 1 ; i ++ ) { if ( a [ i ] <= a [ i + 1 ] ) l ++ ; else { k = k + l * ( l + 1 ) / 2 ; l = 0 ; } } k = k + l * ( l + 1 ) / 2 ; sum = k + n ; printf ( "%lld\n" , sum ) ; t -- ; } }