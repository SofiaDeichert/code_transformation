int gcd ( int a , int b ) { if ( a == 0 ) { return b ; } else { return gcd ( b % a , a ) ; } } unsigned long long int lcm ( unsigned long long int a , unsigned long long int b ) { long int g ; g = gcd ( a , b ) ; if ( g == 1 ) { return a * b ; } else { return g * lcm ( a / g , b / g ) ; } } int main ( void ) { unsigned long long int T , A , B , i , g , l ; scanf ( "%llu" , & T ) ; for ( i = 0 ; i < T ; i ++ ) { scanf ( "%llu%llu" , & A , & B ) ; g = gcd ( A , B ) ; l = lcm ( A , B ) ; printf ( "%llu %llu\n" , g , l ) ; } return 0 ; }