int main ( ) { int t ; int a , b ; int gcd ; long long int lcm ; scanf ( "%d" , & t ) ; while ( t > 0 ) { scanf ( "%d%d" , & a , & b ) ; long long int product = ( a * b ) ; int small = ( a < b ) ? a : b ; int big = ( a > b ) ? a : b ; if ( ( a % small ) == 0 && ( b % small ) == 0 ) gcd = small ; else { int remainder = big % small ; int keep = small ; int temp ; while ( remainder != 0 ) { temp = remainder ; remainder = keep % remainder ; keep = temp ; } gcd = keep ; } lcm = product / gcd ; printf ( "%d %lld\n" , gcd , lcm ) ; t -- ; } return 0 ; }