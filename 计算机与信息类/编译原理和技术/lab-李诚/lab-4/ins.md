#### 类型：

- address : 整数

- flag, bool：0或者1

- value：整数


#### 指令集：

- 访存指令：
  - PUT value  /* 将value放入栈顶 */
  - LD /*从栈顶取一个值（address），将memory中address位置的值放入栈顶 */
  - ST  /*从栈顶取一个值（address），再取一个值（v），将值v存入memory中address位置 */
- 跳转指令
  - JMP address /*跳转到代码段的address位置 */
  - JPC address /*从栈顶取布尔值，根据这个值来决定是否跳转到代码段的address位置 */
  - INT flag /* flag = 0 打印栈顶值（不取出）； flag = 1程序终止 */
- 算数指令
  - ADD /*从栈顶取一个值（l），再取一个值（r），执行l+r运算，将算得的值放入栈顶 */
  - SUB /*从栈顶取一个值（l），再取一个值（r），执行l-r运算，将算得的值放入栈顶 */
  - MUL /*从栈顶取一个值（l），再取一个值（r），执行l\*r运算，将算得的值放入栈顶 */
  - DIV /*从栈顶取一个值（l），再取一个值（r），执行l/r运算，将算得的值放入栈顶 */
  - EQ /*从栈顶取一个值（l），再取一个值（r），判断l是否等于r，将算得的布尔值放入栈顶 */
  - LE /*从栈顶取一个值（l），再取一个值（r），判断l是否小于等于r，将算得的布尔值放入栈顶 */
  - LT /*从栈顶取一个值（l），再取一个值（r），判断l是否小于r，将算得的布尔值放入栈顶 */
  - GE /*从栈顶取一个值（l），再取一个值（r），判断l是否大于等于r，将算得的布尔值放入栈顶 */
  - GT /*从栈顶取一个值（l），再取一个值（r），判断l是否大于r，将算得的布尔值放入栈顶 */
  - AND /*从栈顶取一个布尔值（l），再取一个布尔值（r），执行l && r运算，将算得的布尔值放入栈顶 */
  - OR  /*从栈顶取一个布尔值（l），再取一个布尔值（r），执行l || r运算，将算得的布尔值放入栈顶 */
  - NOT  /*从栈顶取一个布尔值（l），做非运算，将算得的布尔值放入栈顶 */



#### VM参数：

- MAX_STACK_SIZE = 256
- MAX_MEMORY_SIZE = 1024
- MAX_CODEHEAP_SIZE = 1024



#### VM错误类型：

- "Missing input file name"  /* 缺少ASM代码文件名称参数 */
- "Input file XXX does not exist"  /* ASM代码文件不存在 */
- "Input file XXX is not accessible to read" /* ASM代码文件无访问权限 */
- "The length of code is out of range" /* 代码长度过长 */
- "Illegal instruction XXX at line XXX"  /* 错误的指令格式 */
- "Illegal code heap access from instruction XXX at line XXX" /* 在代码堆中寻址时越界或对应位置不存在指令 */
- "Illegal stack access from instruction XXX at line XXX" /* pop时栈空或类型错误；push时栈满；除零错误*/
- "Illegal stack access from instruction XXX at line XXX" /* LD或ST时地址越界；LD时对应位置不存在值 */



#### Example：

- instruction example: 包含指令示例代码
- code block example: 包含代码块示例代码

