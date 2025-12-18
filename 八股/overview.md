# **计算机系统全貌 (Computer Systems)**

## **1\. 计算机体系结构 (Architecture)**

* **核心定义**: 软硬件的契约 (Interface)  
* **核心视角**: 程序员（编译器/OS开发者）可见的属性  
* **关键知识点**  
  * 指令集架构 (ISA)  
    * RISC-V, x86, ARM  
  * 寄存器定义  
  * 内存编址模式  
  * 特权级模式 (Privilege Modes)  
    * Machine / Supervisor / User Mode

## **2\. 计算机组成原理 (Organization)**

* **核心定义**: 架构的物理实现 (Implementation)  
* **核心视角**: 硬件工程师视角，如何把“饼”做出来  
* **关键知识点**  
  * 数据通路 (Datapath)  
  * 控制单元 (Control Unit)  
  * 性能提升技术  
    * 流水线 (Pipelining)  
    * 分支预测 (Branch Prediction)  
    * 乱序执行 (Out-of-Order Execution)  
  * 存储层次  
    * Cache Coherence (缓存一致性)

## **3\. 操作系统 (Operating Systems)**

* **核心定义**: 资源大管家 & 硬件虚拟化  
* **核心视角**: 抽象层，隔离复杂硬件与应用  
* **三大虚拟化 (Illusions)**  
  * CPU 虚拟化 \-\> 进程/线程 (Process/Thread)  
  * 内存虚拟化 \-\> 虚拟地址空间 (Virtual Memory)  
  * 存储虚拟化 \-\> 文件系统 (File System)  
* **关键机制**  
  * 调度 (Scheduling)  
  * 同步与死锁 (Concurrency & Deadlock)  
  * 中断处理 (Interrupt Handling)

## **4\. 计算机网络 (Computer Networks)**

* **核心定义**: 计算机间的通信机制  
* **核心视角**: 异构系统的互联互通  
* **关键知识点**  
  * 分层模型 (TCP/IP Stack)  
    * 应用层 (HTTP/DNS)  
    * 传输层 (TCP/UDP, 可靠性, 拥塞控制)  
    * 网络层 (IP, 路由协议 OSPF/BGP)  
    * 链路层/物理层  
  * Socket 编程接口

## **5\. 数据库系统 (DBMS)**

* **核心定义**: 高效的数据管理引擎  
* **核心视角**: 海量数据的持久化与检索  
* **关键知识点**  
  * 事务管理 (ACID)  
  * 索引结构 (B+ Tree, Hash)  
  * 查询优化 (Query Optimization)  
  * 存储引擎设计  
  * 并发控制 (MVCC, 锁)

## **6\. 关键交叉领域 (The Intersections)**

### **Arch/Org \+ OS (软硬结合部)**

* **中断与异常 (Interrupts & Traps)**  
  * 硬件检测 \-\> OS 处理程序 (Handler)  
* **虚拟内存 (Virtual Memory)**  
  * 硬件 MMU/TLB \<-\> OS 页表维护  
* **同步原语 (Synchronization)**  
  * 硬件原子指令 (AMO/CAS) \<-\> OS Mutex/Sem 实现

### **OS \+ Network (网络子系统)**

* **协议栈实现**  
  * Kernel Networking Subsystem  
* **中断处理**  
  * 网卡硬件中断 \-\> OS 上下文切换  
* **零拷贝 (Zero-Copy)**  
  * DMA \-\> 网卡 (绕过 CPU 拷贝)

### **OS \+ DBMS (相爱相杀)**

* **存储管理**  
  * 裸设备 (Raw Device) vs 文件系统  
  * 数据库 Buffer Pool vs OS Page Cache (双重缓存问题)  
* **调度策略**  
  * 用户态轻量级线程 (Coroutines) vs OS 内核线程

### **Arch \+ DBMS/Net (高性能计算)**

* **SIMD 指令**  
  * 加速数据库扫描 / 网络包处理  
* **NUMA 架构**  
  * 非一致性内存访问优化