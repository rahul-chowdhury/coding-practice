(define square
	(lambda (x) 
	(* x x)
	)
)
(square 3)
(square 4)
(square 5)
(square 6)
(define (power x)
	((lambda (a) (* a a) ) (* x x))
)
(power 3)
(power 4)
(power 5)
(power 6)	
