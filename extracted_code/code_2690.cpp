long min ( long pg , long ss ) { return ss < pg ? ss : pg ; } int main ( ) { long n , i , pos , t ; scanf ( "%ld" , & t ) ; while ( t -- ) { scanf ( "%ld" , & n ) ; long pg = 0 , ss = 99999999 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%ld" , & pg ) ; ss = min ( ss , pg ) ; } printf ( "%ld\n" , ss * ( n - 1 ) ) ; } return 0 ; }