int read_int ( ) { int s = 0 ; char c ; while ( ( c = getchar_unlocked ( ) ) != ' ' && c != '\n' ) s = s * 10 + ( c - '0' ) ; return s ; } void write_int ( int n ) { char c [ 25 ] = { '\0' } ; int j , i = 0 ; while ( n ) { c [ i ++ ] = n ; n = n / 10 ; } for ( j = i - 1 ; j >= 0 ; j -- ) putchar_unlocked ( c [ j ] + '0' ) ; } int sum ( int a [ 5055 ] , int i , int j , int n ) { int m = i * ( i - 1 ) / 2 + j ; int max = - 1 , k , v1 , v2 ; if ( i == n - 1 ) if ( a [ m + i ] > a [ m + i + 1 ] ) return a [ m ] + a [ m + i ] ; else return a [ m ] + a [ m + i + 1 ] ; v1 = a [ m ] + sum ( a , i + 1 , j , n ) ; v2 = a [ m ] + sum ( a , i + 1 , j + 1 , n ) ; if ( v1 > v2 ) return v1 ; else return v2 ; } int main ( void ) { int t , n , a [ 5055 ] ; int i ; t = read_int ( ) ; while ( t -- ) { n = read_int ( ) ; for ( i = 1 ; i <= n * ( n + 1 ) / 2 ; i ++ ) a [ i ] = read_int ( ) ; write_int ( sum ( a , 1 , 1 , n ) ) ; printf ( "\n" ) ; } return 0 ; }