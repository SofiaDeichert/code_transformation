int main ( ) { int a , b , c , d , i , p , q , l ; scanf ( "%d" , & a ) ; for ( i = 0 ; i < a ; i ++ ) { scanf ( "%d %d" , & b , & c ) ; if ( b > c ) { p = b ; q = c ; } else { p = c ; q = b ; } for ( i = 1 ; i <= q ; i ++ ) { if ( ( p % i == 0 ) && ( q % i == 0 ) ) { d = i ; } } l = b * c / d ; printf ( "%d %d\n" , d , l ) ; } return 0 ; }