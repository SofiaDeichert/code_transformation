int main ( ) { int A , B , lcm , gcd , i , T , min ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d%d" , & A , & B ) ; if ( A > B ) min = B ; else if ( A < B ) min = A ; for ( i = 1 ; i <= min ; i ++ ) { if ( ( A % i == 0 ) && ( B % i == 0 ) ) gcd = i ; } lcm = ( A * B ) / gcd ; printf ( "%d %d\n" , gcd , lcm ) ; } return 0 ; }