void FASTWRITE ( long long int x ) { char str [ 20 ] ; int i = 0 ; if ( x < 0 ) { putchar_unlocked ( '-' ) ; x *= - 1 ; } do { str [ i ++ ] = x + 48 ; x /= 10 ; } while ( x != 0 ) ; for ( i -- ; i >= 0 ; i -- ) putchar_unlocked ( str [ i ] ) ; } long long int fastread ( ) { long long int input = 0 ; char c = getchar_unlocked ( ) ; while ( c < 33 ) c = getchar_unlocked ( ) ; while ( c > 33 ) { input = input * 10 + c - '0' ; c = getchar_unlocked ( ) ; } return input ; } int main ( ) { long long int t , a , b , i , j , num , dend , div , quo , rem = - 1 , gcd , lcm , k ; t = fastread ( ) ; while ( t -- ) { rem = - 1 ; a = fastread ( ) ; b = fastread ( ) ; if ( a > b ) { dend = a ; div = b ; } else { dend = b ; div = a ; } while ( rem != 0 ) { rem = dend % div ; dend = div ; div = rem ; } gcd = dend ; lcm = a * b / gcd ; putchar_unlocked ( '\n' ) ; FASTWRITE ( gcd ) ; putchar_unlocked ( ' ' ) ; FASTWRITE ( lcm ) ; } return 0 ; }