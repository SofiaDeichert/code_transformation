long int gcd ( long int , long int ) ; int main ( void ) { int t ; long int a , b , g , temp , l ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld%ld" , & a , & b ) ; if ( a > b ) { temp = a ; a = b ; b = temp ; } g = gcd ( a , b ) ; l = ( a * b ) / g ; printf ( "%ld %ld\n" , g , l ) ; } return 0 ; } long int gcd ( long int a , long int b ) { long int min = a , max = b , temp ; while ( 1 ) { temp = min ; min = max % min ; max = temp ; if ( min == 0 ) return max ; } }