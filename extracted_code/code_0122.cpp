unsigned long int gcd ( unsigned long int , unsigned long int ) ; unsigned long long int lcm ( unsigned long int , unsigned long int ) ; int main ( void ) { int t ; scanf ( "%d" , & t ) ; unsigned long int a , b , temp ; unsigned long int hcf ; unsigned long long int mcl ; while ( t -- ) { scanf ( "%lu %lu" , & a , & b ) ; if ( a > b ) { temp = a ; a = b ; b = temp ; } hcf = gcd ( a , b ) ; printf ( "%lu %llu\n" , hcf , a * b / hcf ) ; } return 0 ; } unsigned long int gcd ( unsigned long int a , unsigned long int b ) { if ( a == 0 ) return b ; else { return gcd ( b % a , a ) ; } }