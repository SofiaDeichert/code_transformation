int main ( ) { long int T , j , i , N ; scanf ( "%ld" , & T ) ; for ( j = 0 ; j < T ; j ++ ) { long int cost , small ; scanf ( "%ld" , & N ) ; long int arr [ N ] ; for ( i = 0 ; i < N ; i ++ ) { scanf ( "%ld" , & arr [ i ] ) ; } small = arr [ 0 ] ; for ( i = 0 ; i < N ; i ++ ) { if ( arr [ i ] < small ) small = arr [ i ] ; } cost = small * ( N - 1 ) ; printf ( "%ld\n" , cost ) ; } }