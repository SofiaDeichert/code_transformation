int gcd ( int a , int b ) { if ( a == 0 ) return b ; else return gcd ( b % a , a ) ; } int main ( void ) { int hcf , lcm ; int T ; int A , B ; scanf ( "%d" , & T ) ; while ( T -- > 0 ) { scanf ( "%d" , & A ) ; scanf ( "%d" , & B ) ; hcf = gcd ( A , B ) ; printf ( "%d %d\n" , hcf , A * B / hcf ) ; } return 0 ; }