(define-fun t1 (+ 1 2))
(define-fun t2 (+ 1 (t1)))
(define-fun t3 (+ 1 (t2)))
(print (+ 1 (t3)))
