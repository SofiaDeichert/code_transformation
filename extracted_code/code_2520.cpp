int main ( ) { int T ; scanf ( "%d" , & T ) ; for ( int i = 0 ; i < T ; ++ i ) { int N ; scanf ( "%d" , & N ) ; int arr [ N ] ; for ( int i = 0 ; i < N ; ++ i ) scanf ( "%d" , & arr [ i ] ) ; int Total = 1 ; int Counter = 1 ; int Max = arr [ 0 ] ; for ( int j = 1 ; j < N ; ++ j ) { if ( arr [ j ] >= Max ) { Counter ++ ; Total += Counter ; Max = arr [ j ] ; } else { Counter = 1 ; Total += Counter ; Max = arr [ j ] ; } } printf ( "%d \n" , Total ) ; } return 0 ; }