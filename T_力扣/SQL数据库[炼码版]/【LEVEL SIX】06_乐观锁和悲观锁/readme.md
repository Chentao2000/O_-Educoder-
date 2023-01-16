`
悲观锁与乐观锁是两种常见的资源并发锁设计思路，也是并发编程中一个非常基础的概念。
悲观锁 (Pessimistic Lock), 顾名思义，就是很悲观，每次去拿数据的时候都认为别人会修改
所以每次在拿数据的时候都会上锁，这样别人想拿这个数据就会block直到它拿到锁。
`

![1655517240167](https://user-images.githubusercontent.com/68007558/174418026-aee6dbf2-1547-4068-be5f-8cbc2cba3e5e.png)


![1655517252848](https://user-images.githubusercontent.com/68007558/174418033-04601906-a4b5-4e91-ae34-64dcbd514d29.png)



![1655517269763](https://user-images.githubusercontent.com/68007558/174418039-5e73dbea-11d6-4684-b153-9d6426ad4436.png)



![1655517826136](https://user-images.githubusercontent.com/68007558/174418300-891c76b5-8c0d-42a9-a91b-5fe0cbf7def6.png)




