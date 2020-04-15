(** No need to open something specific ! *)

let _ =
  let r = PIN12 in
  pin_mode r OUTPUT;
  let i = ref 0 in
  while !i < 5 do
    digital_write r HIGH;
    delay 500;
    digital_write r LOW;
    delay 500;
    i := !i + 1;
  done
