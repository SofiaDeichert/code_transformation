long long int gcd ( long long int a , long long int b ) { if ( a > b ) { if ( a % b == 0 ) { return b ; } else { return gcd ( b , a % b ) ; } } if ( a < b ) { if ( b % a == 0 ) { return a ; } else { return gcd ( a , b % a ) ; } } } long long int max ( long long int a , long long int b ) { if ( a > b ) { return a ; } else { return b ; } } long long int lcm ( long long int a , long long int b ) { long long int i , lc = 1 , maxi ; maxi = max ( a , b ) ; while ( a != 1 && b != 1 ) { for ( i = 2 ; i <= maxi / 2 ; i ++ ) { if ( a % i == 0 && b % i != 0 ) { lc *= i ; a /= i ; } else if ( a % i != 0 && b % i == 0 ) { lc *= i ; b /= i ; } else if ( ( a % i == 0 && b % i == 0 ) ) { lc *= i ; a /= i ; b /= i ; } } } return lc ; } void main ( ) { long long int a , b , gc , lc , t ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld%lld" , & a , & b ) ; gc = gcd ( a , b ) ; lc = lcm ( a , b ) ; printf ( "LCM:%lld   GCD:%lld\n" , lc , gc ) ; } }