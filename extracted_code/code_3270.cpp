int main ( ) { long long int T , N , i , num , t , min ; scanf ( "%lld" , & T ) ; while ( T -- ) { scanf ( "%lld" , & N ) ; t = N ; min = 9999999999 ; while ( N -- ) { scanf ( "%lld" , & num ) ; if ( num < min ) min = num ; } printf ( "%lld\n" , min * ( t - 1 ) ) ; } return 0 ; }