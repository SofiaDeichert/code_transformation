unsigned long long int gcd ( unsigned long long int a , unsigned long long int b ) ; int main ( ) { unsigned long long int t , a , b , g , l ; scanf ( "%llu" , & t ) ; while ( t != 0 ) { scanf ( "%llu%llu" , & a , & b ) ; g = gcd ( a , b ) ; l = ( a / g ) * b ; printf ( "\n%llu %llu" , g , l ) ; t -- ; } return 0 ; } unsigned long long int gcd ( unsigned long long int a , unsigned long long int b ) { unsigned long long int t ; while ( b != 0 ) { t = a % b ; a = b ; b = t ; } return a ; }