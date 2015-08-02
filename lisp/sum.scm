
(define (leng l)
	
	(cond((null? l)(display "list is empty"))
	((null? (cdr l))1)
	(else( + 1 ( sum (cdr l)) ))
	)
		
)
(define a (list 1 23 4 5 6 7 8))
(leng a)

