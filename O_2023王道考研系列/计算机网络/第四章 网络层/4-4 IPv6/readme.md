## 学习笔记:
```
解决ip地址耗尽的三种措施:
1.采用无类别编码 CIDR 使IP地址的分配更加合理
2. 采用网络地址转换NAT 节省全球IP地址
3. 采用更大地址空间新版本 ipv6 （根本上）
```
```
ipv6 16B 
- 扩展地址层结构
- 灵活首部格式
- 改进的选项
- 允许协议扩充
- 支持即插即用
- 支持资源预分配
- ipv6 不允许分片
```
```
- 单播
- 多播
- 任播 : ipv6新增的类型 目的是一组计算机 ，但实际交付只在距离最近一所计算机

ipv4采用 点分 十进制 ，ipv6用冒号分隔 ，每4位用16进制表示
```
```
ipv6 分为3级
第一级： 全球都知道公共拓扑
第二级 : (场点)指定某个场点
第三级 ：（端口）指定某个端口
```
```
ipv6向ipv4采用的兼容策略:
- 双协议栈技术 ： 一台设备同时按照  ipv4 和 ipv6 
- 隧道技术 ，将整个ipv6封装到ipv4数据的 数据部分，使得ipv6的数据报在ipv4传输
```
```
ipv6的缩写
- 四个0 可以用一个0来代替
- :: 只能出现一次，表示这中间有 四个0
```

## 错题记录:



## 打卡专区：
![afb3395e07226a3c932553834075694](https://user-images.githubusercontent.com/68007558/180724818-17602837-0779-4b96-9bd2-ce121c2d0ac6.jpg)


## 答案汇总: 
1-5 DDCDA
