long int gcd ( long long int x , long long int y ) { long long int temp ; while ( y % x != 0 ) { temp = x ; x = y % x ; y = temp ; } return x ; } int main ( ) { long long int x , y , l , g , t ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld %lld" , & x , & y ) ; g = gcd ( x , y ) ; l = x * y / g ; printf ( "%ld %lld\n" , g , l ) ; } return 0 ; }