(define (sum1 n)
	(cond 
		((null? n) ())
		((null? (cdr n)) (car n) )
		(else (list  (sum1 (cdr n))  (car n)))
	)
)
(sum1 (list 1 2 3 4))
