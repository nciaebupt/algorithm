/*
copyright@nciaebupt 转载请注明出处
链表和数字的区别在哪里？数组是线性结构，可以直接索引，即要去第i 个元素，a[i]即可。
链表也是线性结构，要取第i 个元素，只需用指针往后遍历i 次就可。貌似链表比数组还要
麻烦些，而且效率低些。
想到这些相同处中的一些细微的不同处，于是他们的真正不同处渐渐显现了：链表的效率为
何比数组低些？先从两者的初始化开始。数组无需初始化，因为数组的元素在内存的栈区，
系统自动申请空间。而链表的结点元素在内存的堆区，每个元素须手动申请空间，如malloc。
也就是说数组是静态分配内存，而链表是动态分配内存。链表如此麻烦为何还要用链表呢？
数组不能完全代替链表吗？回到这个问题只需想想我们当初是怎么完成学生信息管理系统
的。为何那时候要用链表？因为学生管理系统中的插入，删除等操作都很灵活，而数组则大
小固定，也无法灵活高效的插入，删除。因为堆操作灵活性更强。数组每次插入一个元素就
需要移动已有元素，而链表元素在堆上，无需这么麻烦。
说了这么多，数组和链表的区别整理如下：
数组静态分配内存，链表动态分配内存；


数组在内存中连续，链表不连续；
数组元素在栈区，链表元素在堆区；
数组利用下标定位，时间复杂度为O(1)，链表定位元素时间复杂度O(n)；
数组插入或删除元素的时间复杂度O(n)，链表的时间复杂度O(1)。
*/
