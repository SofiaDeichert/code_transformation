int main ( ) { int t , n1 , n2 , i , j , max , gcd ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d %d" , & n1 , & n2 ) ; for ( j = 0 ; j < n1 || j < n2 ; j ++ ) { if ( n1 % j == 0 && n2 % j == 0 ) gcd = j ; } printf ( "%d" , gcd ) ; max = n1 > n2 ? n1 : n2 ; while ( 1 ) { if ( max % n1 == 0 && max % n2 == 0 ) printf ( "%d" , max ) ; break ; } max ++ ; } return 0 ; }