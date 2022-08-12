# Bomb Lab 笔记

## Phase_1

```assembly
   0x400ee0 <+0>:	sub    $0x8,%rsp
   0x400ee4 <+4>:	mov    $0x402400,%esi
   0x400ee9 <+9>:	callq  0x401338 <strings_not_equal>
   0x400eee <+14>:	test   %eax,%eax
   0x400ef0 <+16>:	je     0x400ef7 <phase_1+23>
   0x400ef2 <+18>:	callq  0x40143a <explode_bomb>
   0x400ef7 <+23>:	add    $0x8,%rsp
   0x400efb <+27>:	retq
```



## Phase_6

``` assembly
   0x4010f4 <+0>:	push   %r14
   0x4010f6 <+2>:	push   %r13
   0x4010f8 <+4>:	push   %r12
   0x4010fa <+6>:	push   %rbp
   0x4010fb <+7>:	push   %rbx
   0x4010fc <+8>:	sub    $0x50,%rsp
   0x401100 <+12>:	mov    %rsp,%r13		$r13 = rsp
   0x401103 <+15>:	mov    %rsp,%rsi		$rsi = rsp
   0x401106 <+18>:	callq  0x40145c <read_six_numbers>
   0x40110b <+23>:	mov    %rsp,%r14		$r14 = rsp
   0x40110e <+26>:	mov    $0x0,%r12d		$r12d = 0
   
   ----------- ----------- ----------- ----------- part 1
   
   0x401114 <+32>:	mov    %r13,%rbp		$rbp = rsp
   0x401117 <+35>:	mov    0x0(%r13),%eax	 	$eax = nums[0]
   0x40111b <+39>:	sub    $0x1,%eax
   0x40111e <+42>:	cmp    $0x5,%eax				nums[0] <= 6
   0x401121 <+45>:	jbe    0x401128 <phase_6+52>
   0x401123 <+47>:	callq  0x40143a <explode_bomb>
   0x401128 <+52>:	add    $0x1,%r12d				
   0x40112c <+56>:	cmp    $0x6,%r12d
   0x401130 <+60>:	je     0x401153 <phase_6+95> 退出循环
   0x401132 <+62>:	mov    %r12d,%ebx		$ebx = r12d = i
   0x401135 <+65>:	movslq %ebx,%rax		$rax = $rbx
   0x401138 <+68>:	mov    (%rsp,%rax,4),%eax		$eax = nums[i]
   0x40113b <+71>:	cmp    %eax,0x0(%rbp)
   0x40113e <+74>:	jne    0x401145 <phase_6+81>
   0x401140 <+76>:	callq  0x40143a <explode_bomb>
   0x401145 <+81>:	add    $0x1,%ebx
   0x401148 <+84>:	cmp    $0x5,%ebx
   0x40114b <+87>:	jle    0x401135 <phase_6+65>
   0x40114d <+89>:	add    $0x4,%r13
   0x401151 <+93>:	jmp    0x401114 <phase_6+32>
   
   for(int i = 0; i < 6; i++){
   		if(nums[i] > 6){
   				bomb;
   		}
			for(int j = i + 1; j <= 5; j++){
					if(nums[i] == nums[j]){
							bomb;
					}
			}
   }
   
   1. nums[i] <= 6
   2. nums[i] 互不相等
   
	----------- ----------- ----------- ----------- part 2
   
   0x401153 <+95>:	lea    0x18(%rsp),%rsi
   0x401158 <+100>:	mov    %r14,%rax			$rax = $rsp
   0x40115b <+103>:	mov    $0x7,%ecx			$ecx = 0x7
   0x401160 <+108>:	mov    %ecx,%edx			$edx = $ecx
   0x401162 <+110>:	sub    (%rax),%edx		$edx = 7 - nums[i]
   0x401164 <+112>:	mov    %edx,(%rax)		nums[i] = 7 - nums[i]
   0x401166 <+114>:	add    $0x4,%rax			nums[i + 1]
   0x40116a <+118>:	cmp    %rsi,%rax			
   0x40116d <+121>:	jne    0x401160 <phase_6+108>
   
   for(int i = 0; i < 6; i ++){
   		nums[i] = 7 - nums[i];
   }
   
   问题 : 问什么会跳出去?
   回答 : 寄存器$rsi的位置就在nums[5]的后面
   
   ----------- ----------- ----------- ----------- part 3
   
   0x40116f <+123>:	mov    $0x0,%esi						$esi = 0
   0x401174 <+128>:	jmp    0x401197 <phase_6+163>
   0x401176 <+130>:	mov    0x8(%rdx),%rdx		$rdx指向下一个节点
   0x40117a <+134>:	add    $0x1,%eax
   0x40117d <+137>:	cmp    %ecx,%eax
   0x40117f <+139>:	jne    0x401176 <phase_6+130>
   0x401181 <+141>:	jmp    0x401188 <phase_6+148>
   0x401183 <+143>:	mov    $0x6032d0,%edx			
   0x401188 <+148>:	mov    %rdx,0x20(%rsp,%rsi,2)	$rdx存的是指针,是下一个节点的地址, 8B
   0x40118d <+153>:	add    $0x4,%rsi
   0x401191 <+157>:	cmp    $0x18,%rsi
   0x401195 <+161>:	je     0x4011ab <phase_6+183>
   0x401197 <+163>:	mov    (%rsp,%rsi,1),%ecx 	$ecx = 7-nums[i]
   0x40119a <+166>:	cmp    $0x1,%ecx
   0x40119d <+169>:	jle    0x401183 <phase_6+143>
   0x40119f <+171>:	mov    $0x1,%eax						$eax = 1
   0x4011a4 <+176>:	mov    $0x6032d0,%edx				$rdx指向第一个节点
   0x4011a9 <+181>:	jmp    0x401176 <phase_6+130>
   
   
   x/30 0x6032d0 :
0x6032d0 <node1>:	0x14c(332)	0x001	0x006032e0	0x000
0x6032e0 <node2>:	0x0a8(168)	0x002	0x006032f0	0x000
0x6032f0 <node3>:	0x39c(924)	0x003	0x00603300	0x000
0x603300 <node4>:	0x2b3(691)	0x004	0x00603310	0x000
0x603310 <node5>:	0x1dd(477)	0x005	0x00603320	0x000
0x603320 <node6>:	0x1bb(443)	0x006	0x00000000	0x000
   
   node{
   		int nodeVal   //4B  16-8-4 = 4
   		int val;			//4B
   		node* next;		//8B
   }
   sizeof(node) = 0x6032e0 - 0x6032d0 = 16 (deximal)
   
   7 - nums[i] 作为移动的距离, 将移动后的指针复制给新的地址空间, 进行排序
   
   ----------- ----------- ----------- ----------- part 4
   
   0x4011ab <+183>:	mov    0x20(%rsp),%rbx	node[i]
   0x4011b0 <+188>:	lea    0x28(%rsp),%rax	node[i]->next
   0x4011b5 <+193>:	lea    0x50(%rsp),%rsi	node[i+1]->next
   0x4011ba <+198>:	mov    %rbx,%rcx				
   0x4011bd <+201>:	mov    (%rax),%rdx
   0x4011c0 <+204>:	mov    %rdx,0x8(%rcx)		node[i]->next = node[i+1]
   0x4011c4 <+208>:	add    $0x8,%rax				
   0x4011c8 <+212>:	cmp    %rsi,%rax
   0x4011cb <+215>:	je     0x4011d2 <phase_6+222>
   0x4011cd <+217>:	mov    %rdx,%rcx
   0x4011d0 <+220>:	jmp    0x4011bd <phase_6+201>
   
   问题 : 208行 $rax为什么 +8
   回答 : 搞清楚栈帧的结构, 数据是如何排列的
   
   x/30 0x7ffc4bec35f0 :
0x7ffc4bec35f0: 0x00000006	0x00000005	0x00000004	0x00000003
0x7ffc4bec3600: 0x00000002	0x00000001	0x00603910	0x00000000
0x7ffc4bec3610: 0x00603320	0x00000000	0x00603310	0x00000000
0x7ffc4bec3620: 0x00603300	0x00000000	0x006032f0	0x00000000
0x7ffc4bec3630: 0x006032e0	0x00000000	0x006032d0	0x00000000
   
   for(int i = 5; i >=0 ;i--){
   		node[i]->next = node[i -1];
   }
   
   ----------- ----------- ----------- ----------- part 5
   
   0x4011d2 <+222>:	movq   $0x0,0x8(%rdx)
   0x4011da <+230>:	mov    $0x5,%ebp
   0x4011df <+235>:	mov    0x8(%rbx),%rax
   0x4011e3 <+239>:	mov    (%rax),%eax
   0x4011e5 <+241>:	cmp    %eax,(%rbx)		
   0x4011e7 <+243>:	jge    0x4011ee <phase_6+250>
   0x4011e9 <+245>:	callq  0x40143a <explode_bomb>
   0x4011ee <+250>:	mov    0x8(%rbx),%rbx
   0x4011f2 <+254>:	sub    $0x1,%ebp
   0x4011f5 <+257>:	jne    0x4011df <phase_6+235>
   
   降序排序
0x6032d0 <node1>:	0x14c(332)	0x001	0x006032e0	0x000
0x6032e0 <node2>:	0x0a8(168)	0x002	0x006032f0	0x000
0x6032f0 <node3>:	0x39c(924)	0x003	0x00603300	0x000
0x603300 <node4>:	0x2b3(691)	0x004	0x00603310	0x000
0x603310 <node5>:	0x1dd(477)	0x005	0x00603320	0x000
0x603320 <node6>:	0x1bb(443)	0x006	0x00000000	0x000

 	 7 - num[i]  = 指针移动次数, 移动以后降序排列
 	 nums[i] = {4, 3, 2, 1, 6, 5}
   
   ----------- ----------- ----------- ----------- -----------
   
   0x4011f7 <+259>:	add    $0x50,%rsp
   0x4011fb <+263>:	pop    %rbx
   0x4011fc <+264>:	pop    %rbp
   0x4011fd <+265>:	pop    %r12
   0x4011ff <+267>:	pop    %r13
   0x401201 <+269>:	pop    %r14
   0x401203 <+271>:	retq
```





