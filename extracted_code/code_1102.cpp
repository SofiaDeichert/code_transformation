long GCD ( int A , int B ) { long reminder ; if ( B > A ) { int temp ; temp = A ; A = B ; B = temp ; } while ( B ) { reminder = A % B ; A = B ; B = reminder ; } return A ; } long LCM ( int A , int B ) { return ( A * B ) / GCD ( A , B ) ; } int main ( void ) { int T , A , B ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d%d" , & A , & B ) ; printf ( "%ld %ld\n" , GCD ( A , B ) , LCM ( A , B ) ) ; } return 0 ; }