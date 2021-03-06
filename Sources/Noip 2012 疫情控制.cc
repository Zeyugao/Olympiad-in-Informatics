//Summary:
//	根据显然法得，一个军队越往上走，能守卫的节点一定不会减少，所以，往上走才是正解之一法则
//	往上走的时候，有些军队可以到达根节点，有些无法到达根节点，对于无法到达根节点得军队，显然时越往上越优，同时，还要根据节点得信息进行二次dfs，判断是否是{该节点的父节点仅有一个子节点（就是该节点），那么进行标记的时候，可以进行往上推进已标记的节点，如果到了根结点的子节点之一那是再好不过的了}
//	对于能够到达根结点的军队，如果{它下不来了，就是在离他最近的未标记的节点都到不了}，那么他还不如不要上到根节点了，好好看守好他自己的节点就可以了
//	枚举到达根结点的军队，如果这个军队来自的子节点没有被标记，那么就让这个军队到来自的子节点即可，标记该节点，去除该军队
//	根据前面标记的情况，对{到达根节点的军队的剩余时间，各个未被标记的子节点到父节点的距离}分别排序
//		如果未被标记的节点数量还大于能够移动的节点，直接raise Exceptio
//	用贪心法则，把剩余时间短的与距离长短的直接“连线”，进行贪心选择
//	最后统计有没有没有被打标记的节点
