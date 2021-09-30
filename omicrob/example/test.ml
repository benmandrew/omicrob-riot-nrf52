
(* option utilities *)
(* let optmin x y =
  match x,y with
  | None,a | a,None -> a
  | Some x, Some y-> Some (min x y)

let optsucc = function
  | Some x -> Some (x+1)
  | None -> None

let rec fold_left f acc l =
  match l with
  | [] -> acc
  | x::s -> fold_left f (f acc x) s

(* Change-making problem*)
let change_make money_system amount =
  let rec loop n =
    let onepiece acc piece =
      match n - piece with
      | 0 -> (*problem solved with one coin*) 
             Some 1
      | x -> if x < 0 then 
               (*we don't reach 0, we discard this solution*)
               None
             else
               (*we search the smallest path different to None with the remaining pieces*) 
               optmin (optsucc (loop x)) acc
    in
    (*we call onepiece forall the pieces*)
    fold_left onepiece None money_system
  in loop amount

let main =
  match change_make [10;7;5] 99 with
  | None -> 0;
  | Some v -> v;
  ;; *)


(* let () =
  Printf.printf "Hello from OMicroB!\n"
  ;; *)


(* let () =
  print_string "Hello from OMicroB!\n";
  flush stdout
  ;; *)


(* external print_string : string -> unit = "print_string"

let main =
  print_string "Hello from OMicroB!\n"
  ;; *)


(* let main = List.rev [1; 2; 3; 4; 5] ;; *)


let main = 10 + 5;;
