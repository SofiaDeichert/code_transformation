int main ( ) { long long int N , T , t , i , sum ; scanf ( "%lld" , & T ) ; for ( t = 0 ; t < T ; t ++ ) { scanf ( "%lld" , & N ) ; long long int * array = ( long long int * ) malloc ( sizeof ( long long int ) * N ) ; long long int * dp = ( long long int * ) malloc ( sizeof ( long long int ) * N ) ; for ( i = 0 ; i < N ; i ++ ) { scanf ( "%lld" , & array [ i ] ) ; dp [ i ] = 1 ; } sum = dp [ 0 ] ; for ( i = 1 ; i < N ; i ++ ) { if ( array [ i ] >= array [ i - 1 ] ) { dp [ i ] = dp [ i - 1 ] + 1 ; } sum += dp [ i ] ; } printf ( "%lld\n" , sum ) ; } return 0 ; }