(define-fun (f1 v1 v2) (and v1 v2))
(define-fun (f2 v1 v2) (+ v1 v2))
(print (f1 (<= (f2 1 2) (f2 2 1)) (>= (f2 1 2) (f2 2 1))
