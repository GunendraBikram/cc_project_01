(define-fun (t a b)
(if a (if (= (get-int) 8) 50 44) b))
(print (< 1 (t true 1)))