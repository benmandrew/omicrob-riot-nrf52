open Avr

type portb_bit = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 | PB6 | PB7
type portc_bit = PC0 | PC1 | PC2 | PC3 | PC4 | PC5 | PC6 | PC7
type portd_bit = PD0 | PD1 | PD2 | PD3 | PD4 | PD5 | PD6 | PD7
type ddrb_bit = DB0 | DB1 | DB2 | DB3 | DB4 | DB5 | DB6 | DB7
type ddrc_bit = DC0 | DC1 | DC2 | DC3 | DC4 | DC5 | DC6 | DC7
type ddrd_bit = DD0 | DD1 | DD2 | DD3 | DD4 | DD5 | DD6 | DD7
type pinb_bit = IB0 | IB1 | IB2 | IB3 | IB4 | IB5 | IB6 | IB7
type pinc_bit = IC0 | IC1 | IC2 | IC3 | IC4 | IC5 | IC6 | IC7
type pind_bit = ID0 | ID1 | ID2 | ID3 | ID4 | ID5 | ID6 | ID7
type spcr_bit = SPR0 | SPR1 | CPHA | CPOL | MSTR | DORD | SPE | SPIE
type spsr_bit = SPI2x | SPSR1 | SPSR2 | SPSR3 | SPSR4 | SPSR5 | SPSR6 | SPIF
type spdr_bit = SPDR0 | SPDR1 | SPDR2 | SPDR3 | SPDR4 | SPDR5 | SPDR6 | SPDR7
type 'a register =
  | PORTB : portb_bit register
  | PORTC : portc_bit register
  | PORTD : portd_bit register
  | DDRB : ddrb_bit register
  | DDRC : ddrc_bit register
  | DDRD : ddrd_bit register
  | PINB : pinb_bit register
  | PINC : pinc_bit register
  | PIND : pind_bit register
  | SPCR : spcr_bit register
  | SPSR : spsr_bit register
  | SPDR : spsr_bit register
type ('a,'b,'c,'d) pin =
  | PIN0  : (portd_bit register, ddrd_bit register, pind_bit register, no analog_pin) pin
  | PIN1  : (portd_bit register, ddrd_bit register, pind_bit register, no analog_pin) pin
  | PIN2  : (portd_bit register, ddrd_bit register, pind_bit register, no analog_pin) pin
  | PIN3  : (portd_bit register, ddrd_bit register, pind_bit register, no analog_pin) pin
  | PIN4  : (portd_bit register, ddrd_bit register, pind_bit register, no analog_pin) pin
  | PIN5  : (portd_bit register, ddrd_bit register, pind_bit register, no analog_pin) pin
  | PIN6  : (portd_bit register, ddrd_bit register, pind_bit register, no analog_pin) pin
  | PIN7  : (portd_bit register, ddrd_bit register, pind_bit register, no analog_pin) pin
  | PIN8  : (portb_bit register, ddrb_bit register, pinb_bit register, no analog_pin) pin
  | PIN9  : (portb_bit register, ddrb_bit register, pinb_bit register, no analog_pin) pin
  | PIN10 : (portb_bit register, ddrb_bit register, pinb_bit register, no analog_pin) pin
  | PIN11 : (portb_bit register, ddrb_bit register, pinb_bit register, no analog_pin) pin
  | PIN12 : (portb_bit register, ddrb_bit register, pinb_bit register, no analog_pin) pin
  | PIN13 : (portb_bit register, ddrb_bit register, pinb_bit register, no analog_pin) pin
  | MISO  : (portb_bit register, ddrb_bit register, pinb_bit register, no analog_pin) pin
  | SCK   : (portb_bit register, ddrb_bit register, pinb_bit register, no analog_pin) pin
  | MOSI  : (portb_bit register, ddrb_bit register, pinb_bit register, no analog_pin) pin
  | SS    : (portb_bit register, ddrb_bit register, pinb_bit register, no analog_pin) pin
  | PINA0 : (portc_bit register, ddrc_bit register, pinc_bit register, yes analog_pin) pin
  | PINA1 : (portc_bit register, ddrc_bit register, pinc_bit register, yes analog_pin) pin
  | PINA2 : (portc_bit register, ddrc_bit register, pinc_bit register, yes analog_pin) pin
  | PINA3 : (portc_bit register, ddrc_bit register, pinc_bit register, yes analog_pin) pin
  | PINA4 : (portc_bit register, ddrc_bit register, pinc_bit register, yes analog_pin) pin
  | PINA5 : (portc_bit register, ddrc_bit register, pinc_bit register, yes analog_pin) pin

let port_of_pin : type a b c d. (a register, b register, c register,d analog_pin) pin -> a register =
  function
  | PIN0 -> PORTD
  | PIN1 -> PORTD
  | PIN2 -> PORTD
  | PIN3 -> PORTD
  | PIN4 -> PORTD
  | PIN5 -> PORTD
  | PIN6 -> PORTD
  | PIN7 -> PORTD
  | PIN8 -> PORTB
  | PIN9 -> PORTB
  | PIN10 -> PORTB
  | PIN11 -> PORTB
  | PIN12 -> PORTB
  | PIN13 -> PORTB
  | MISO -> PORTB
  | SCK -> PORTB
  | MOSI -> PORTB
  | SS -> PORTB
  | PINA0 -> PORTC
  | PINA1 -> PORTC
  | PINA2 -> PORTC
  | PINA3 -> PORTC
  | PINA4 -> PORTC
  | PINA5 -> PORTC

