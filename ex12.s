(define-fun ( F (int i) (int j)) int
(if (not (= i 6))
(if (not (= i j)) (+ 1 (* 2 3) ) (- (* 2 j) (+ i i)))
(if (< i 8) (mod i 3) i)))