
let usage () =
  Printf.eprintf "Usage: %s [COLxLIN] [dc=RXX] [cs=RXX] [rst=RXX] \n%!"
    Sys.argv.(0);
  exit 1


let check_prefix prefix str =
  let plen = String.length prefix in
  if plen > String.length str then false else
    let rec f i =
      if i = plen then true
      else if Char.lowercase_ascii prefix.[i] <> Char.lowercase_ascii str.[i] then false
      else f (succ i)
    in
    f 0


let parse_size str =
  try
    let len = String.length str in
    let x_ind = String.index str 'x' in
    let col = String.sub str 0 x_ind in
    let lin = String.sub str (succ x_ind) (len - x_ind - 1) in
    (int_of_string col, int_of_string lin)
  with Not_found | Invalid_argument _ | Failure _ ->
    failwith "invalid size"


let dc = ref None
let cs = ref None
let rst = ref None
let size = ref None

let set n x v =
  match !x with
    | None -> x := Some v
    | Some _ -> failwith (Printf.sprintf "%s already defined" n)

let get n x =
  match !x with
    | None -> failwith (Printf.sprintf "%s undefined" n)
    | Some v -> v


let _ =
  let nb_arg = Array.length Sys.argv in
  for i = 1 to nb_arg - 1 do
    let arg = Sys.argv.(i) in
    try
      let len = String.length arg in
      if check_prefix "dc=PIN" arg then
        set "dc" dc (Simul.pin_of_number (String.sub arg 3 (len-3)))
      else if check_prefix "cs=PIN" arg then
        set "cs" cs (Simul.pin_of_number (String.sub arg 3 (len-3)))
      else if check_prefix "rst=PIN" arg then
        set "rst" rst (Simul.pin_of_number (String.sub arg 4 (len-4)))
      else
        set "size" size (parse_size arg);
    with Failure _ ->
      Printf.eprintf "Error: don't know what to do with: '%s'\n%!" arg;
      usage ();
  done;
  let cs = get "cs" cs in
  let dc = get "dc" dc in
  let rst = get "rst" rst in
  let size = get "size" size in
  let column_nb = fst size in
  let line_nb = snd size in
  (try
    at_exit (fun () -> print_endline "STOP");
    let display = Display.create_display 0 0 cs dc rst column_nb line_nb in
    Display.init_graphics display;
    Proto.register display;
    Simul.start ();
    Simul.join ()
  with Failure msg ->
    Printf.eprintf "Error: %s\n%!" msg;
    usage () )
