### 1. 实验要求

- PL0扩展：支持*print*语句
- PL0生成可执行代码，代码格式见*ins.md*
- 最终需要编译生成一个可执行文件*PL0*，*PL0*有2个参数，分别为PL0语言代码的输入和ASM代码的输出
  （如运行 `./PL0 input.pl output.asm`可将*input.pl*文件编译成*output.asm*）



### 2. 测试步骤

- 从gitlab获取VM：`git clone http://210.45.114.146:880/staff/pl0sim.git`

- 将1中编译生成的可执行文件*PL0*放入*pl0sim*文件夹中，替换掉原来的fake *PL0*
- 在*pl0sim*文件夹中执行`./runcase --debug` 查看调试结果
- 在*pl0sim*文件夹中执行`./runcase`查看最终结果



### 3. 成绩说明

- test case 分为4类，分别是beginner，median，challenged，advanced
- beginner，median，challenged各5个例子，advanced共10个例子
- beginner，median，challenged中为PL0的基本语法
- advanced中为lab3扩展实验中的扩展语法。10个测试样例中，数组2个，逻辑运算符2个，返回值2个，elif、else、do while 1个，传参2个，负数1个
- 分数：beginner 1个2分，median 1个4分， challenged 1个6分，advanced 1个8分，一共140分，成绩最高100分



### 4. 注意事项

- 不要hardcode test case !
- 不要hardcode 函数调用！
- 不要做编译预处理的优化 !
- 不要修改任何测试文件 !
