int main ( ) { int i , T , A , B , r , n1 , n2 , gcd , lcm , l , s ; scanf ( "%d" , & T ) ; for ( i = 0 ; i < T ; i ++ ) { scanf ( "%d\t%d" , & A , & B ) ; if ( A > B ) { l = A ; s = B ; } else { l = B ; s = A ; } r = l % s ; while ( r != 0 ) { l = s ; s = r ; r = l % s ; } gcd = s ; lcm = ( A * B ) / gcd ; printf ( "%d %d\n" , gcd , lcm ) ; } return 0 ; }