let _ =
  Serial.init ();
  let i = ref 5 in
  while(!i > 0) do
    Serial.write ((string_of_int (millis ()))^"\n");
    Screen.print_string (Serial.read ()); (* Weirdly this takes ~1s *)
    delay 200;
    i := !i - 1;
  done
