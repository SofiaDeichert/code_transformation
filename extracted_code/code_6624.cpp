int main ( ) { long long int min , n2 ; long long int T , n , i ; scanf ( "%lld" , & T ) ; while ( T -- ) { scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & n2 ) ; if ( i == 0 ) { min = n2 ; } else if ( min > n2 ) { min = n2 ; } } printf ( "%lld\n" , min * ( n - 1 ) ) ; } return 0 ; }