int main ( ) { int T , l , lcm ; long A , B ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%ld%ld" , & A , & B ) ; if ( A < B ) l = A ; else l = B ; l -- ; while ( l != 1 ) { if ( A % l == 0 && B % l == 0 ) break ; l -- ; } lcm = ( A * B ) / l ; printf ( "%d %d\n" , l , lcm ) ; } return 0 ; }