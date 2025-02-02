(setq sum 0)

(loop for i from 3 to 999
    do (if (or (zerop (mod i 3)) (zerop (mod i 5)))
        (incf sum i)))

(write-line (write-to-string sum))