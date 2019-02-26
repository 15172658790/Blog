# C-parser
>A token\_scanner and declaration parser for simplified c using LL(1)
# Rules
* size of int or pointer is 1byte
# Grammar
```scala
translation_unit 
  : declaration 
  | translation_unit declaration 
      ; 
 
declaration 
  : declaration_specifiers init_declarator_list ';' 
      ; 
 
declaration_specifiers 
  : type_specifier 
  ; 
 
init_declarator_list 
  : init_declarator 
  | init_declarator_list ',' init_declarator 
  ; 
 
init_declarator 
  : declarator 
  ; 
 
type_specifier 
  : VOID 
  | INT 
  ; 
 
declarator 
  : pointer direct_declarator 
  | direct_declarator 
  ; 
 
direct_declarator 
  : IDENTIFIER 
  | '(' declarator ')' 
  | direct_declarator '[' CONSTANT_INT ']' 
  | direct_declarator '(' parameter_type_list ')' 
  | direct_declarator '(' ')' 
  ; 
 pointer 
  : '*' 
  | '*' pointer 
  ; 
 
parameter_type_list 
  : parameter_list 
      ; 
 
parameter_list 
  : parameter_declaration 
  | parameter_list ',' parameter_declaration 
  ; 
 
parameter_declaration 
  : declaration_specifiers declarator 
  ; 
```
# Examples
```c
>> int *p,q,j[2];
p::pointer(int)
q::int
j::array(2,int)

>> int *p[2][3];
p::array(2,array(3,pointer(int)))

>> int (*p[4])[2];
p::array(4,pointer(array(2,int)))

>> int (*f(int i,void *j))[2];
f::function( i::int X j::pointer(void) => pointer(array(2,int)))

>> int f(void i, void j, int p[2]);
f::function( i::void X j::void X p::array(2,int) => int)

>> int *f(int i)[2];
[Error]: Array of Functions is not allowed

>> int f[2](int k);
[Error]: Array of Function can not be returned from functions

>> void (*(*paa)[10])(int a);
paa::pointer(array(10,pointer(function( a::int => void))))

>> int (*(*(*pg())(int x))[20])(int *y);
pg::function( void => pointer(function( x::int => pointer(array(20,pointer(function( y::pointer(int) => int)))))))

>> int (*p(int * s,int (*t)(int *m, int n, int (*l())[20]),int k[10]))[10][20];
p::function( s::pointer(int) X t::pointer(function( m::pointer(int) X n::int X l::function( void => pointer(array(20,int))) => int)) X k::array(10,int) => pointer(array(10,array(20,int))))

```
