int GCD ( int , int ) ; int LCM ( int , int ) ; int main ( ) { int n1 , n2 , T , res1 , res2 ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d %d" , & n1 , & n2 ) ; res1 = GCD ( n1 , n2 ) ; res2 = LCM ( n1 , n2 ) ; printf ( "%d %d\n" , res1 , res2 ) ; } return 0 ; } int GCD ( int a , int b ) { int c = 0 , i , r1 = 0 ; if ( a == b ) { return a ; } if ( a > b ) { c = b ; } if ( b > a ) { c = a ; } for ( i = 1 ; i <= c ; i ++ ) { if ( a % i == 0 && b % i == 0 ) { r1 = i ; } } return r1 ; } int LCM ( int a , int b ) { if ( a % b == 0 ) { return a ; } else if ( b % a == 0 ) { return b ; } else { return a * b ; } }