int main ( ) { int a , b , c , t ; scanf ( "%d" , & t ) ; if ( t >= 1 && t <= 1000 ) { while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; c = a * b ; while ( a != b ) { if ( a > b ) { a = a - b ; } else { b = b - a ; } } printf ( "%d\t%d\n" , a , c / a ) ; } } return 0 ; }