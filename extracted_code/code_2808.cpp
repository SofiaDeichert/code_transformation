int main ( ) { int t , n1 , n2 , gcd , lcm , k , l , temp ; scanf ( "%d" , & t ) ; while ( t -- > 0 ) { scanf ( "%d %d" , & n1 , & n2 ) ; k = n1 ; l = n2 ; while ( n1 % n2 != 0 ) { temp = n2 ; n2 = n1 % n2 ; n1 = temp ; } gcd = n2 ; lcm = k * l / gcd ; printf ( "%d %d\n" , gcd , lcm ) ; gcd = 0 ; lcm = 0 ; } return 0 ; }