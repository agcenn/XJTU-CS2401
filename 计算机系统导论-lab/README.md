# 计算机系统导论 Lab

XJTU **CS2401 计算机系统导论**课程实验合集（CS:APP 系列实验），包含 Attacklab、Datalab、Linker Lab、bomblab 四个实验，以及课程参考资料。

## 目录结构

```
计算机系统导论-lab/
├── Attacklab/                  缓冲区溢出攻击实验
│   ├── ctarget                 目标程序（代码注入）
│   ├── rtarget                 目标程序（ROP）
│   ├── phase1.txt ~ phase5.txt 各关卡攻击 payload
│   └── cookie.txt              本次实验 cookie
├── Datalab/
│   └── bits.c                  位运算 / 补码求解（实验提交文件）
├── Linker Lab/                 链接器实现（C++）
│   └── src/                    main / relocation / resolve / util
├── bomblab/
│   ├── bomb                    拆弹目标程序
│   └── solution.txt            各关答案与过关字符串
├── x86-64-reference.pdf        x86-64 参考手册
├── x86-64-reference-汉化版.pdf
├── 计算机系统导论期末-单丹枫.pdf   期末复习资料
└── 计算机系统导论期末-李昊.pdf
```

## 各实验说明

### Attacklab
围绕 x86-64 函数调用栈的缓冲区溢出实验：
- `ctarget`：代码注入（code injection）实验，通过覆盖返回地址跳到注入的指令
- `rtarget`：ROP（Return-Oriented Programming）实验，用现有 gadget 拼出攻击链
- `phase1.txt` ~ `phase5.txt`：对应关卡的十六进制 payload
- `cookie.txt`：本实验专属 cookie（`0x66e37c7e`）

### Datalab
- `bits.c`：在限定运算符（`!`、`~`、`&`、`^`、`|`、`+`、`<<`、`>>`）和操作数上限内，实现位操作、补码运算、浮点位级操作等函数
- 作者：ALEX GUAN YAN CEN CEN（2249990046）

### Linker Lab
- 用 C++ 实现一个简易链接器的核心步骤：
  - `resolve.cc/h`：符号解析
  - `relocation.cc/h`：重定位
  - `util.cc/h`、`main.cc`：工具函数与入口

### bomblab
- `bomb`：需要逐关"拆解"的目标程序，每关考察不同的汇编阅读能力
- `solution.txt`：各关输入答案（含 `Crikey! I have lost my mojo!` 等过关字符串）

## 运行说明

- 实验均在 **Linux** 环境完成，`ctarget` / `rtarget` / `bomb` 为 **Linux ELF 可执行文件**，Windows 下无法直接运行（可放在 WSL / 虚拟机 / 服务器上跑）
- 编译 Lab 时注意关闭或开启相应的栈保护（如 Attacklab 需要 `-z execstack` 与关闭 ASLR）
- 本仓库内容仅供学习与复习参考

---

课程：西安交通大学 CS2401 计算机系统导论
