let _ =
  let r = PIN6 in
  let p = PIN13 in
  pin_mode r OUTPUT;
  pin_mode p OUTPUT;
  let i = ref 0 in
  while !i < 5 do
  digital_write r HIGH;
  digital_write p HIGH;
  delay 500; 
  digital_write r LOW;
  digital_write p LOW;
  delay 500;
  i := !i + 1;
 done
