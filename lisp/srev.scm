(define (reverse1 l)
	 (
	 	if (null? (cdr l)) 
	 		()
	 	(reverse1 (cdr l));else statement
	 )
	 
	 (display (car l))
	 (display " ")
	 
)
(define a (list 1 2 3))
(reverse1 a)