let ddr_of_pin : type a b c d. (a register , b register, c register, d analog_pin) pin -> b register=
  function
  | PIN0 -> DDRD
  | PIN1 -> DDRD
  | PIN2 -> DDRD
  | PIN3 -> DDRD
  | PIN4 -> DDRD
  | PIN5 -> DDRD
  | PIN6 -> DDRD
  | PIN7 -> DDRD
  | PIN8 -> DDRB
  | PIN9 -> DDRB
  | PIN10 -> DDRB
  | PIN11 -> DDRB
  | PIN12 -> DDRB
  | PIN13 -> DDRB
  | MISO -> DDRB
  | SCK -> DDRB
  | MOSI -> DDRB
  | SS -> DDRB
  | PINA0 -> DDRC
  | PINA1 -> DDRC
  | PINA2 -> DDRC
  | PINA3 -> DDRC
  | PINA4 -> DDRC
  | PINA5 -> DDRC

let input_of_pin : type a b c d. (a register , b register, c register, d analog_pin) pin -> c register=
  function
  | PIN0 -> PIND
  | PIN1 -> PIND
  | PIN2 -> PIND
  | PIN3 -> PIND
  | PIN4 -> PIND
  | PIN5 -> PIND
  | PIN6 -> PIND
  | PIN7 -> PIND
  | PIN8 -> PINB
  | PIN9 -> PINB
  | PIN10 -> PINB
  | PIN11 -> PINB
  | PIN12 -> PINB
  | PIN13 -> PINB
  | MISO -> PINB
  | SCK -> PINB
  | MOSI -> PINB
  | SS -> PINB
  | PINA0 -> PINC
  | PINA1 -> PINC
  | PINA2 -> PINC
  | PINA3 -> PINC
  | PINA4 -> PINC
  | PINA5 -> PINC

let port_bit_of_pin : type a b c d. (a register, b register, c register, d analog_pin) pin -> a =
  function
  | PIN0 -> PD0
  | PIN1 -> PD1
  | PIN2 -> PD2
  | PIN3 -> PD3
  | PIN4 -> PD4
  | PIN5 -> PD5
  | PIN6 -> PD6
  | PIN7 -> PD7
  | PIN8 -> PB0
  | PIN9 -> PB1
  | PIN10 -> PB2
  | PIN11 -> PB3
  | PIN12 -> PB4
  | PIN13 -> PB5
  | MISO -> PB4
  | SCK -> PB5
  | MOSI -> PB3
  | SS -> PB0
  | PINA0 -> PC0
  | PINA1 -> PC1
  | PINA2 -> PC2
  | PINA3 -> PC3
  | PINA4 -> PC4
  | PINA5 -> PC5

let ddr_bit_of_pin : type a b c d. (a register, b register, c register, d analog_pin) pin -> b =
  function
  | PIN0 -> DD0
  | PIN1 -> DD1
  | PIN2 -> DD2
  | PIN3 -> DD3
  | PIN4 -> DD4
  | PIN5 -> DD5
  | PIN6 -> DD6
  | PIN7 -> DD7
  | PIN8 -> DB0
  | PIN9 -> DB1
  | PIN10 -> DB2
  | PIN11 -> DB3
  | PIN12 -> DB4
  | PIN13 -> DB5
  | MISO -> DB4
  | SCK -> DB5
  | MOSI -> DB3
  | SS -> DB0
  | PINA0 -> DC0
  | PINA1 -> DC1
  | PINA2 -> DC2
  | PINA3 -> DC3
  | PINA4 -> DC4
  | PINA5 -> DC5

let input_bit_of_pin : type a b c d . (a register, b register, c register, d analog_pin) pin -> c =
  function
  | PIN0 -> ID0
  | PIN1 -> ID1
  | PIN2 -> ID2
  | PIN3 -> ID3
  | PIN4 -> ID4
  | PIN5 -> ID5
  | PIN6 -> ID6
  | PIN7 -> ID7
  | PIN8 -> IB0
  | PIN9 -> IB1
  | PIN10 -> IB2
  | PIN11 -> IB3
  | PIN12 -> IB4
  | PIN13 -> IB5
  | MISO -> IB4
  | SCK -> IB5
  | MOSI -> IB3
  | SS -> IB0
  | PINA0 -> IC0
  | PINA1 -> IC1
  | PINA2 -> IC2
  | PINA3 -> IC3
  | PINA4 -> IC4
  | PINA5 -> IC5

external write_register : 'a register -> int -> unit = "caml_write_register" [@@noalloc]
external read_register : 'a register -> int = "caml_read_register" [@@noalloc]
external set_bit : 'a register -> 'a -> unit = "caml_set_bit" [@@noalloc]
external clear_bit : 'a register -> 'a -> unit = "caml_clear_bit" [@@noalloc]
external read_bit : 'a register -> 'a -> bool = "caml_read_bit" [@@noalloc]

let pin_mode p m =
  let port = port_of_pin p in
  let bit = port_bit_of_pin p in
  let ddr_bit = ddr_bit_of_pin p in
  let ddr = ddr_of_pin p in
  match m with
  | OUTPUT ->
    set_bit ddr ddr_bit
  | INPUT ->
    clear_bit ddr ddr_bit;
    clear_bit port bit
  | INPUT_PULLUP ->
    clear_bit ddr ddr_bit;
    set_bit port bit

let digital_write p b =
  let port = port_of_pin p in
  let bit = port_bit_of_pin p in
  match b with
  | HIGH -> set_bit port bit
  | LOW -> clear_bit port bit

let digital_read p =
  let input = input_of_pin p in
  let bit = input_bit_of_pin p in
  match read_bit input bit with
  | true -> HIGH
  | false -> LOW
