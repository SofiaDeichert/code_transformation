int main ( void ) { int T , A , B , c , A1 , B1 ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d%d" , & A1 , & B1 ) ; A = A1 ; B = B1 ; while ( B ) { A = A % B ; A ^= B ^= A ^= B ; } printf ( "%d %d\n" , A , A1 * ( B1 / A ) ) ; } return 0 ; }