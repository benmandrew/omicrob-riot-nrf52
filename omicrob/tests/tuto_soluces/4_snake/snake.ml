open Avr
open Arduboy
type direction = North | South | East | West

let _ =  Random.init 42

let snake = Array.make 20 (0,0)
let ptr_head = ref 1
let ptr_tail = ref 0
let size = ref 1

exception Lose
exception Win

let new_position () =
  (Random.int 64, Random.int 32)
 
let apple = ref (new_position ())

let left_of = function
    South -> East
  | North -> West
  | East -> North
  | West -> South

let right_of = function
    South -> West
  | North -> East
  | East -> South
  | West -> North


let button_direction =
  let old_left = ref HIGH in
  let old_right = ref HIGH in
  fun dir -> 
  let new_left = digital_read button_left in
  let new_right = digital_read button_right in 
  let new_dir = 
  match new_left,new_right with
  | LOW,_ when !old_left <> LOW -> left_of dir
  | _ , LOW  when !old_right <> LOW -> right_of dir
  | _ -> dir
  in
  old_left := new_left;
  old_right := new_right;
  new_dir

exception Break
let collides_with_itself () =
  let i = ref !ptr_tail in
  try
  while true do
    if !i = !ptr_head then raise Break;
    if snake.(!i) = snake.(!ptr_head) then
      raise Lose;
    incr i;
    i := !i mod Array.length snake;
  done
  with Break -> ()

let new_head dir =
  let (cx,cy) = (snake.(!ptr_head)) in
  match dir with
  | South -> (cx,(cy+1) mod 32)
  | North -> (cx,(cy - 1 + 32) mod 32)
  | West -> ((cx-1 + 64) mod 64,cy)
  | East -> ((cx+1) mod 64,cy)

let draw_apple () =
  let x,y = !apple in
  Oled.draw x y true

let eats_apple () =
  snake.(!ptr_head) = (!apple)

let rec game_loop dir=
  let (xh,yh) as head = new_head dir in
  let (xt,yt) = (snake.(!ptr_tail)) in
  let new_dir = button_direction dir in
  if (eats_apple ()) then
    begin
      apple := new_position ();
      incr size;
      if !size = Array.length snake then 
        raise Win;
    end
  else 
     begin
      Oled.draw xt yt false;
      ptr_tail := (!ptr_tail + 1) mod (Array.length snake)
    end;
  ptr_head := (!ptr_head + 1) mod (Array.length snake);
  snake.(!ptr_head) <- head;
  draw_apple ();
  Oled.draw xh yh true;
  Oled.display ();
  collides_with_itself ();
  delay(100 - !size);
  game_loop new_dir

let () = 
  init ();
  try
    game_loop South
  with Lose ->
    digital_write r LOW
     | Win ->
     digital_write g LOW
