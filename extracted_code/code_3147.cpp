long long int findHCF ( int , int ) ; int main ( ) { int T ; scanf ( "%d" , & T ) ; long long int a , b , LCM , HCF ; for ( int i = 0 ; i < T ; i ++ ) { scanf ( "%lld %lld" , & a , & b ) ; HCF = findHCF ( a , b ) ; LCM = a * b / HCF ; printf ( "%lld %lld\n" , HCF , LCM ) ; } return 0 ; } long long int findHCF ( int a , int b ) { int remainder = a % b ; if ( remainder == 0 ) { return b ; } else { return findHCF ( b , remainder ) ; } }