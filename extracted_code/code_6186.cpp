int main ( ) { int T , A , B , a , b , gcd , lcm , n = 1 ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d %d" , & A , & B ) ; if ( A > B ) { a = A ; b = B ; } else { a = B ; b = A ; } while ( n ) { n = a % b ; a = b ; b = n ; } gcd = a ; lcm = ( A * B ) / gcd ; printf ( "%d %d\n" , gcd , lcm ) ; } }