void play ( int n1 , int n2 , int num1 , int num2 , int rem , int GCD , int LCM ) { if ( n2 != 0 ) { rem = n1 % n2 ; n1 = n2 ; n2 = rem ; play ( n1 , n2 , num1 , num2 , rem , GCD , LCM ) ; } else { GCD = n1 ; LCM = ( num1 * num2 ) / GCD ; printf ( "%d %d\n" , GCD , LCM ) ; } } int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n1 , n2 , num1 , num2 , rem , GCD , LCM ; scanf ( "%d %d" , & num1 , & num2 ) ; n1 = num1 , n2 = num2 ; play ( n1 , n2 , num1 , num2 , rem , GCD , LCM ) ; } }