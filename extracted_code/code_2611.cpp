long long int gcd ( long long int , long long int ) ; int main ( ) { int cases ; scanf ( "%d" , & cases ) ; while ( cases -- ) { long long int num1 , num2 , g_c_d , l_c_m ; scanf ( "%lld%lld" , & num1 , & num2 ) ; long long int prod = num1 * num2 ; g_c_d = gcd ( num1 , num2 ) ; l_c_m = ( prod / g_c_d ) ; printf ( "%lld %lld" , g_c_d , l_c_m ) ; printf ( "\n" ) ; } return 0 ; } long long int gcd ( long long int a , long long int b ) { if ( b == 0 ) { return a ; } else { return gcd ( b , a % b ) ; } }