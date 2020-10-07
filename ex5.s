(define-fun t1 true)
(define-fun t2 (and (t1) (= (get-int) (get-int))))
(print (t2))
