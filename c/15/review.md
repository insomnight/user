# 15.8　复习题

## 1．把下面的十进制转换为二进制

- a．3

```c
11
```

- b．13

```c
1101
```

- c．59

```c
111011
```

- d．119

```c
1110111
```

## 2．将下面的二进制值转换为十进制、八进制和十六进制的形式

- a．00010101

```c
21
025
0x15
```

- b．01010101

```c
85
0125
0x55
```

- c．01001100

```c
76
0114
0x4C
```

- d．10011101

```c
157
0235
0x9D
```

## 3．对下面的表达式求值，假设每个值都为8位

- a．～3

```c
00000011
11111100
252
```

- b．3 & 6

```c
00000011
00000110
00000010
2
```

- c．3 | 6

```c
00000011
00000110
00000111
7
```

- d．1 | 6

```c
00000001
00000110
00000111
7
```

- e．3 ^ 6

```c
00000011
00000110
00000101
5
```

- f．7 >> 1

```c
00000111
00000011
3
```

- g．7 << 2

```c
00000111
00011100
28
```

## 4．对下面的表达式求值，假设每个值都为8位

- a．～0

```c
00000000
11111111
255
```

- b．!0

```c
00000000
00000001
1
```

- c．2 & 4

```c
00000010
00000100
00000000
0
```

- d．2 && 4

```c
00000010
00000100
00000001
1
```

- e．2 | 4

```c
00000010
00000100
00000110
6
```

- f．2 || 4

```c
00000010
00000100
00000001
1
```

- g．5 << 3

```c
00000101
00101000
40
```

## 5．因为ASCII码只使用最后7位，所以有时需要用掩码关闭其他位，其相应的二进制掩码是什么？分别用十进制、八进制和十六进制来表示这个掩码

```c
01111111
127
0177
0x7F
```

## 6．程序清单15.2中，可以把下面的代码

```c
while (bits-- > 0)
{
    mask |= bitval;
    bitval <<= 1;
}
```

替换成：

```c
while (bits-- > 0)
{
    mask += bitval;
    bitval *= 2;
}
```

程序照常工作。这是否意味着*=2等同于<<=1？+=是否等同于|=？

bitval * 2和bitval << 1都把bitval的当前值增加一倍，它们是等效的。但是mask += bitval和mask |= bitval只有在bitval和mask没有同时打开的位时效果才相同。例如，2 | 4得6，但是3 | 6也得6。

## 7．

- a．Tinkerbell计算机有一个硬件字节可读入程序。该字节包含以下信息

| 位            | 含义                  |
| :-----------: |    :-----------:     |
| 0 ~ 1         | 1.4MB软盘驱动器的数量  |
| 2             | 未使用                |
| 3 ~ 4         | CD-ROM驱动器数量      |
| 5             | 未使用                |
| 6 ~ 7         | 硬盘驱动器数量         |

Tinkerbell和IBM PC一样，从右往左填充结构位字段。创建一个适合存放这些信息的位字段模板。

```c
struct tb_drives {
　　 unsigned int diskdrives 　: 2;
　　 unsigned int 　           : 1;
　　 unsigned int cdromdrives  : 2;
　　 unsigned int 　           : 1;
　　 unsigned int harddrives 　: 2;
};
```

- b．Klinkerbell与Tinkerbell类似，但是它从左往右填充结构位字段。请为Klinkerbell创建一个相应的位字段模板

```c
struct kb_drives {
　　 unsigned int harddrives 　: 2;
　　 unsigned int 　           : 1;
　　 unsigned int cdromdrives  : 2;
　　 unsigned int 　           : 1;
　　 unsigned int diskdrives　 : 2;
};
```