int main ( ) { long int a , b , T , i = 1 , GCD , LCM ; scanf ( "%ld" , & T ) ; while ( T -- ) { scanf ( "%ld %ld" , & a , & b ) ; if ( a > b ) { for ( i = b ; i >= 1 ; i -- ) { if ( b % i == 0 && a % i == 0 ) { GCD = i ; break ; } } for ( i = a ; i <= a * b ; i ++ ) { if ( i % a == 0 && i % b == 0 ) { LCM = i ; break ; } } printf ( "%ld %ld\n" , GCD , LCM ) ; } else if ( b > a ) { for ( i = a ; i >= 1 ; i -- ) { if ( a % i == 0 && b % i == 0 ) { GCD = i ; break ; } } for ( i = b ; i <= a * b ; i ++ ) { if ( i % a == 0 && i % b == 0 ) { LCM = i ; break ; } } printf ( "%ld %ld\n" , GCD , LCM ) ; } } return 0 ; }