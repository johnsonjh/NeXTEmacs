(defun undo-start ()
  "Move undo-pointer to front of undo records.
The next call to undo-more will undo the most recently made change.
  (if (eq buffer-undo-list t)
      (error "No undo information in this buffer"))
  (setq pending-undo-list buffer-undo-list))

(defun undo-more (count)
  "Undo back N undo-boundaries beyond what was already undone recently.
Call undo-start to get ready to undo recent changes,
then call undo-more one or more times to undo them.
  (or pending-undo-list
      (error "No further undo information"))
  (setq pending-undo-list (primitive-undo count pending-undo-list)))