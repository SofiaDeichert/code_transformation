int main ( ) { int a , b = 1 , c , d , e , f ; scanf ( "%d\n" , & a ) ; while ( b <= a ) { scanf ( "%d %d\n" , & c , & d ) ; if ( c < d ) e = c , f = d ; else e = d , f = c ; while ( ! ( c % e == 0 && d % e == 0 ) ) { e -- ; } printf ( "%d " , e ) ; while ( ! ( f % c == 0 && f % d == 0 ) ) { f ++ ; } printf ( "%d\n" , f ) ; b ++ ; } return 0 ; }