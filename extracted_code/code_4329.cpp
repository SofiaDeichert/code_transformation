int main ( ) { int T ; long long int N ; scanf ( "%d" , & T ) ; for ( int i = 0 ; i < T ; i ++ ) { scanf ( "%lld" , & N ) ; int ar [ N ] ; long long int min = 11111101 ; for ( int j = 0 ; j < N ; j ++ ) { scanf ( "%d" , & ar [ j ] ) ; if ( min > ar [ j ] ) min = ar [ j ] ; } printf ( "%d\n" , min ) ; long long cost = min * ( N - 1 ) ; printf ( "%lld\n" , cost ) ; } return 0 ; }